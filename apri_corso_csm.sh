#!/bin/bash
# Apre in locale SOLO il sito dei lab di Computational Statistical Mechanics
# (static/csm), senza Hugo e senza dipendenze: basta python3, che sul Mac c'e'
# gia'. E' la copia pubblicata da publish.sh (in atomsim/SLIDES_2026-27),
# identica a quella online (lab futuri in grigio e zip compresi), e con MathJax
# dentro le formule si vedono anche senza rete.
# Gemello di apri_corso.sh (Programmazione Scientifica++).
#
# Uso:  ./apri_corso_csm.sh          apre http://127.0.0.1:8400 nel browser
#       ./apri_corso_csm.sh 8500     su un'altra porta (se e' occupata prova le successive)
# Si chiude con Ctrl+C.
#
# Il server ascolta solo su questo computer (127.0.0.1): dalla rete non si vede.
#
# Porta di partenza 8400, lontana da quelle di apri_corso.sh (8000, 8001, ...).
# Con 8001 (prima versione, 6/10/2026) il browser mostrava Programmazione
# Scientifica++: apri_corso.sh, trovando occupata la 8000, era gia' stato su
# 8001, e Chrome per quell'indirizzo teneva in cache le pagine di Prog-Sci
# (http.server non dice al browser di non conservarle, e i due siti hanno pagine
# con lo stesso percorso: index.html, lab-01/index.html, ...).
# Per lo stesso motivo il server qui risponde con "Cache-Control: no-store", e
# prima di aprire il browser si controlla che la home servita sia davvero CSM.
cd "$(dirname "$0")/static/csm" 2>/dev/null || { echo "Non trovo static/csm accanto allo script."; exit 1; }
[ -f index.html ] || { echo "static/csm e' vuota: pubblica prima con ./publish.sh <n_lab> da atomsim/SLIDES_2026-27."; exit 1; }
command -v python3 >/dev/null || { echo "Serve python3."; exit 1; }

PORTA=${1:-8400}
libera() { python3 -c "import socket,sys; s=socket.socket(); sys.exit(0 if s.connect_ex(('127.0.0.1',$1)) else 1)"; }
until libera "$PORTA"; do PORTA=$((PORTA+1)); done
URL="http://127.0.0.1:$PORTA/index.html"

if [ ! -f mathjax/MathJax.js ]; then
  echo "ATTENZIONE: questa copia prende MathJax da internet, quindi senza rete le formule"
  echo "non si vedono. Rilancia da atomsim/SLIDES_2026-27:  ./publish.sh <n_lab> --tutto"
fi

# come python3 -m http.server --bind 127.0.0.1, ma senza cache nel browser
python3 -c '
import sys, http.server
class H(http.server.SimpleHTTPRequestHandler):
    def end_headers(self):
        self.send_header("Cache-Control", "no-store")
        super().end_headers()
    def log_message(self, *a):
        pass
http.server.ThreadingHTTPServer(("127.0.0.1", int(sys.argv[1])), H).serve_forever()
' "$PORTA" >/dev/null 2>&1 &
SERVER=$!
trap 'kill $SERVER 2>/dev/null; echo; echo "Server dei lab CSM chiuso."' EXIT
trap 'exit 0' INT TERM

# aspetta che risponda (al massimo 5 secondi)
for _ in $(seq 50); do
  python3 -c "import urllib.request as u; u.urlopen('$URL', timeout=0.3)" 2>/dev/null && break
  sleep 0.1
done

# la home servita deve essere quella di CSM (e non un altro sito sulla stessa porta)
if ! python3 -c "import urllib.request as u, sys; sys.exit(0 if b'Computational Statistical Mechanics' in u.urlopen('$URL', timeout=2).read() else 1)" 2>/dev/null; then
  echo "ERRORE: su $URL non risponde il sito dei lab CSM. Riprova con un'altra porta: ./apri_corso_csm.sh 8500"
  exit 1
fi

echo "Lab di Computational Statistical Mechanics in locale: $URL"
echo "(Ctrl+C per chiudere)"
if [ "$(uname)" = "Darwin" ]; then
  # Chrome se c'e' (e' il browser su cui le slide sono state verificate), altrimenti quello predefinito
  open -a "Google Chrome" "$URL" 2>/dev/null || open "$URL"
fi
wait "$SERVER"
