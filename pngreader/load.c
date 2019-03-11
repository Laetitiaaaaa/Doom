/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:52:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/11 13:42:16 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void		loadchunk(t_png *file)
{
	unsigned char	chunk[9];
	int				len;

	while (TRUE)
	{
		read(file->fd, chunk, 8);
		chunk[8] = 0;
		(len = strtoint(&chunk[0], 4)) > 8192 ? stopload(file) : 0;
		len += 4;
		if (ft_strcmp((const char*)(&chunk[4]), "PLTE") == 0)
			makechunk(file, len, "PLTE");
		else if (ft_strcmp((const char*)(&chunk[4]), "IDAT") == 0)	
			makechunk(file, len, "IDAT");
		else if (ft_strcmp((const char*)(&chunk[4]), "tEXt") == 0)
			makechunk(file, len, "tEXt");
		else if (ft_strcmp((const char*)(&chunk[4]), "IEND") == 0)
			break;
		else
			(file->fd = lseek(file->fd, len, SEEK_CUR)) == -1 ? stopload(file) : 0;
	}
}

void		loadIHDR(t_png *file)
{
	unsigned char	check[25];
	unsigned char	*ptr;

	ptr = NULL;
	read(file->fd, &check, 25) != 25 ? stopload(file) : 0;
	ptr = &(check[0]);
	ptr = &(check[4]);
	checkihdr(ptr, file);
	ptr = &(check[8]);
	file->sizex = strtoint(ptr, 4);
	ptr = &(check[12]);
	file->sizey = strtoint(ptr, 4);
	ptr = &(check[16]);
	file->bpp = *(ptr);
	ptr = &(check[17]);
	file->typecolor = *(ptr);
	ptr = &(check[18]);
	file->compress = *(ptr);
	ptr = &(check[19]);
	file->filt = *(ptr);
	ptr = &(check[20]);
	file->lacement = *(ptr);
}
