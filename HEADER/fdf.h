/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaprk <chaprk@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 14:47:54 by chaprk            #+#    #+#             */
/*   Updated: 2022/04/24 22:59:59 by chaprk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <math.h>
# include <stdio.h>

# define BUFFER_SIZE 42

# define WIDTH			1800
# define HEIGHT			1000

# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124
# define ESC			53
# define ZOOM_UP		24
# define ZOOM_DOWN		27
# define ANGLE_COS_DOWN	1
# define ANGLE_COS_UP	0
# define ANGLE_SIN_DOWN	2
# define ANGLE_SIN_UP	3
# define Z_UP			13
# define Z_DOWN			12
# define ISO_ON			18
# define ISO_OFF		19
# define PAR			20
# define RESET			48

typedef struct s_dots
{
	double	x;
	double	y;
	int		z;
	int		color;

}	t_dots;

typedef struct s_fdf
{
	int		width;
	int		height;
	t_dots	**z_matrix;
	int		zoom;
	double	angle_cos;
	double	angle_sin;
	double	z_scale;
	int		flag;
	int		shift_x;
	int		shift_y;
	int		scr_x;
	int		scr_y;

	int		bits_per_pixel;
	int		line_len;
	int		endian;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
}	t_fdf;

/*
** 00_main.c
*/

int		main(int argc, char **argv);

/*
** 01_check.c
*/

int		file_check(char *file_name);
int		check_read(char *file_name);

/*
** 02_init.c
*/

void	init_struct(t_fdf *data);
void	init_image(t_fdf *data);
void	ft_isometric(double *x, double *y, int z, t_fdf *data);
void	ft_parallel(double *x, double *y, int z, t_fdf *data);
void	make_step(double *x_step, double *y_step, int *max);

/*
** 03_parse.c
*/

int		ft_read_file(char *file, t_fdf *data);
int		ft_get_height(char *file);
int		ft_get_width(char *file);
int		init_matrix(t_fdf *data);
void	fill_matrix(t_dots *z_matrix, char *line, int y);

/*
** 04_parse_utils.c
*/

int		check_color(char *str);
int		hex_to_dec(char *hex, int base);

/*
** 05_draw.c
*/

void	draw(t_fdf *data, t_dots **z_matrix);
void	print_to_img(t_fdf *data, t_dots **z_matrix);
void	print_menu(t_fdf *data);
void	*ft_memset(void *s, int c, size_t n);

/*
** 06_draw_utils.c
*/

void	get_shift(t_dots *start, t_dots *end, t_fdf *data);
void	get_zoom(t_dots *start, t_dots *end, t_fdf *data);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	get_color(t_dots *z_matrix, char *z);
void	free_string(char **str);

/*
** 07_key_hook.c
*/

int		key_event(int key, t_fdf *data);
int		move(int key, t_fdf *data);
int		zoom(int key, t_fdf *data);
int		angle(int key, t_fdf *data);
int		z_scale(int key, t_fdf *data);

/*
** 08_utils1.c
*/

int		ft_atoi(char *str);
void	ft_bzero(void *s, size_t n);
void	ft_free_data_struct(t_fdf *data);
double	ft_max(double a, double b);
void	free_matrix(t_dots **z_matrix, int length);

/*
** 09_utils2.c
*/

char	**ft_split(char *s, char c);
void	*ft_calloc(size_t count, size_t size);

char	*get_next_line(int fd);
char	*ft_read_left_line(int fd, char *left_line);
char	*ft_get_line(char *left_line);
char	*ft_new_left_line(char *left_line);
size_t	ft_strlen(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_line, char *buff);

/*
** 10_utils3.c
*/

void	check_flag(t_dots start, t_dots end, t_fdf *data);
void	bresenham_iso(t_dots start, t_dots end, t_fdf *data);
void	bresenham_par(t_dots start, t_dots end, t_fdf *data);
#endif
