/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsailine <zsailine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 16:24:56 by zsailine          #+#    #+#             */
/*   Updated: 2024/04/10 10:03:42 by zsailine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *src)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (ft_strlen((char *)s) + 1));
	i = 0;
	if (!(dest))
		return (0);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	chain;
	size_t	i;

	chain = ft_strlen((char *)s);
	i = 0;
	if (start >= chain)
		return (ft_strdup(""));
	if (len > chain - start)
		len = ft_strlen(s + start);
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	srclen1;
	size_t	srclen2;
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	srclen1 = ft_strlen(s1);
	srclen2 = ft_strlen(s2);
	dest = malloc(sizeof(char) * (srclen1 + srclen2 + 1));
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		dest[i + j] = s2[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == (char)character)
			return ((char *)str);
		str++;
	}
	if (*str == (char)character)
		return ((char *)str);
	return (0);
}
