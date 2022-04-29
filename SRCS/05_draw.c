/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:59:34 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 22:56:57 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

void	draw(t_fdf *data, t_dots **z_matrix);
void	print_to_img(t_fdf *data, t_dots **z_matrix);
void	print_menu(t_fdf *data);
void	*ft_memset(void *s, int c, size_t n);

void	draw(t_fdf *data, t_dots **z_matrix)
{
	ft_bzero(data->addr, data->scr_x * data->scr_y
		* (data->bits_per_pixel / 8));
	print_to_img(data, z_matrix);
}

void	print_to_img(t_fdf *data, t_dots **z_matrix)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data->height)
	{
		x = -1;
		while (++x < data->width)
		{
			if (x < data->width - 1)
				check_flag(z_matrix[y][x], z_matrix[y][x + 1], data);
			if (y < data->height - 1)
				check_flag(z_matrix[y][x], z_matrix[y + 1][x], data);
		}
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	print_menu(data);
}

void	print_menu(t_fdf *data)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 0;
	mlx = data->mlx;
	win = data->win;
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Move: <- | ->");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Zoom: + | -");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Scale: Q | W");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Rotate: A | S | D | F");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Exit: ESC");
	mlx_string_put(mlx, win, 15, y += 30, 0xC2B280, "Pro: ON/OFF: 1 | 2");
}

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
