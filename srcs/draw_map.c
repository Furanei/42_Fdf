/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 04:45:57 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/21 16:24:05 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

static int calculate_z(t_3d *d, int x_line, int y_line, int position)
{
	int z;
	if (position == 1)
	{
		z = d->value_z * d->map[d->y_map + y_line][d->x_map + x_line];
	}
	else
		z = d->value_z * d->map[d->y_map][d->x_map];
	return (z); 
}

static void calculate_the_line(t_3d *d, t_fxy *a, t_fxy *b, int way)
{
	int x_line;
	int y_line;
	
	if (!way)
		ft_error(INFO, "need_option_way(1, 2 or 3)");
	x_line =(way & 1 ? 1 : 0);
	y_line =(way & 2 ? 1 : 0);

	if (!d->angle)
	{a->x = (d->start_x + (d->x_map  * d->value));
		a->y = (d->start_y + (d->y_map  * d->value));
		b->x = (d->start_x + ((d->x_map + x_line)  * d->value));
		b->y = (d->start_y + ((d->y_map + y_line)  * d->value));}

	if (d->angle){
		a->x = d->start_x + ((d->x_map + d->y_map)  * ((d->value/3) * 2));
		a->y =	d->start_y2 + (d->y_map  * (d->value/3)) - (d->x_map  * (d->value/3));
		b->x = a->x + ((y_line + x_line) * ((d->value/3) * 2));
		b->y = a->y + (y_line * (d->value/3)) - (x_line * (d->value/3));
	}
	// a->x += - (d->x_map  * d->angle_x) + (d->y_map * d->angle_y);
	// a->y +=	- (d->x_map  * d->angle_x) + (d->y_map * d->angle_y);
	// b->x += - ((d->x_map + x_line)  * d->angle_x) + ((d->y_map + y_line) * d->angle_y);
	// b->y += - ((d->x_map + x_line)  * d->angle_x) + ((d->y_map + y_line) * d->angle_y);

	// a->x += 0;
	a->y += -(calculate_z(&*d, x_line, y_line, 0));
	// b->x += 0;
	b->y += -(calculate_z(&*d, x_line, y_line, 1));

	a->x +=+ d->decal_x;
	a->y +=+ d->decal_y;
	b->x +=+ d->decal_x;
	b->y +=+ d->decal_y;
}

static void draw_line_loop(t_3d *d, t_fxy *a, t_fxy *b)
{

	while (d->y_map < d->height_map)
	{
		d->x_map = 0;
		while (d->x_map < d->width_map)
		{
			d->color = color_choice(d->color);
			if (d->x_map < d->width_map - 1)
			{
				calculate_the_line(&*d, &*a, &*b, 1);
				draw_line(&*d, &*a, &*b);
			}
			if (d->y_map < d->height_map - 1)
			{
				calculate_the_line(&*d, &*a, &*b, 2);
				draw_line(&*d, &*a, &*b);
			}
			if (d->option_d && (d->x_map < d->width_map - 1) && (d->y_map < d->height_map - 1))
			{
				calculate_the_line(&*d, &*a, &*b, 3);
				draw_line(&*d, &*a, &*b);
			}
			// mlx_pixel_put(d->mlx, d->win, d->start_x + (d->x_map * d->value) + d->decal_x,
			// d->start_y + (d->y_map * d->value) + d->decal_y - (VALUE_VAR_Z +(d->map[d->y_map][d->x_map] * d->value_z)), d->color);
			d->x_map++;
		}
		d->y_map++;
	}	
}

void	draw_map(t_3d *d)
{
	t_fxy	a ;
	t_fxy	b ;
	d->start_x = d->width_window/10;
	d->start_y = d->height_window/10;
	d->start_y2 = d->height_window/2;


	draw_line_loop(&*d, &a, &b);
	d->y_map = 0;
	d->x_map = 0;
}