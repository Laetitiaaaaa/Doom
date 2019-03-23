/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:08:00 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/23 18:04:11 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/tga_reader.h"
#include "../../includes/doom.h"


void	sym_vert(t_tga *tga)
{
	int		j;
	int		i;
	int 	nb;

	j  = 0;
	i = 0;
	nb = 0;
	while (i < tga->h)
	{
		j = 0;
		while (j < tga->w)
		{
			tga->pxl[nb] = tga->done[(i * tga->w) + tga->w - j];
			j++;
			nb++;
		}
		i++;
	}
	printf("Sym\n");
}

void	rotatepxl(t_tga *tga)
{
	int				i;
	int				nb;

	nb = 0;
	i = 0;
	tga->done = malloc(sizeof(tga->done) * tga->w * tga->h);
	printf("Reverse\n");
	while (i < (tga->w * tga->h))
	{
		tga->done[(tga->w * tga->h) - i] = tga->pxl[i];
		i++;
	}
	printf("Reverse\n");
	sym_vert(tga);
}

int		get_data_tga(t_tga *tga, const char *path)
{
	int		fd;
	struct	stat sts;
	int		i;

	i = 0;
	if ((fd = open(path, O_RDONLY)) == -1)
		return (0);
	if (fstat(fd, &sts) != 0)
		return (0);
	if (!S_ISREG(sts.st_mode))
		return (0);
	if (read_hdr(tga, fd) == 0)
		return (0);
	tga->color_type ? read_cm(tga, fd) : 0;
	read_data(tga, fd);
	close(fd);
	return (1);
}

int		tga_load(t_tga *tga, const char *path)
{
	if (get_data_tga(tga, path) == 0)
	{
		ft_putstr("not a valid file or path\n");
		return (0);
	}
	printf("Rle uncompress\n");
	if (tga->compress >= 8)
		rle_uncompress(tga);
	printf("Rle pxl\n");
	create_pxl(tga);
	printf("rotate\n");
	rotatepxl(tga);
	printf("%s\n", path);
	printf("1 => %d\n", tga->alpha & 0x80);
	printf("2 => %d\n", tga->alpha & 0x40);
	//	int	i = 0;
/*	while (i++ < (tga->w * tga->h) * 4)
	{
		printf("[%d]\t", tga->file[i]);
		i % 8 ==0 ? printf("\n"): 0;
		//printf("[%d,%d,%d,%d]\n", tga->pxl->a, tga->pxl->r, tga->pxl->g, tga->pxl->b);
	}*/
	
	return (0);
}
