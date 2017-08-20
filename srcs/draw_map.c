/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 04:45:57 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/21 00:39:58 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"


// int pixel_calc(t_3d *d, char option, int right, int down)
// {
// 	if (option == 120)
// 		return((d->start_x + (((d->x + right) + (d->y + down))+ d->decal_x * VALUE_VAR_X)));
// 	else if (option == 121)
// 		return (d->start_y + (((d->y + down) - (d->x + right))+d->decal_y * VALUE_VAR_Y)
// 			- (d->map[d->y][(d->x + right)] * ((d->map[d->y][d->x] * VALUE_VAR_Z) + d->value_z)));
// 	else
// 	{
// 		write(1, "error_pixel_calc\n", ft_strlen("error_pixel_calc\n"));
// 		exit(0);
// 	}
// }

static int color_choice(int color)
{
	if (color == WHITE)
		color = YELLOW;
	else if (color == YELLOW)
		color = GREEN;
	else if (color == GREEN)
		color = BLUE;
	else if (color == BLUE)
		color = RED;
	else if (color == RED)
		color = WHITE;
	return (color);
}

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
	a->x = (d->start_x + (d->x_map  * d->value)) + d-> decal_x;
	a->y = ((d->start_y + (d->y_map  * d->value)) - calculate_z(&*d, x_line, y_line, 0)) + d->decal_y;
	b->x = (d->start_x + ((d->x_map + x_line)  * d->value)) + d-> decal_x;
	b->y = ((d->start_y + ((d->y_map + y_line)  * d->value)) - calculate_z(&*d, x_line, y_line, 1)) + d->decal_y;
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
			if ((d->x_map < d->width_map - 1) && (d->y_map < d->height_map - 1))
			{
				calculate_the_line(&*d, &*a, &*b, 3);
				draw_line(&*d, &*a, &*b);
			}
			// 	draw_line(&*d, (d->x_map) * d->value, (d->y + 1) * d->value, d->color);
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


	draw_line_loop(&*d, &a, &b);
	d->y_map = 0;
	d->x_map = 0;
}
