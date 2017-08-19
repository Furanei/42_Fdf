/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/08 16:31:12 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/19 22:55:23 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

static void line_helper(int dx, int dy, int x, int y, t_3d *d)
{
	int i = 0;

	int m = 0;
	int count = 0;
	int cmp = 0;
	i = ft_abs(dx) > ft_abs(dy) ? (ft_abs(dx) / ft_abs(dy)) : (ft_abs(dy) / ft_abs(dx));
		// a = ft_abs(dx) > ft_abs(dy) ? 1 : 0;
		m = ft_abs(dx) > ft_abs(dy) ? (ft_abs(dx) % ft_abs(dy)) : (ft_abs(dy) % ft_abs(dx));
		count = ft_abs(dx) > ft_abs(dy) ? ft_abs(dx) : ft_abs(dy);
		while (count)
		{
			mlx_pixel_put(d->mlx, d->win, x,
			y, (((d->map[d->y][d->x] > 2 && d->map[d->y][d->x + 1] > 2) || (d->map[d->y][d->x] > 2 && d->map[d->y +1][d->x] > 2)) ? WHITE : BLUE));
			if (ft_abs(dx) > ft_abs(dy))
			{
				dx >= 0 ? (x--) : (x++);
				cmp++;
				if (cmp == i)
				{
				dy >= 0 ? (y--) : (y++ );
				m ? (cmp = -1) && m-- : (cmp = 0);
				}
			}
			else
			{
				dy >= 0 ? (y--) : (y++ );
				cmp++;
				if (cmp == i)
				{
				dx >= 0 ? (x--) : (x++);
				m ? (cmp = -1) && m-- : (cmp = 0);
				}
			}
			count--;
		}
}

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
	range[4] & 1 ? line_helper(range[0], range[1], x[1], y[1], d): 0;
	range[4] & 2 ? line_helper(range[2], range[3], x[2], y[2], d): 0;
}

// void    draw_line(t_fdf *d, int x1, int y1, int color)
// {
//     float		dx;
//     float		dy;
//     int			px_count;
//     int			i;

//     if ((x1 < 0 && d->x < 0) || (x1 >= WIDTH || d->x >= WIDTH)
//			|| (y1 < 0 && d->y < 0) || (y1 > HEIGHT && d->y >= HEIGHT))
//         return ;
//     dx = x1 - d->x;
//     dy = y1 - d->y;
//     px_count = ft_max(fabs(dx), fabs(dy));
//     i = 0;
//     while (i < px_count)
//     {
//         pxput(d, d->x + (dx / px_count) * i,
//                 d->y + (dy / px_count) * i, color);
//         i++;
//     }
// }

// void    pxput(t_fdf *d, int x, int y, int color)
// {
//     if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
//         return ;
//     *((int*)d->addr + (x) + (y * d->l_size_4)) = color;
// }
