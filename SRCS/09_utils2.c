/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:52:23 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 21:48:02 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

char			**ft_split(char *s, char c);
static size_t	word_count(char *s, char c);
static char		*save_word(char *s, char c);
static void		free_all(char **word);
void			*ft_calloc(size_t count, size_t size);

char	**ft_split(char *s, char c)
{
	size_t	i;
	char	**word;

	i = 0;
	if (!s)
		return (0);
	word = ft_calloc(word_count(s, c) + 1, sizeof(char *));
	while (word && *s)
	{
		if (*s == c)
			s++;
		else
		{
			word[i] = save_word(s, c);
			if (word[i] == NULL)
			{
				free_all(word);
				return (0);
			}
			s += ft_strlen(word[i]);
			i++;
		}
	}
	return (word);
}

static size_t	word_count(char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			count++;
		i++;
	}
	return (count);
}

static char	*save_word(char *s, char c)
{
	size_t	len;
	char	*word;

	len = ft_strlen(s);
	if (ft_strchr(s, c))
		len = (size_t)(ft_strchr(s, c) - s);
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (0);
	ft_strlcpy(word, s, len + 1);
	return (word);
}

static void	free_all(char **word)
{
	char	**arr;

	arr = word;
	while (*arr)
		free(*(arr++));
	free(word);
}

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;

	tmp = malloc(size * count);
	if (!tmp)
		return (0);
	ft_memset(tmp, 0, size * count);
	return (tmp);
}
