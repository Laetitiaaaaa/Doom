/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pngreader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 12:35:09 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/10 15:48:02 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		fillfile(t_win *wn, t_png *file)
{
	unsigned char	sign[17]; // (25 - 8) (len + nom)
	(void)wn;
	read(file->fd, &sign, 8);
	read(file->fd, &sign, 17);
	file->sizex = (int)sign[3]; // NEED 4 BYTE
	file->sizey = (int)sign[7];
	file->bpp 	= (int)sign[8];
	file->typecolor = (int)sign[9];
	file->compression = (int)sign[10];
	file->filtrage = (int)sign[11];
	file->entrelacement= (int)sign[12]; // 13 => 17 CRC
//	checkcrc(file, &sign[13]);
}

void		checksignatur(t_win *wn, t_png file)
{
	unsigned char	sign[8];

	(void)wn;
	read(file.fd, &sign, 8);
	sign[0] != 137 ? stop_exec("Not a png\n", wn) : 0;
	sign[1] != 80 ? stop_exec("Not a png\n", wn) : 0;
	sign[2] != 78 ? stop_exec("Not a png\n", wn) : 0;
	sign[3] != 71 ? stop_exec("Not a png\n", wn) : 0;
	sign[4] != 13 ? stop_exec("Not a png\n", wn) : 0;
	sign[5] != 10 ? stop_exec("Not a png\n", wn) : 0;
	sign[6] != 26 ? stop_exec("Not a png\n", wn) : 0;
	sign[7] != 10 ? stop_exec("Not a png\n", wn) : 0;
}

void		filldata(t_png *file)
{
	int				index;
	unsigned char	parse[file->len + 1];

	index = -1;
	read(file->fd, parse, file->len);
	parse[file->len] = 0;
	printf("\n");
	while (++index < file->len)
	{
		printf("%d	", parse[index]);
		index % 8 == 7 ? printf("\n") : 0;
	}
}

void		parsepng(t_win *wn, t_png *file)
{
	unsigned char	check[900];
	int				len;

	!read(file->fd, &check, 8) ? stop_exec("error read\n", wn) : 0;
	len = (int)check[3] + 4; //+ CRC
	check[8] = '\0';
	if (ft_strcmp((const char *)&check[4], "PLTE") == 0)
	{
		printf("Plte\n");
		read(file->fd, &check, len);
		read(file->fd, &check, 8);
		len = (int)check[3];
		check[8] = '\0';
	}
	if (ft_strcmp((const char *)&check[4], "IDAT") == 0)
	{
		file->len = len;
		filldata(file);
	}
	!read(file->fd, &check, 8) ? stop_exec("error read\n", wn) : 0;
	check[8] = '\0';
	if (ft_strcmp(((const char *)&check[4]), "IEND") == 0)
	{
		printf("End\n");
	}
}

void		getpng(t_win *wn, char *path)
{
	t_png	file;

	printf("%s\n", path);
	file.path =  ft_strdup(path);
	if (path == NULL)
		stop_exec("Path png incorrect\n", wn);
	file.fd = open(path, O_RDONLY);
	file.fd == -1 ? stop_exec("Fail open\n", wn): 0;
	checksignatur(wn, file);
	fillfile(wn, &file);	
	parsepng(wn, &file);
}
