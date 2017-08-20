/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 03:48:11 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/20 23:14:02 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

# include "../get_next_line/get_next_line.h"
// # include "../minilibx_macos/mlx.h"
# include "mlx.h"
# include <stdlib.h>
# include "./keycode.h"
# include "./colors.h"
# include <fcntl.h>
# include <math.h>

#define TERM2 "dev/ttys002"
# define INFO __FILE__, (char *)__FUNCTION__, __LINE__

# define TITLE_WINDOW					"FDF"
# define HEIGHT_WINDOW				1300
# define WIDTH_WINDOW					2000

# define VALUE_VAR_X			30
# define VALUE_VAR_Y			20
# define VALUE_VAR_Z			3
# define VALUE_VAR			10

# define LOG_CLEAR		\033[2K
# define LOG_UP			\033[A
# define LOG_NOCOLOR	\033[0m
# define LOG_BOLD		\033[1m
# define LOG_UNDERLINE	\033[4m
# define LOG_BLINKING	\033[5m
# define LOG_BLACK		\033[1;30m
# define LOG_RED		\033[1;31m
# define LOG_GREEN		\033[1;32m
# define LOG_YELLOW		\033[1;33m
# define LOG_BLUE		\033[1;34m
# define LOG_VIOLET		\033[1;35m
# define LOG_CYAN		\033[1;36m
# define LOG_WHITE		\033[1;37m
typedef struct		s_3d
{
/*
*affichage
*/
	void	*mlx;//used on display
	void	*win;//used on display
	int		y_map;//used on draw_line
	int		x_map;//used on draw_line

	char	**s;//used on saved_map with split
	int		**map;//used
	int		fd;//used saved_map
/*
* MAP
*/
	int		width_window;
	int		height_window;

	int		width_map;//used
	int		height_map;//used
	int		start_x;
	int		start_y;

	int		value;
	int		value_z;
	int		decal_x;
	int		decal_y;
	int color;
/*
*donnee
*/
	int			m;
	char		higher;

	int			var_x;//used on draw_line
	int 		var_y;//used on draw_line
	int			d_x;
	int			d_y;
}                   t_3d;

typedef struct		s_fxy
{
	int		x;
	int		y;
}					t_fxy;

typedef struct  	s_dl
{
	int		d_a;
	int 	*a;
	int		d_b;
	int 	*b;
	int		a1;
	int		a2;
	int		b1;
	int		b2;
	double	m;
	int		pixel;
	double	gauge;
	int		add_a;
	int		add_b;
}					t_dl;

t_3d		*read_map(char *s, t_3d *d);
t_3d		*t_3d_malloc(t_3d *d);
void		display(t_3d *d);
void		draw_map(t_3d *d);
// void		draw_line(t_3d *d);
void    draw_line(t_3d *d, t_fxy *a, t_fxy *b);
t_dl		*t_dl_malloc(t_dl *l);
void		pointer_t_dl(t_3d *d, t_dl *l, t_fxy a, t_fxy b);
int			pixel_calc(t_3d *d, char option, int right, int down);
int			my_key_funct(int keycode, t_3d *d);
void	ft_error(char *file, char *func, int line, char *s);

#endif

