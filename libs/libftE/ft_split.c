/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elarue <elarue@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:10:13 by enzol             #+#    #+#             */
/*   Updated: 2025/11/20 15:59:19 by elarue           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	in_word = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && in_word == 0)
		{
			in_word = 1;
			count++;
		}
		else if (s[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

char	**free_all(int word_index, char **result)
{
	while (word_index >= 0)
		free(result[word_index--]);
	free(result);
	return (NULL);
}

void	helper(char *in_word, int *start, int *i)
{
	*in_word = 1;
	*start = *i;
}

char	**extract_words(char const *s, char c, char in_word, char **result)
{
	int	start;
	int	word_index;
	int	i;

	i = -1;
	word_index = 0;
	while (s[++i])
	{
		if (s[i] != c && in_word == 0)
			helper(&in_word, &start, &i);
		else if (s[i] == c && in_word == 1)
		{
			in_word = 0;
			result[word_index++] = ft_substr(s, start, i - start);
			if (!result[word_index - 1])
				return (free_all(word_index - 1, result));
		}
	}
	if (in_word == 1)
		result[word_index++] = ft_substr(s, start, i - start);
	if (!result[word_index - 1] && word_index != 0)
		return (free_all(word_index - 1, result));
	result[word_index] = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		nbr_words;
	int		in_word;
	char	**extract;

	in_word = 0;
	if (s == NULL)
		return (NULL);
	nbr_words = count_words(s, c);
	result = malloc((nbr_words + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	extract = extract_words(s, c, in_word, result);
	return (extract);
}
/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**result;
	int		i;

	if (argc == 3)
	{
		result = ft_split(argv[1], argv[2][0]);
		i = 0;
		printf("String: '%s'\n", argv[1]);
		printf("Delimiter: '%c'\n", argv[2][0]);
		printf("Result:\n");
		while (result[i])
		{
			printf("[%d]: '%s'\n", i, result[i]);
			free(result[i]);
			i++;
		}
		free(result);
	}
	return (0);
}
*/