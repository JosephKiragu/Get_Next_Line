/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:15:28 by jkiragu           #+#    #+#             */
/*   Updated: 2022/09/07 15:23:37 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (s1 == NULL)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *c)
{
	size_t	j;

	j = 0;
	while (c[j++] != 0)
		;
	return (j);
}

char	*ft_strchr(char *str, int j)
{
	size_t	z;

	z = 0;
	if (str == NULL)
		return (0);
	if (j == '\0')
		return ((char *)&str[ft_strlen(str)]);
	while (str[z] != '\0')
	{
		if (str[z] == j)
			return ((char *)&str[z]);
		z++;
	}
	return (0);
}

char	*read_current_line(char *str)
{
	size_t	j;
	char	*line;

	j = 0;
	if (str == NULL)
		return (NULL);
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	line = (char *)malloc(sizeof(char) * (j + 2));
	if (line == NULL)
		return (NULL);
	j = 0;
	while (str[j] != '\0' && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*save_all_lines(char *str)
{
	size_t	j;
	size_t	k;
	char	*lines;

	j = 0;
	k = 0;
	while (str[j] != '\0' && str[j] != '\n')
		j++;
	if (str[j] == '\0')
	{
		free(str);
		return (0);
	}
	lines = malloc(sizeof(lines) * (ft_strlen(str) - j + 1));
	if (lines == NULL)
		return (NULL);
	j++;
	while (str[j] != '\0')
		lines[k++] = str[j++];
	lines[k] = '\0';
	free (str);
	return (lines);
}
