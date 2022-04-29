/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 17:28:44 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 20:22:48 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

int	check_color(char *str);
int	hex_to_dec(char *hex, int base);

int	check_color(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			return (0);
		i++;
	}
	return (1);
}

int	hex_to_dec(char *hex, int base)
{
	int	dec;
	int	len;

	dec = 0;
	len = ft_strlen(hex);
	while (len-- >= 0)
	{
		if (hex[len] >= '0' && hex[len] <= '9')
		{
			dec += (hex[len] - 48) * base;
			base *= 16;
		}
		else if (hex[len] >= 'A' && hex[len] <= 'F')
		{
			dec += (hex[len] - 55) * base;
			base *= 16;
		}
		else if (hex[len] >= 'a' && hex[len] <= 'f')
		{
			dec += (hex[len] - 87) * base;
			base *= 16;
		}
	}
	return (dec);
}
