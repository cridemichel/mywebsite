---
# Documentation: https://wowchemy.com/docs/managing-content/

title: 'Algorithm 1010: Boosting Efficiency in Solving Quartic Equations with No Compromise
  in Accuracy'
subtitle: ''
summary: ''
authors:
- A. G. Orellana
- C. De Michele
tags:
- '"numerical solver design"'
- '"Quartic equation"'
- '"performance"'
- '"factorization into quadratics"'
- '"Newton-Raphson scheme"'
categories: []
date: '2020-05-01'
lastmod: 2021-04-18T10:27:27+02:00
featured: false
draft: false

# Featured image
# To use, add an image named `featured.jpg/png` to your page's folder.
# Focal points: Smart, Center, TopLeft, Top, TopRight, Left, Right, BottomLeft, Bottom, BottomRight.
image:
  caption: ''
  focal_point: ''
  preview_only: false

# Projects (optional).
#   Associate this post with one or more of your projects.
#   Simply enter your project's folder or file name without extension.
#   E.g. `projects = ["internal-project"]` references `content/project/deep-learning/index.md`.
#   Otherwise, set `projects = []`.
projects: []
publishDate: '2021-04-18T08:27:27.253573Z'
publication_types:
- '2'
abstract: Aiming to provide a very accurate, efficient, and robust quartic equation
  solver for physical applications, we have proposed an algorithm that builds on the
  previous works of P. Strobach and S. L. Shmakov. It is based on the decomposition
  of the quartic polynomial into two quadratics, whose coefficients are first accurately
  estimated by handling carefully numerical errors and afterward refined through the
  use of the Newton-Raphson method. Our algorithm is very accurate in comparison with
  other state-of-the-art solvers that can be found in the literature, but (most importantly)
  it turns out to be very efficient according to our timing tests. A crucial issue
  for us is the robustness of the algorithm, i.e., its ability to cope with the detrimental
  effect of round-off errors, no matter what set of quartic coefficients is provided
  in a practical application. In this respect, we extensively tested our algorithm
  in comparison to other quartic equation solvers both by considering specific extreme
  cases and by carrying out a statistical analysis over a very large set of quartics.
  Our algorithm has also been heavily tested in a physical application, i.e., simulations
  of hard cylinders, where it proved its absolute reliability as well as its efficiency.
publication: '*ACM Trans. Math. Softw.*'
url_pdf: https://doi.org/10.1145/3386241
doi: 10.1145/3386241
---
