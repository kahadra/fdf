/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:35:05 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 22:59:26 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

int	key_event(int key, t_fdf *data);
int	move(int key, t_fdf *data);
int	zoom(int key, t_fdf *data);
int	angle(int key, t_fdf *data);
int	z_scale(int key, t_fdf *data);

int	key_event(int key, t_fdf *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move(key, data);
	if (key == ZOOM_UP || key == ZOOM_DOWN)
		zoom(key, data);
	if (key == ANGLE_COS_DOWN || key == ANGLE_COS_UP || key == ANGLE_SIN_DOWN \
												|| key == ANGLE_SIN_UP)
		angle(key, data);
	if (key == Z_UP || key == Z_DOWN)
		z_scale(key, data);
	if (key == ISO_ON)
		data->flag = 1;
	if (key == ISO_OFF)
		data->flag = 0;
	if (key == PAR)
		data->flag = 2;
	if (key == ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->img);
		ft_free_data_struct(data);
		exit(0);
	}
	draw(data, data->z_matrix);
	return (0);
}

int	move(int key, t_fdf *data)
{
	if (key == UP)
		data->shift_y -= 50;
	if (key == DOWN)
		data->shift_y += 50;
	if (key == LEFT)
		data->shift_x -= 50;
	if (key == RIGHT)
		data->shift_x += 50;
	return (0);
}

int	zoom(int key, t_fdf *data)
{
	if (key == ZOOM_UP)
		data->zoom += 1;
	if (key == ZOOM_DOWN && data->zoom > 0)
		data->zoom -= 1;
	return (0);
}

int	angle(int key, t_fdf *data)
{
	if (key == ANGLE_COS_UP)
		data->angle_cos += 0.01;
	if (key == ANGLE_COS_DOWN)
		data->angle_cos -= 0.01;
	if (key == ANGLE_SIN_UP)
		data->angle_sin += 0.01;
	if (key == ANGLE_SIN_DOWN)
		data->angle_sin -= 0.01;
	return (0);
}

int	z_scale(int key, t_fdf *data)
{
	if (key == Z_UP)
		data->z_scale += 0.1;
	if (key == Z_DOWN)
		data->z_scale -= 0.1;
	return (0);
}
