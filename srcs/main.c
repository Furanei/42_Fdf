/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 23:17:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/05/16 23:30:45 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>/////

int		read_map(char *s, t_3d *d)//faux
{
	char	*line;
	int		fd;
	int		first;

	first = 1;
	if(!(fd = open(s, O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		if (first)
		{
			d->s = ft_strdup(line);//on fait une copie de la line actuelle de gnl dans la structure
			d->max_x = ft_strlen(d->s);
			free(line);
			first = 0;
		}
		else
		{
			if (ft_strlen(line) != d->max_x)
			{
				ft_putstr("error");
				return (0);
			}
			d->s = ft_strnjoinfree(d->s, line, d->max_x, 'B');// si c'est pas la premiere line 
		}
		d->max_y++;
	}
	printf("%d\n", d->max_y);
	return (1);
}

// int		my_key_funct(int keycode, t_3d *d)
// {
// 	if (keycode == KEY_ESCAPE)
// 		exit (0);
// 	if (keycode == KEY_W)
// 	{
// 		printf("%d\n", keycode);
// 		d->x--;
// 	}
// 	if (keycode == KEY_S)
// 		d->x++;
// 	if (keycode == KEY_D)
// 		d->y++;
// 	if (keycode == KEY_A)
// 		d->y--;
// 	mlx_pixel_put(d->mlx, d->win, 200 + d->y, 200 + d->x, 0xFF00FF);
// 	return (0);
// }

int main(int ac, char **av)
{
	t_3d	*d;

	if (!(d = malloc(sizeof(t_3d))))
		return (0);
	d->x = 0;
	d->y = 0;
	printf("%d\n", d->max_y);
	read_map(av[1], &*d);//stock la map dans d->s
	d = parse(d);
	printf("%s\n", d->s);
	// d->mlx = mlx_init();
	// d->win = mlx_new_window(d->mlx, WIDTH, HEIGHT, TITLE);
	// mlx_pixel_put(d->mlx, d->win, 200, 200, 0x00FFFFFF);
	// mlx_key_hook(d->win, my_key_funct, d);
	// mlx_loop(d->mlx);
	return (0);
}