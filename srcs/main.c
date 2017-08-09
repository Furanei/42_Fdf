/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 23:17:51 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/08 17:06:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int main(int ac, char **av)
{
	t_3d	*data_map;

	data_map = NULL;
	if(ac != 2)
		return (0);
	data_map = t_3d_malloc(&*data_map);
	data_map = read_map(av[1], &*data_map);
	//----------test--------------
	while (data_map->y < data_map->height_map)
	{
		data_map->x = 0;
		while (data_map->x < data_map->width_map)
		{
			ft_putnbr(data_map->map[data_map->y][data_map->x]);
			write(1, " ", 1);
			data_map->x++;
		}
		data_map->y++;
		write(1, "\n", 1);
	}
	data_map->x = 0;
	data_map->y = 0;
	//----------test--------------
	display(&*data_map);
	return (0);
}
