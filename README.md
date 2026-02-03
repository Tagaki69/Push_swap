*This project was created as part of the 42 curriculum by elarue and wakhazza.*

## 📝 Description

**push_swap** est un projet d’algorithmique dont l’objectif est de trier une pile de nombres entiers en utilisant deux piles (`a` et `b`) et un ensemble d’instructions limité. Le but est de générer une suite d’opérations la plus courte possible pour obtenir une pile `a` triée par ordre croissant. Ce projet permet d’explorer la complexité algorithmique et l’optimisation selon la configuration initiale des données et leur taux de désordre.

## 🛠️ Instructions

### Compilation

Le projet utilise un `Makefile` respectant les règles `all`, `clean`, `fclean` et `re`.

```bash
make
```

### Exécution

Le programme prend une liste d’entiers en argument.

```bash
./push_swap 2 1 3 6 5 8
```

## 🎛️ Sélecteurs de stratégie

Il est possible de forcer une stratégie spécifique via les drapeaux suivants :

* `--simple` : force l’algorithme à utiliser le **tri par insertion**.
* `--medium` : force l’algorithme à utiliser le **chunk-based sorting**.
* `--complex` : force l’algorithme à utiliser le **radix sort (LSD)**.
* `--adaptive` : utilise la stratégie basée sur le désordre (comportement par défaut si aucun flag n’est indiqué).

## 🧪 Mode Benchmark

Le drapeau `--bench` affiche sur `stderr` :

* le pourcentage de désordre calculé ;
* le nom de la stratégie et sa classe de complexité théorique ;
* le nombre total d’opérations et le décompte détaillé par type.

## 🧠 Algorithmes et justification

Nous avons implémenté quatre stratégies distinctes pour répondre aux exigences du sujet :

1. **Simple** : adaptation du **tri par insertion**. Efficace pour les très petites piles ; elle limite les manipulations en privilégiant des insertions directes.
2. **Medium** : utilise un **chunk-based sorting**. La pile est divisée en morceaux pour réduire le coût de recherche.
3. **Complex** : implémentation d’un **radix sort (LSD)** binaire après compression d’index. Cette méthode garantit une performance stable sur de grands volumes de données.
4. **Adaptive** : sélectionne dynamiquement la méthode selon la métrique de désordre calculée via `compute_disorder` avant tout mouvement.

## 🧩 Logique de la stratégie Adaptive

Les seuils suivants ont été choisis pour optimiser les performances :

* **Désordre < 0.2 (faible)** : utilise l’**insertion sort** pour viser une complexité proche de l’optimal sur des listes presque triées.
* **0.2 ≤ Désordre < 0.5 (moyen)** : utilise le **chunk sort** pour conserver de bonnes performances sans exploser le nombre d’opérations.
* **Désordre ≥ 0.5 (élevé)** : utilise le **radix sort** pour garder une performance régulière, même sur des listes très mélangées.


## 🤝 Contributions

* **elarue** :

  * conception du parsing et de la validation des données (doublons, limites `INT`) ;
  * ajout du paramètre .2f dans la fonction printf pour afficher un float avec deux chiffres après la virgule ;
  * implémentation de l’algorithme **Complex** (radix sort) et de la compression d’index ;

* **wakhazza** :

  * implémentation des algorithmes **Simple** (insertion sort) et **Medium** (chunk sort) ;
  * développement de la stratégie **Adaptive** et du calcul du désordre ;
  * fonctions utilitaires de gestion de pile et calculs associés.

## 📚 Ressources et IA

### Ressources classiques

* [Sorting algorithm — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
* [Tri par base (Radix sort) — Wikipedia](https://fr.wikipedia.org/wiki/Tri_par_base)
* [Tri par insertion — Wikipedia](https://fr.wikipedia.org/wiki/Tri_par_insertion)

### Utilisation de l’IA

L’IA a été utilisée comme assistant pédagogique pour les tâches suivantes :

* **explication théorique** : aide à la compréhension des mécanismes des différents algorithmes de tri.