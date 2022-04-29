/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chpark <chpark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:46:05 by chpark            #+#    #+#             */
/*   Updated: 2022/04/24 23:00:15 by chpark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/fdf.h"

int	main(int argc, char **argv);

int	main(int argc, char **argv)
{
	t_fdf	*data;

	if (argc != 2 || file_check(argv[1]) || check_read(argv[1]))
		return (0);
	data = malloc(sizeof(t_fdf));
	if (!data)
		return (0);
	if (ft_read_file(argv[1], data))
	{
		free(data);
		return (0);
	}
	init_struct(data);
	init_image(data);
	draw(data, data->z_matrix);
	mlx_key_hook(data->win, key_event, data);
	mlx_loop(data->mlx);
	return (0);
}
