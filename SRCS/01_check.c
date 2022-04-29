/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   001_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:06:11 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 20:06:13 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

int	file_check(char *file_name);
int	check_read(char *file_name);

int	file_check(char *file_name)
{
	int	i;
	int	size;

	size = ft_strlen(file_name);
	i = size - 4;
	if (file_name[i++] != '.')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	if (file_name[i++] != 'd')
		return (1);
	if (file_name[i++] != 'f')
		return (1);
	return (0);
}

int	check_read(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY, 0);
	if (fd < 0)
		return (1);
	return (0);
}
