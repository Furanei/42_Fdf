/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:31:12 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/10 01:37:53 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


void	draw_line(t_3d *d)
{
	int		x[3];
	int		y[3];
	int     range[5];
	int		i = 0;
	int pomme = 0;

	ft_bzero(range, 5);
	x[0] = pixel_calc(d, 'x', 0, 0);
	y[0] = pixel_calc(d, 'y', 0, 0);//depart
	if (!(d->x == (d->width_map - 1)))
	{
		x[1] = pixel_calc(d, 'x', 1, 0);
		y[1] = pixel_calc(d, 'y', 1, 0);// ligne a droite
		range[0] = x[1] - x[0];
		range[1] = y[1] - y[0];
		range[4] += 1;
	}	
	if (!(d->y == (d->height_map - 1)))
	{
		x[2] = pixel_calc(d, 'x', 0, 1);
		y[2] = pixel_calc(d, 'y', 0, 1);// vers le bas
		range[2] = x[2] - x[0];
		range[3] = y[2] - y[0];
		range[4] += 2;
	}
	if (range[4] & 1)
	{
		i = ft_abs(range[0]) > ft_abs(range[1]) ? (ft_abs(range[0]) / ft_abs(range[1])) : (ft_abs(range[1]) / ft_abs(range[0]));
		while (ft_abs(range[0]) || ft_abs(range[1]))
		{
			mlx_pixel_put(d->mlx, d->win, x[1],
			y[1], (d->map[d->y][d->x]) > 2 ? WHITE : RED);
			if (ft_abs(range[0]) > ft_abs(range[1]) && pomme <= i)
			{
				range[0] >= 0 ? (range[0]-- && x[1]--) : (range[0]++ && x[1]++);
				pomme++;
			}
			else
			{
				range[1] >= 0 ? (range[1]-- && y[1]--) : (range[1]++ &&	y[1]++ );
				pomme = 0;
			}
		}
	}
	pomme = 0;
	if (range[4] & 2)
	{
		i = ft_abs(range[2]) > ft_abs(range[3]) ? (ft_abs(range[2]) / ft_abs(range[3])) : (ft_abs(range[3]) / ft_abs(range[2]));
		while (ft_abs(range[2]) || ft_abs(range[3]))
		{
			mlx_pixel_put(d->mlx, d->win, x[2],
			y[2], (d->map[d->y][d->x]) > 2 ? BLUE : GREEN);
			if (ft_abs(range[2]) > ft_abs(range[3]) && pomme <= i)
			{
				range[2] > 0 ? (range[2]-- && x[2]--) : (range[2]++ && x[2]++);
				pomme++;
			}
			else
			{
				range[3] > 0 ? (range[3]-- && y[2]--) : (range[3]++ && y[2]++);
				pomme = 0;
			}
		}	
	}
}