/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 16:48:10 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 22:58:22 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_free_data_struct(t_fdf *data);
double	ft_max(double a, double b);
void	free_matrix(t_dots **z_matrix, int length);

int	ft_atoi(char *str)
{
	size_t		i;
	long long	j;
	short		sign;

	i = 0;
	j = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		if (j * 10 + (sign * (str[i] - '0')) < j && sign > 0)
			return (-1);
		if (j * 10 + (sign * (str[i] - '0')) > j && sign < 0)
			return (0);
		j = j * 10 + (sign * (str[i] - '0'));
		i++;
	}
	return (j);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	ft_free_data_struct(t_fdf *data)
{
	int	i;

	i = 0;
	while (i <= data->height)
	{
		free(data->z_matrix[i]);
		i++;
	}
	free(data->z_matrix);
	free(data);
}

double	ft_max(double a, double b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

void	free_matrix(t_dots **z_matrix, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		free(z_matrix[i]);
		i++;
	}
	free(z_matrix);
}
