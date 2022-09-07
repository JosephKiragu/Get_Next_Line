/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:20:27 by jkiragu           #+#    #+#             */
/*   Updated: 2022/09/07 15:26:00 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

//main functions
char	*get_next_line(int fd);
char	*get_all_lines(char *str, int fd);
char	*save_all_lines(char *str);
char	*read_current_line(char *str);

//utility functions
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);

#endif