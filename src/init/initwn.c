/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:15:15 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/17 15:23:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	initmap(t_win **wn)
{
	((*wn)->map = malloc(sizeof(t_map))) == NULL ? exit(0) : 0;
	(*wn)->map->x = 0.1;
	(*wn)->map->y = 0.1;
	(*wn)->map->w = 600;
	(*wn)->map->h = 600;
	(*wn)->map->size = 1;
}

void	initwn(t_win **wn)
{
	(*wn)->interface = EDITEUR;
	initmap(wn);
	(*wn)->state = NULL;
	(*wn)->difficulty = 0;
	(*wn)->debug = 0;
	(*wn)->window = NULL;
	(*wn)->rend = NULL;
}
