/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 04:45:57 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/20 01:04:14 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


int pixel_calc(t_3d *d, char option, int right, int down)
{
	if (option == 120)
		return((d->start_x + (((d->x + right) + (d->y + down))+ d->decal_x * VALUE_VAR_X)));
	else if (option == 121)
		return (d->start_y + (((d->y + down) - (d->x + right))+d->decal_y * VALUE_VAR_Y)
			- (d->map[d->y][(d->x + right)] * ((d->map[d->y][d->x] * VALUE_VAR_Z) + d->value_z)));
	else
	{
		write(1, "error_pixel_calc\n", ft_strlen("error_pixel_calc\n"));
		exit(0);
	}
}

void	draw_map(t_3d *d)
{
	d->start_x = d->width_window/10;
	d->start_y = d->height_window/10;

	while (d->y < d->height_map)
	{
		d->x = 0;
		while (d->x < d->width_map)
		{
			// draw_line(&*d);
			// mlx_pixel_put(d->mlx, d->win, pixel_calc(d, 'x', 0, 0),
			// pixel_calc(d, 'y', 0, 0), WHITE);
			mlx_pixel_put(d->mlx, d->win, d->start_x + (d->x * VALUE_VAR_X) + d->decal_x,
			d->start_y + (d->y * VALUE_VAR_Y) + d->decal_y - (VALUE_VAR_Z +(d->map[d->y][d->x] * d->value_z)), d->color);
			d->x++;
		}
		d->y++;
	}
	d->y = 0;
	d->x = 0;
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
