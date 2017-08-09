/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:31:12 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/09 19:40:45 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


void	draw_line(t_3d *d)
{
	int		x[3];
	int		y[3];
	int     range[5];

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
		while ((range[0] && range[1]))
		{	
			// if (x[0] == x[1] || y[0] == y[0])
			// 	break;
			mlx_pixel_put(d->mlx, d->win, x[1],
			y[1], (d->map[d->y][d->x]) > 2 ? WHITE : RED);
			if (ft_abs(range[0]) > ft_abs(range[1]))
			{
				if (range[0] >= 0)
				{
					range[0]--;
					x[1]--;
				}
				else
				{
					range[0]++;
					x[1]++;
				}
			}
			else
			{
				if (range[1] >= 0)
				{
					range[1]--;
					y[1]--;
				}
				else
				{
					range[1]++;
					y[1]++;
				}
			}
		}
	}
	if (range[4] & 2)
	{
		while ((range[2] && range[3]))
		{
			mlx_pixel_put(d->mlx, d->win, x[2],
			y[2], (d->map[d->y][d->x]) > 2 ? BLUE : GREEN);
		if (ft_abs(range[2]) > ft_abs(range[3]))
			range[2] ? (range[2]-- && x[2]--) : (range[2]++ && x[2]++);
		else
			range[3] ? (range[3]-- && y[2]--) : (range[3]++ && y[2]++);	
		}
	}
}