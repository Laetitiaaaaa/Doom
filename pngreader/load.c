/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:52:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/10 20:33:05 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void		loadchunk(t_png *file)
{
	unsigned char	chunk[9];
	int				len;

	while (TRUE)
	{
		read(file->fd, chunk, 8) != 8 ? stopload(file) : 0;
		chunk[8] = 0;
		(len = hextoint(&chunk[0], 4)) > 8192 ? stopload(file) : 0;
		printf("Len = %d\n", len);
		printf("str = |%c|%c|%c|%c|\n", chunk[4], chunk[5], chunk[6], chunk[7]);
		if (ft_strcmp((const char*)(&chunk[4]), "PLTE") == 0)
			makechunk(file, len, "PLTE");
		else if (ft_strcmp((const char*)(&chunk[4]), "IDAT") == 0)	
			makechunk(file, len, "IDAT");
		else if (ft_strcmp((const char*)(&chunk[4]), "tEXt") == 0)
			makechunk(file, len, "tEXt");
		else if (ft_strcmp((const char*)(&chunk[4]), "IEND") == 0)
			break;
		else
			(file->fd = lseek(file->fd, len, SEEK_CUR)) == -1 ?
				stopload(file) : 0;
	}
}

void		loadIHDR(t_png *file)
{
	unsigned char	check[25];
	unsigned char	*ptr;

	ptr = NULL;
	read(file->fd, &check, 25) != 25 ? stopload(file) : 0;
	ptr = &(check[0]);
	ptr += 4;
	checkihdr(ptr, file);
	file->sizex = hextoint(ptr + 4, 4);
	file->sizey = hextoint(ptr + 4, 4);
	file->bpp = *(ptr + 1);
	file->typecolor = *(ptr + 1);
	file->compress = *(ptr + 1);
	file->filt = *(ptr + 1);
	file->lacement = *(ptr + 1);
}
