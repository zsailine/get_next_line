/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:26:27 by zsailine          #+#    #+#             */
/*   Updated: 2024/04/10 10:03:10 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free(char *str)
{
	free(str);
	str = NULL;
}

static char	*ft_read(int fd, char *text)
{
	ssize_t	check_read;
	char	*tmp;
	char	*src;

	check_read = 1;
	src = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!src)
		return (NULL);
	while (check_read != 0)
	{
		check_read = read(fd, src, BUFFER_SIZE);
		if (check_read < 0)
			return (ft_free(text), ft_free(src), NULL);
		else if (check_read == 0)
			break ;
		src[check_read] = '\0';
		if (!text)
			text = ft_strdup("");
		tmp = text;
		text = ft_strjoin(tmp, src);
		ft_free(tmp);
		if (ft_strchr(src, '\n'))
			break ;
	}
	return (ft_free(src), text);
}

static char	*ft_get_new_line(char *text)
{
	int		i;
	char	*new_text;

	i = 0;
	while (text[i] != '\0' && text[i] != '\n')
		i++;
	if (!text[i])
		return (NULL);
	new_text = ft_substr(text, i + 1, ft_strlen(text) - i + 1);
	if (!*new_text)
		return (ft_free(new_text), NULL);
	return (new_text);
}

static char	*ft_get_line(char *text)
{
	char	*dest;
	ssize_t	i;

	i = 0;
	while (text[i] != '\n' && text[i] != '\0')
		i++;
	dest = ft_substr(text, 0, i + 1);
	if (!*dest)
		return (ft_free(dest), NULL);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*dest;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (ft_free(text), NULL);
	tmp = ft_read(fd, text);
	if (!tmp)
		return (NULL);
	dest = ft_get_line(tmp);
	if (!dest)
		return (ft_free(dest), NULL);
	text = ft_get_new_line(tmp);
	ft_free(tmp);
	return (dest);
}
