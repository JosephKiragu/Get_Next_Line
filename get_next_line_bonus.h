/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkiragu <jkiragu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:23:24 by jkiragu           #+#    #+#             */
/*   Updated: 2022/09/07 16:07:44 by jkiragu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# ifndef MAX_LEN
#  define MAX_LEN 1024
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

// Main functions
char	*get_next_line_bonus(int fd);
char	*get_all_lines(char *str, int fd);
char	*save_all_lines(char *str);
char	*read_current_line(char *str);

//utility functions
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
char	*ft_strchr(char *str, int c);

#endif
