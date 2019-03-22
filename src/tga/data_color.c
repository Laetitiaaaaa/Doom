/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga_type_read.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauron <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 11:33:52 by jsauron           #+#    #+#             */
/*   Updated: 2019/03/22 10:55:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tga_reader.h"

void	read_color(t_pixel *pxl, int bits, unsigned char *file, int pos)
{
	if (bits == 32)
	{
		pxl->a = file[pos + 3];
		pxl->r = file[pos + 2];
		pxl->g = file[pos + 1];
		pxl->b = file[pos];
	}
	else if (bits == 24)
	{
		pxl->a = 255;
		pxl->r = file[pos + 0];
		pxl->g = file[pos + 1];
		pxl->b = file[pos + 2];
	}
	else if (bits == 16 || bits == 15)
	{
		if (bits == 16)
			pxl->a = file[pos + 1] & 0x80 ? 255 : 0;
		else
			pxl->a = 255;
		pxl->r = ((file[pos + 1] & 0x7C) >> 2) * 255 / 31;
		pxl->g = ((file[pos + 1] & 0x3) << 2) * 255 / 31;
		pxl->g += ((file[pos] & 0xE0) >> 2) * 255 / 31;
		pxl->b = (file[pos] & 0x1F) * 255 / 31;
	}
	else if (bits  == 8)
	{
		pxl->a = 255;
		pxl->r = file[pos];
		pxl->g = file[pos];
		pxl->b = file[pos];
	}
}
