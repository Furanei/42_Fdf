/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 20:55:01 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/09 16:48:37 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_3d		*saved_map(t_3d *d, int n_line)
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

t_3d		*read_map(char *s, t_3d *d)
{
	char	*line;
	int		n_line;
	int		fd;

	n_line = 0;
	if(!(fd = open(s, O_RDONLY)))
		return (0);
	while (get_next_line(fd, &line) == 1)
	{
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
	free((char**)d->s);
	return (d);
}