/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wakhazza <wakhazza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 08:42:17 by wakhazza          #+#    #+#             */
/*   Updated: 2026/01/29 16:48:28 by wakhazza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../push_swap.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	size_t			i;

	if (!s)
		return (0);
	c1 = (unsigned char)c;
	i = 0;
	while (s[i])
	{
		if ((unsigned char)s[i] == c1)
			return ((char *)&s[i]);
		i++;
	}
	if (c1 == '\0')
		return ((char *)&s[i]);
	return (0);
}

static char	*save_next(char *s)
{
	int		i;
	int		j;
	char	*saved;

	i = 0;
	if (!s || !*s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if (!s[i])
		return (free_and_null(s));
	saved = malloc(ft_strlen_g(s) - i + 1);
	if (!saved)
		return (free_and_null(s));
	j = 0;
	while (s[i])
		saved[j++] = s[i++];
	saved[j] = '\0';
	free(s);
	return (saved);
}

static char	*extract_line(char *s)
{
	int		i;
	char	*line;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		line = malloc(i + 2);
	else
		line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		line[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

static char	*find_next_line(int fd, char *stash)
{
	char	*buf;
	int		nb_read;

	nb_read = 1;
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (free_and_null(stash));
	while (!ft_strchr(stash, '\n') && nb_read != 0)
	{
		nb_read = read(fd, buf, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(buf);
			return (free_and_null(stash));
		}
		buf[nb_read] = '\0';
		stash = ft_strjoin_g(stash, buf);
		if (!stash)
			return (free_and_null(buf));
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	stash = find_next_line(fd, stash);
	if (!stash)
		return (NULL);
	if (!*stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = save_next(stash);
	return (line);
}
// #include <stdio.h>
// int	main(void)
// {
// 	// int	fd = open("machin.txt", O_RDONLY);
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// printf("%s", get_next_line(fd));
// 	// close(fd);

// 	int	fd = open("machin.txt", O_RDONLY);
// 	char *s = get_next_line(fd);
// 	printf("%s", s);
// 	free(s);
// 	char *s1 = get_next_line(fd);
// 	printf("%s", s1);
// 	free(s1);
// 	char *s2 = get_next_line(fd);
// 	printf("%s", s2);
// 	free(s2);
// 	char *s3 = get_next_line(fd);
// 	printf("%s", s3);
// 	free(s3);
// 	close(fd);
// }

// #include "get_next_line.h"
// #include <stdio.h>
// #include <fcntl.h>

// int main(void)
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("machin.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		printf("Erreur d'ouverture du fichier");
// 		return (1);
// 	}

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return (0);
// }