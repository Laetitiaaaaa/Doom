/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_data_pxl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 12:27:45 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/22 10:47:58 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga_reader.h"

void	fill_pxl(t_tga *tga, int i, int mode)
{
	int		pos;

	if (mode == 1)
	{
		pos = i * (tga->bits_cm >> 3) + tga->len_cm + 2;
		read_color(&tga->cm[i], tga->bits_cm, tga->colormap, pos);
	}
	else
	{
		pos = (i * (tga->bitspix >> 3)) + tga->len_cm - 1;
		read_color(&tga->pxl[i], tga->bitspix, tga->file, pos);
	}
}

void	fill_data(t_tga *tga, int mode)
{
	int		i;
	int		limit;

	i = 0;
	limit = (mode == 1) ? tga->len_cm : (tga->w * tga->h);
//	printf("%d\t%d\n", tga->file[tga->len_cm], tga->file[tga->len_cm + 1]);
	while (i < limit)
	{
		fill_pxl(tga, i, mode);
		i++;
	}
}

void	create_pxl(t_tga *tga)
{
	tga->pxl = malloc(sizeof(t_pixel) * (tga->w * tga->h));
	if (tga->color_type)
	{
		tga->cm = malloc(sizeof(t_pixel) * tga->len_cm);
		fill_data(tga, 1);
		range_pxl(tga);
	}
	else
		fill_data(tga, 2);
}
