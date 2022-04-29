/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonkim <wonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 23:58:42 by kimwon            #+#    #+#             */
/*   Updated: 2022/04/24 21:19:37 by wonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../HEADER/fdf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(src);
	if (!dst || !src)
		return (0);
	if (dstsize == 0)
		return (size);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (size);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen + 1)
	{
		return (srclen + size);
	}
	if (size > dstlen + 1)
	{
		while (src[i] && dstlen + 1 + i < size)
		{
			dst[dstlen + i] = src[i];
			i++;
		}
	}
	dst[dstlen + i] = 0;
	return (dstlen + srclen);
}

char	*ft_strchr(char *s, int c)
{
	char	find;
	int		i;

	find = (char)c;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == find)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == find)
		return ((char *)s + i);
	return (0);
}

char	*ft_strjoin(char *left_line, char *buff)
{
	size_t	len;
	char	*tmp;

	if (!left_line)
	{
		left_line = (char *)malloc(sizeof(char));
		left_line[0] = 0;
	}
	if (!left_line || !buff)
		return (0);
	len = ft_strlen(left_line) + ft_strlen(buff) + 1;
	tmp = (char *)malloc(sizeof(char) * (len));
	if (!tmp)
		return (0);
	ft_strlcpy(tmp, left_line, len);
	ft_strlcat(tmp, buff, len);
	free(left_line);
	return (tmp);
}
