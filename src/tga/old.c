/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:08:00 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/24 21:16:36 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tga_reader.h"


static void	sym_vert(t_tga *tga)
{
	int		j;
	int		i;
	int 	nb;

	j  = 0;
	i = 0;
	nb = 0;
	while (i < tga->h * 4)
	{
		j = 0;
		while (j < tga->w * 4)
		{
			tga->data[nb] = tga->done[(i * tga->w * 4) + (tga->w * 4) - j];
			j++;
			nb++;
		}
		i++;
	}
}

void	rotatepxl(t_tga *tga)
{
	int				i;
	int				nb;

	nb = 0;
	i = 0;
	tga->done = malloc(sizeof(tga->done) * tga->w * tga->h * 4);
	while (i < (tga->w * tga->h * 4))
	{
		tga->done[(tga->w * tga->h * 4) - i] = tga->data[i];
		i++;
	}
	sym_vert(tga);
}
