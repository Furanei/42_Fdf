/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/20 16:46:32 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/21 02:32:44 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_fxy	rotate_rx(int x, int y, int z, double a)
{
	t_fxy		ro;

	ro.x = x;
	ro.y = (y * cos(a)) - (z * sin(a));
	ro.z = (y * sin(a)) + (z * cos(a));
	return (ro);
}

static t_fxy	rotate_ry(int x, int y, int z, double b)
{
	t_fxy		ro;

	ro.x = (x * cos(b)) + (z * sin(b));
	ro.y = y;
	ro.z = -(x * sin(b)) + (z * cos(b));
	return (ro);
}

static t_fxy	rotate_rz(int x, int y, int z, double c)
{
	t_fxy		ro;

	ro.x = (x * cos(c)) + (y * sin(c));
	ro.y = -(x * sin(c)) + (y * cos(c));
	ro.z = z;
	return (ro);
}

t_fxy			rotate(t_fxy fxy, double a, double b, double c)
{
	fxy = rotate_rx(fxy.x, fxy.y, fxy.z, a);
	fxy = rotate_ry(fxy.x, fxy.y, fxy.z, b);
	fxy = rotate_rz(fxy.x, fxy.y, fxy.z, c);
	return (fxy);
}
