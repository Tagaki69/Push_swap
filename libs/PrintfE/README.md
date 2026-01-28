# ft_printf 📝

## 🎯 Description

Implémentation personnalisée de `printf()` en C utilisant les fonctions variadiques. Projet du cursus 42 pour approfondir la gestion des arguments variables et du formatage.

## 🚀 Conversions supportées

- `%c` - Caractère | `%s` - Chaîne | `%p` - Pointeur
- `%d` - Décimal | `%i` - Entier | `%u` - Non signé  
- `%x` - Hex minuscule | `%X` - Hex majuscule | `%%` - Littéral

## 📁 Structure

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

## 📝 Aperçu des Fonctions

### 🎯 Fonction principale
- **`ft_printf()`** - Point d'entrée principal qui parse le format et gère les arguments variadiques

### ⚡ Gestionnaires de conversions
- **`handle_char_percent()`** - Gère `%c` (caractères) et `%%` (pourcentage littéral)
- **`handle_string()`** - Gère `%s` (chaînes) avec protection NULL → `"(null)"`
- **`handle_int_uint()`** - Gère `%d`, `%i` (entiers) et `%u` (non signés)
- **`handle_hex()`** - Gère `%x` (hex minuscule) et `%X` (hex majuscule)
- **`handle_pointer()`** - Gère `%p` (pointeurs) avec préfixe `0x` et NULL → `"(nil)"`

### 🔧 Utilitaires de conversion
- **`ft_itoa()`** - Convertit les entiers signés en chaînes (gère INT_MIN)
- **`ft_uitoa_base()`** - Convertit nombres non signés dans n'importe quelle base avec charset personnalisé

### 📤 Fonctions de sortie
- **`ft_putchar_fd()`** - Écrit un caractère sur un descripteur de fichier
- **`ft_putstr_fd()`** - Écrit une chaîne sur un descripteur de fichier**

### 🧰 Utilitaires string
- **`ft_strlen()`** - Calcule la longueur d'une chaîne
- **`ft_strdup()`** - Duplique une chaîne en allouant de la mémoire

### 🏗️ Architecture
**Architecture modulaire** avec séparation claire des responsabilités :
- **Parser** (ft_printf.c) → **Convertisseurs** (ft_printf_convertions.c) → **Utilitaires** (ft_itoa_all.c, ft_string.c, ft_output.c)

## 🏆 Note obtenue

**100/100** ✨

## 🛠️ Contraintes 42

✅ ≤25 lignes/fonction ✅ ≤80 colonnes ✅ Gestion mémoire stricte ✅ Norme 42

## 📚 Concepts clés

**Fonctions variadiques** • **Parsing de format** • **Conversions de base** • **Architecture modulaire**

---

## ⚠️ Disclaimer 42

Ce dépôt est rendu public pour présenter mon code et servir de ressource pédagogique ; le plagiat est strictement interdit et vous devez être capable d'expliquer votre propre travail.

*Projet réalisé dans le cadre du cursus 42* 🎓
