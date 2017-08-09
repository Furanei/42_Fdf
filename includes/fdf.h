/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 03:48:11 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/09 19:21:07 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"

# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include "./keycode.h"
# include "./colors.h"
# include <fcntl.h>
# include <math.h>

# define TITLE_WINDOW					"FDF"
# define HEIGHT_WINDOW				1300
# define WIDTH_WINDOW					2000

# define VALUE_VAR_X			30
# define VALUE_VAR_Y			20

typedef struct		s_3d
{
/*
*affichage
*/
	void	*mlx;//used on display
	void	*win;//used on display
	int		y;//used on draw_line
	int		x;//used on draw_line

	char	**s;//used on saved_map with split
	int		**map;//used
	int		fd;//used saved_map
/*
* MAP
*/
	int		width_map;//used
	int		height_map;//used
	int		start_x;
	int		start_y;
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
void		draw_line(t_3d *d);
t_dl		*t_dl_malloc(t_dl *l);
void		pointer_t_dl(t_3d *d, t_dl *l, t_fxy a, t_fxy b);
int			ft_abs(int n);
int pixel_calc(t_3d *d, char option, int right, int down);

#endif

