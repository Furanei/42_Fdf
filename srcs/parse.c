/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 23:21:01 by mbriffau          #+#    #+#             */
/*   Updated: 2017/05/16 23:22:09 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_3d		*malloc_d_map(t_3d *d)
{
	int		i;

	printf("%d\n", d->max_y);
	i = 0;
	if (!(d->map = (int**)malloc(sizeof(int*) * 70)))
		return (0);
	while (i < d->max_y)
	{
		if (!(d->map[i] = (int*)malloc(sizeof(int) * 700)))//pas bon max_x = char
			return (0);
		i++;
	}
	printf("%d\n", d->max_x);
	return (d);
}

t_3d		*parse(t_3d *d)
{
	int		i;
	int		s_size;
	int		x;
	int		y;

	y = 0;
	i = 0;
	d = malloc_d_map(d);
	printf("2\n");
	while (d->s[i] != 0)
	{
		printf("3\n");
		x = 0;
		s_size = 1;
		while (i < d->max_x)
		{
			printf("4\n");
			if (d->s[i] != ' ' && d->s[i + 1] == ' ')
			{
				d->map[y][x] = ft_atoi(ft_strndup((d->s + (i - (s_size - 1))), s_size));
				x++;
			}
			else if (d->s[i] != ' ' && d->s[i + 1] != ' ')
			{
				s_size++;
			}
			i++;
		}
		y++;
	}
	return (d);
}
