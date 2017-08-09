/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 15:23:37 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/09 16:37:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"
# include "mlx.h"

int		my_key_funct(int keycode, t_3d *d)
{
	printf("keycode used : %d\n", keycode);
	if (keycode == KEY_ESCAPE)
		exit (0);
	if (keycode == KEY_W)
		d->x--;
	if (keycode == KEY_S)
		d->x++;
	if (keycode == KEY_D)
		d->y++;
	if (keycode == KEY_A)
		d->y--;
	mlx_pixel_put(d->mlx, d->win, 200 + d->y, 200 + d->x, 0xFFFFFF);
	return (0);
}

void	display(t_3d *d)
{
	d->mlx = mlx_init();
	d->win = mlx_new_window(d->mlx, WIDTH_WINDOW, HEIGHT_WINDOW, TITLE_WINDOW);
	draw_map(*&d);
	mlx_key_hook(d->win, my_key_funct, d);
	mlx_loop(d->mlx);
}