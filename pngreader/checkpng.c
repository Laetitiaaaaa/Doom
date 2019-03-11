/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpng.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 17:38:37 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/11 13:46:26 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void		checkprint(t_png *file)
{
	t_chunk	*print;

	print = file->chunk;
	printf("\n============~==========\n");
	printf("Path	: %s\n", file->name);
	printf("Size X	: %d\n", file->sizex);
	printf("Size Y	: %d\n", file->sizey);
	printf("BPP 	: %d\n", file->bpp);
	printf("Color	: %d\n", file->typecolor);
	printf("Compres	: %d\n", file->compress);
	printf("Filtre	: %d\n", file->filt);
	printf("Lace	: %d\n", file->lacement);
	while (print != NULL)
	{
		printf("Len		: %d\n", print->len);
		printf("Chunk	: %s\n", print->name);
		printf("Data	: %s\n", print->data);
		print = print->next;
	}
}

void		checkihdr(unsigned char *head, t_png *file)
{
	head[0] != 'I' || head[1] != 'H' || head[2] != 'D' || head[3] != 'R' ?
		stopload(file) : 0;
}

void		checksignature(t_png *file)
{
	unsigned char	check[8];
	
	read(file->fd, &check, 8) != 8 ? stopload(file) : 0;
	(check[0] != 137 || check[1] != 80 || check[2] != 78
	 || check[3] != 71 || check[4] != 13 || check[5] != 10
	 || check[6] != 26 || check[7] != 10) ? stopload(file) : 0;
}

void		checkpath(t_png *file)
{
	char	check;

	file->fd = open(file->name, O_RDONLY);
	file->fd == -1 ? stopload(file) : 0;
	read(0, &check, 0) == -1 ? stopload(file) : 0;
}
