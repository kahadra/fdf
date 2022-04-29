/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wonkim <wonkim@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:26:21 by kimwon            #+#    #+#             */
/*   Updated: 2022/04/24 21:19:43 by wonkim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../HEADER/fdf.h"

char	*get_next_line(int fd);
char	*make_left_line(int fd, char *left_line);
char	*make_line(char *left_line);
char	*make_new_left_line(char *left_line);

char	*get_next_line(int fd)
{
	static char	*left_line;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	left_line = make_left_line(fd, left_line);
	if (!left_line)
		return (0);
	line = make_line(left_line);
	left_line = make_new_left_line(left_line);
	return (line);
}

char	*make_left_line(int fd, char *left_line)
{
	char	*buff;
	int		i;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (0);
	i = 1;
	while (!ft_strchr(left_line, '\n') && i != 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
		{
			free(buff);
			return (0);
		}
		buff[i] = '\0';
		left_line = ft_strjoin(left_line, buff);
	}
	free(buff);
	return (left_line);
}

char	*make_line(char *left_line)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_line[i])
		return (0);
	while (left_line[i] && left_line[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (left_line[i] && left_line[i] != '\n')
	{
		str[i] = left_line[i];
		i++;
	}
	if (left_line[i] == '\n')
	{
		str[i] = left_line[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*make_new_left_line(char *left_line)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_line[i] && left_line[i] != '\n')
		i++;
	if (!left_line[i])
	{
		free(left_line);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_line) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (left_line[i])
		str[j++] = left_line[i++];
	str[j] = '\0';
	free(left_line);
	return (str);
}
