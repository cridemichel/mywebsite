---
title: 'Shadow Hamiltonian in molecular dynamics simulations: Against a possible suggested
  misuse of its physical meaning'

# Authors
# A YAML list of author names
# If you created a profile for a user (e.g. the default `admin` user at `content/authors/admin/`), 
# write the username (folder name) here, and it will be replaced with their full name and linked to their profile.
authors:
- Cristiano De Michele
- Giovanni Ciccotti

# Author notes (such as 'Equal Contribution')
# A YAML list of notes for each author in the above `authors` list
author_notes: []

date: '2026-06-01'

# Date to publish webpage (NOT necessarily Bibtex publication's date).
publishDate: '2026-06-24T11:25:02.719726Z'

# Publication type.
# A single CSL publication type but formatted as a YAML list (for Hugo requirements).
publication_types:
- 2

# Publication name and optional abbreviated publication name.
publication: '*The Journal of Chemical Physics*'
publication_short: ''

doi: 10.1063/5.0308262

abstract: Symplectic integrators are largely employed in MD due to their long-term
  stability and near conservation of invariants. Their numerical robustness can be
  rationalized by the existence of a shadow Hamiltonian Hsh, exactly conserved by
  symplectic integrators and expressible as an asymptotic expansion with respect to
  the integration time steps δt around the physical Hamiltonian H. In this work, we
  suggest not attaching any physical meaning to Hsh, based on theoretical analysis
  and MD simulations of a standard LJ system using the velocity-Verlet algorithm.
  We do not intend to optimize symplectic algorithms. Instead, we claim that the existence
  of Hsh cannot provide better observables to estimate statistical properties. For
  that reason, we will also examine the behavior of trajectories integrated with large
  δt that are always exact integrations of their corresponding Hsh(δt). To these trajectories,
  of course, we do not attach a physical meaning. Note that the stability of the energy
  cannot be enough to guarantee accurate estimates of statistical properties. Although
  symplectic integrators yield, within numerical accuracy, exact trajectories of Hsh,
  thermodynamic quantities derived from Hsh deviate from the physical ones when δt
  is too large. Indeed, the conventional kinetic temperature of H is wrongly estimated
  for large δt, while “shadow” temperature becomes unphysical for the same large δt,
  despite its exact meaning for Hsh. We conclude that Hsh lacks physical relevance
  for large δt, and the only remedy to perform simulations by standard integrators,
  such as the velocity-Verlet, is to use a short enough δt, in which case the estimated
  physical properties coincide.

# Summary. An optional shortened abstract.
summary: ''

tags: []

# Display this page in a list of Featured pages?
featured: false

# Links
url_pdf: ''
url_code: ''
url_dataset: ''
url_poster: ''
url_project: ''
url_slides: ''
url_source: ''
url_video: ''

# Custom links (uncomment lines below)
# links:
# - name: Custom Link
#   url: http://example.org

# Publication image
# Add an image named `featured.jpg/png` to your page's folder then add a caption below.
image:
  caption: ''
  focal_point: ''
  preview_only: false

# Associated Projects (optional).
#   Associate this publication with one or more of your projects.
#   Simply enter your project's folder or file name without extension.
#   E.g. `projects: ['internal-project']` links to `content/project/internal-project/index.md`.
#   Otherwise, set `projects: []`.
projects: []
links:
- name: URL
  url: https://doi.org/10.1063/5.0308262
---

Add the **full text** or **supplementary notes** for the publication here using Markdown formatting.
