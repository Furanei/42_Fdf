/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/01 04:25:10 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/19 23:02:27 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_3d	*t_3d_malloc(t_3d *d)
{
	if (!(d = malloc(sizeof(t_3d))))
		return (0);
	d->x = 0;
	d->y = 0;
	d->height_map = 0;
	d->width_map = 0;
	d->decal_x = 0;
	d->decal_y = 0;
	d->value_z= 0;
	d->color = WHITE;
	return (d);
}

t_dl	*t_dl_malloc(t_dl *l)
{
	if (!(l = (t_dl *)malloc(sizeof(t_dl))))
		return (0);
	return (l);
}
