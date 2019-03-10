/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newchunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 18:21:22 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/10 19:26:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void	makechunk(t_png *file, int len, char *chunk)
{
	t_chunk			*plte;
	unsigned char	check[len + 1];

	plte = NULL;
	*plte = newchunk(file);
	plte->name = ft_strdup(chunk);
	plte->len = len;
	if (len != 0)
	{
		read(file->fd, &check, len) != len ? stopload(file) : 0;
		check[len] = 0;
		plte->data = (unsigned char *)ft_strdup((const char *)check);
	}
}

t_chunk	newchunk(t_png *file)
{
	t_chunk *ptr;

	ptr = file->chunk;
	while (ptr->next != NULL)
		ptr = ptr->next;
	(ptr->next = ft_memalloc(sizeof(t_png))) == NULL ? stopload(file) : 0;
	ptr = ptr->next;
	ptr->next = NULL;
	return (*ptr);
}
