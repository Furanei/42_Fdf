/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 03:48:11 by mbriffau          #+#    #+#             */
/*   Updated: 2017/05/16 23:07:25 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../libft/libft.h"
# include <fcntl.h>
# include "../get_next_line/get_next_line.h"
# include "mlx.h"
# include <stdlib.h>
# include "./keycode.h"
# include "./colors.h"

# define TITLE					"FDF"
# define HEIGHT					1300
# define WIDTH					2000

typedef struct		s_3d
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		max_x;
	int		max_y;
	char	*s;
	int		**map;
}                   t_3d;

t_3d		*parse(t_3d *d);
t_3d		*malloc_d_map(t_3d *d);


#endif

