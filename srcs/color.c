/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbriffau <mbriffau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/19 18:58:48 by mbriffau          #+#    #+#             */
/*   Updated: 2017/08/19 19:09:07 by mbriffau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/fdf.h"

int		color(int value_z, int index)
{
	if (value_z > index)
		return (RED);
	else
		return (WHITE);
}