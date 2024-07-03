/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:25:42 by zsailine          #+#    #+#             */
/*   Updated: 2024/04/08 11:33:13 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 12
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t		ft_strlen(const char *src);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int character);
char		*get_next_line(int fd);
char		*ft_strchr(const char *str, int character);

#endif