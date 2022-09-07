/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:20:07 by jkiragu           #+#    #+#             */
/*   Updated: 2022/09/07 15:26:40 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_all_lines(char *src, int fd)
{
	char	*buf;
	int		len;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
	{
		free(buf);
		return (NULL);
	}
	len = 1;
	while (!ft_strchr(src, '\n') && len != 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[len] = '\0';
		src = ft_strjoin(src, buf);
	}
	free(buf);
	return (src);
}

char	*get_next_line(int fd)
{
	static char	*next_line;
	char		*current_line;

	current_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_line = get_all_lines(next_line, fd);
	if (next_line == NULL)
		return (NULL);
	current_line = read_current_line(next_line);
	next_line = save_all_lines(next_line);
	if (current_line[0] == '\0')
	{
		free(next_line);
		free(current_line);
		return (NULL);
	}
	return (current_line);
}
