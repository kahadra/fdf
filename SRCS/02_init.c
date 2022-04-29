/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:47:25 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 22:57:52 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

void	init_struct(t_fdf *data);
void	init_image(t_fdf *data);
void	ft_isometric(double *x, double *y, int z, t_fdf *data);
void	ft_parallel(double *x, double *y, int z, t_fdf *data);
void	make_step(double *x_step, double *y_step, int *max);

void	init_struct(t_fdf *data)
{
	data->zoom = 30;
	data->z_scale = 2;
	data->shift_y = 250;
	data->shift_x = 900;
	data->scr_x = WIDTH;
	data->scr_y = HEIGHT;
	data->angle_cos = 0.8;
	data->angle_sin = 0.8;
	data->flag = 1;
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1800, 1000, "FdF");
}

void	init_image(t_fdf *data)
{
	data->img = mlx_new_image(data->mlx, 1800, 1000);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_len, &data->endian);
}

void	ft_isometric(double *x, double *y, int z, t_fdf *data)
{
	*x = (*x - *y) * cos(data->angle_cos);
	*y = (*x + *y) * sin(data->angle_sin) - z;
}

void	ft_parallel(double *x, double *y, int z, t_fdf *data)
{
	*x = *x - z * sin(data->angle_sin);
	*y = *y - z * cos(data->angle_cos);
}

void	make_step(double *x_step, double *y_step, int *max)
{
	*max = ft_max(fabs(*x_step), fabs(*y_step));
	*x_step /= *max;
	*y_step /= *max;
}
