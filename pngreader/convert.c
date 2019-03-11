/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 13:42:22 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/11 13:47:56 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void	convertdata(t_png *file)
{
	int		i;

	while (ft_strcmp(file->chunk->name, "IDAT") != 0)
		file->chunk = file->chunk->next;
	printf("%s\n", file->chunk->name);

	i = 0;
	while (i < file->chunk->len)
	{
		printf("%d\t", file->chunk->data[i]);
		i++;
	}
}
