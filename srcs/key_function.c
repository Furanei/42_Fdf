/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_function.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:54:30 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/20 01:16:31 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
// #define TEST "./file"

static int key_color(int keycode, int color)
{
	keycode == KEY_PAD_0 ? color = WHITE : 0;
	keycode == KEY_PAD_1 ? color = RED : 0;
	keycode == KEY_PAD_2 ? color = BLUE : 0;
	keycode == KEY_PAD_3 ? color = GREEN : 0;
	keycode == KEY_PAD_4 ? color = POWDER_BLUE : 0;
	keycode == KEY_PAD_5 ? color = INDIGO : 0;
	keycode == KEY_PAD_6 ? color = CORAL : 0;
	keycode == KEY_PAD_7 ? color = IVORY : 0;
	keycode == KEY_PAD_8 ? color = LAVENDER : 0;
	keycode == KEY_PAD_9 ? color = AQUA_MARINE : 0;
	return (color);
}

int		my_key_funct(int keycode, t_3d *d)
{
	// static int fd = 0;

	// if (!(fd = open("./dev/ttys002", O_WRONLY | S_IWUSR)))
	// 	ft_error(INFO, "error_open()");
	// ft_putstr_fd("keycode used : ", fd);
	// ft_putnbr_fd(keycode, fd);
	// ft_putstr_fd("\n", fd);
	printf("keycode used : %d\n", keycode);

	if (keycode == KEY_ESCAPE)
		exit (0);
	if (keycode == KEY_E)
		d->value_z -= 5;
	if (keycode == KEY_Q)
		d->value_z += 5;
	if (keycode == KEY_S)
		d->decal_y += 5;
	if (keycode == KEY_W)
		d->decal_y -= 5;
	if (keycode == KEY_A)
		d->decal_x -= 5;
	if (keycode == KEY_D)
		d->decal_x += 5;
	d->color = key_color(keycode, d->color);
	// mlx_pixel_put(d->mlx, d->win, 200 + d->y, 200 + d->x, 0xFFFFFF);
	mlx_clear_window(d->mlx, d->win);
	draw_map(*&d);
	return (0);
}