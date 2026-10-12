#!/bin/bash
# Apre in locale SOLO il sito del corso (static/prog-sci), senza Hugo e senza
# dipendenze: basta python3, che sul Mac c'e' gia'. E' la copia pubblicata da
# publish_week.sh, identica a quella online (voci future in grigio comprese),
# e con MathJax dentro le formule si vedono anche senza rete.
#
# Uso:  ./apri_corso.sh          apre http://127.0.0.1:8000 nel browser
#       ./apri_corso.sh 8080     su un'altra porta (se e' occupata prova le successive)
# Si chiude con Ctrl+C.
#
# Il server ascolta solo su questo computer (127.0.0.1): dalla rete non si vede.
cd "$(dirname "$0")/static/prog-sci" 2>/dev/null || { echo "Non trovo static/prog-sci accanto allo script."; exit 1; }
[ -f index.html ] || { echo "static/prog-sci e' vuota: pubblica prima con ./publish_week.sh <settimana>."; exit 1; }
command -v python3 >/dev/null || { echo "Serve python3."; exit 1; }

PORTA=${1:-8000}
libera() { python3 -c "import socket,sys; s=socket.socket(); sys.exit(0 if s.connect_ex(('127.0.0.1',$1)) else 1)"; }
until libera "$PORTA"; do PORTA=$((PORTA+1)); done
URL="http://127.0.0.1:$PORTA/index.html"

if [ ! -f mathjax/MathJax.js ]; then
  echo "ATTENZIONE: questa copia prende MathJax da internet, quindi senza rete le formule"
  echo "non si vedono. Rilancia dalla cartella LEZIONI:  ./publish_week.sh <settimana> --tutto"
fi

python3 -m http.server "$PORTA" --bind 127.0.0.1 >/dev/null 2>&1 &
SERVER=$!
trap 'kill $SERVER 2>/dev/null; echo; echo "Server del corso chiuso."' EXIT
trap 'exit 0' INT TERM

# aspetta che risponda (al massimo 5 secondi)
for _ in $(seq 50); do
  python3 -c "import urllib.request as u; u.urlopen('$URL', timeout=0.3)" 2>/dev/null && break
  sleep 0.1
done

echo "Corso in locale: $URL"
echo "(Ctrl+C per chiudere)"
if [ "$(uname)" = "Darwin" ]; then
  # Chrome se c'e' (e' il browser su cui le slide sono state verificate), altrimenti quello predefinito
  open -a "Google Chrome" "$URL" 2>/dev/null || open "$URL"
fi
wait "$SERVER"
