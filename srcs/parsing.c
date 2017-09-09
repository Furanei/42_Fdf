/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:55:01 by mbriffau          #+#    #+#             */
/*   Updated: 2017/09/09 17:35:15 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3d			*saved_map(t_3d *d, int n_line)
{
	if (d->width_map == 0)
	{
		while (d->s[d->width_map] != 0)
			d->width_map++;
	}
	if (!(d->map[n_line] = (int *)malloc(sizeof(int) * d->width_map)))
		return (0);
	d->width_map = 0;
	while (d->s[d->width_map] != 0)
	{
		d->map[n_line][d->width_map] = ft_atoi(d->s[d->width_map]);
		free((char*)d->s[d->width_map]);
		d->width_map++;
	}
	return (d);
}

static inline t_3d	*limit_window(t_3d *d)
{
	d->width_window = (d->width_map + (d->width_map / 3)) * VALUE_VAR_X;
	d->width_window = d->width_window > 2555 ? 2555 : d->width_window;
	d->height_window = (d->height_map + (d->height_map / 2))
	* (VALUE_VAR_Y + VALUE_VAR_Z);
	d->height_window = d->height_window > 1380 ? 1380 : d->height_window;
	return (d);
}

t_3d				*read_map(char *s, t_3d *d)
{
	char	*line;
	int		n_line;
	int		fd;

	n_line = 0;
	if (!s || !(fd = open(s, O_RDONLY)))
		exit(0);
	while (get_next_line(fd, &line) == 1)
	{
		// if (!(ft_isdigit(line[0])))
		// 	exit(0);
		d->height_map++;
		free(line);
	}
	close(fd);
	fd = open(s, O_RDONLY);
	if (!(d->map = (int **)malloc(sizeof(int *) * d->height_map)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
		d->s = ft_strsplit(line, ' ');
		d = saved_map(&*d, n_line);
		free(line);
		n_line++;
	}
	limit_window(&*d);
	free((char**)d->s);
	return (d);
}
