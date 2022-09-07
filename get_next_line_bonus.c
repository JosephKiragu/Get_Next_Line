#include "get_next_line_bonus.h"
#include <stdio.h>

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

char	*get_next_line_bonus(int fd)
{
	char		*current_line;
	static char	*next_line[MAX_LEN];

	current_line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	next_line[fd] = get_all_lines(next_line[fd], fd);
	current_line = read_current_line(next_line[fd]);
	next_line[fd] = save_all_lines(next_line[fd]);
	if (current_line[0] == '\0')
	{
		free(next_line[fd]);
		free(current_line);
		return (NULL);
	}
	return (current_line);
}
