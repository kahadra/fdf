/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:04:18 by chpark            #+#    #+#             */
/*   Updated: 2022/04/29 17:04:59 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

void	check_flag(t_dots start, t_dots end, t_fdf *data);
void	bresenham_iso(t_dots start, t_dots end, t_fdf *data);
void	bresenham_par(t_dots start, t_dots end, t_fdf *data);

void	check_flag(t_dots start, t_dots end, t_fdf *data)
{
	if (data->flag == 2)
		bresenham_par(start, end, data);
	else
		bresenham_iso(start, end, data);
}

void	bresenham_iso(t_dots start, t_dots end, t_fdf *data)
{
	double	x_step;
	double	y_step;
	int		max;

	get_zoom(&start, &end, data);
	if (data->flag)
	{
		ft_isometric(&start.x, &start.y, start.z, data);
		ft_isometric(&end.x, &end.y, end.z, data);
	}
	get_shift(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	make_step(&x_step, &y_step, &max);
	if (start.z < end.z)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.y >= 0 && (int)start.x >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}

void	bresenham_par(t_dots start, t_dots end, t_fdf *data)
{
	double	x_step;
	double	y_step;
	int		max;

	get_zoom(&start, &end, data);
	ft_parallel(&start.x, &start.y, start.z, data);
	ft_parallel(&end.x, &end.y, end.z, data);
	get_shift(&start, &end, data);
	x_step = end.x - start.x;
	y_step = end.y - start.y;
	make_step(&x_step, &y_step, &max);
	if (start.z < end.z)
		start.color = end.color;
	while ((int)(start.x - end.x) || (int)(start.y - end.y))
	{
		if ((int)start.x < data->scr_x && (int)start.y < data->scr_y
			&& (int)start.y >= 0 && (int)start.x >= 0)
			my_mlx_pixel_put(data, start.x, start.y, start.color);
		start.x += x_step;
		start.y += y_step;
	}
}
