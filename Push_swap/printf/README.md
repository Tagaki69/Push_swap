*This project has been created as part of the 42 curriculum by elarue.*

# ft_printf

## Description

`ft_printf` est une ré-implémentation du comportement de base de `printf()` en C.
Le but du projet : comprendre la gestion des arguments variables, le parsing d’un format, et le fonctionnement des conversions standards.
Le programme utilise les fonctions variadiques (`va_list`, `va_start`, `va_arg`, `va_end`) et applique un système interne de dispatch pour chaque type de conversion.

## Supported Conversions

* `%c` : caractère
* `%s` : chaîne
* `%p` : pointeur
* `%d` / `%i` : entier signé
* `%u` : entier non signé
* `%x` / `%X` : hexadécimal (minuscule/majuscule)
* `%%` : pourcentage littéral

## Project Structure

```
ft_printf/
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_printf_convertions.c
├── ft_output.c
├── ft_string.c
└── ft_itoa_all.c
```

## Instructions

### Compilation

```
make
```

Cela génère `libftprintf.a`.

### Utilisation

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Value: %d\n", 42);
}
```

### Nettoyage

```
make clean
make fclean
make re
```

## Functions Overview

### Core

* `ft_printf()` : lit la chaîne de format, avance caractère par caractère, identifie les conversions et envoie vers les handlers adaptés.

### Conversion handlers

* `handle_char_percent()` : `%c` et `%%`
* `handle_string()` : `%s`, gère les pointeurs NULL avec `(null)`
* `handle_int_uint()` : `%d`, `%i`, `%u`
* `handle_hex()` : `%x`, `%X`
* `handle_pointer()` : `%p`, affiche `0x` + valeur ou `(nil)` si NULL

### Conversion utilities

* `ft_itoa()` : entiers signés
* `ft_uitoa_base()` : entiers non signés dans n’importe quelle base

### Output helpers

* `ft_putchar_fd()`
* `ft_putstr_fd()`

### String utilities

* `ft_strlen()`
* `ft_strdup()`

## Algorithm and Data Structure Explanation

### Parsing algorithm

1. Parcours linéaire de la chaîne de format.
2. Si le caractère n’est pas `%`, impression directe.
3. Si `%` détecté : lecture du spécificateur suivant.
4. Utilisation d’une table de correspondance interne (switch-like) qui redirige vers la fonction de conversion adaptée.
5. Récupération d’un argument via `va_arg` et exécution du handler.

Ce choix privilégie :

* simplicité du flux de contrôle
* coûts faibles au runtime
* absence de structures complexes inutiles pour ce projet

### Data structures

Le projet reste volontairement minimaliste :

* tableaux statiques de bases (`"0123456789abcdef"` / `"0123456789ABCDEF"`)
* chaînes allouées dynamiquement pour les conversions numériques
* aucun conteneur avancé (pas nécessaire pour les exigences de `printf` basique)

Ce design limite l’empreinte mémoire et facilite la conformité à la norme 42.

## Resources

### Documentation standard C

* `man 3 printf`
* `man 3 stdarg`
* `https://cplusplus.com/reference/cstdarg/`

### Articles / guides

* Variadic functions in C
* Hexadecimal conversion algorithms
* Integer-to-string implementation examples

### Use of AI

L’IA a été utilisée pour :

* structurer la documentation
* reformuler des explications pour clarifier l’architecture
* produire un README conforme aux exigences de l’école
  Aucune génération automatique de code n’a été réalisée ; la logique du projet, les fonctions et les algorithmes ont été développés manuellement.

## Additional Notes

* Conforme aux contraintes 42 :

  * max 25 lignes/fonction
  * max 80 colonnes
  * attention stricte à la gestion mémoire
  * structure modulaire

## Disclaimer

Ce dépôt est public pour montrer mon travail et aider d’autres étudiants.
Chaque étudiant doit coder et comprendre sa propre version de `ft_printf`.