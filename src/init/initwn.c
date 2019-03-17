/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:15:15 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/17 17:46:14 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	initelem(t_win **wn)
{
	((*wn)->elem = malloc(sizeof(t_elem))) == NULL ? exit(0) : 0;
	(*wn)->elem->name = ft_strdup("Line");
	(*wn)->elem->x1 = 0;
	(*wn)->elem->x2 = 200;
	(*wn)->elem->y1 = 0;
	(*wn)->elem->y2 = 200;
	((*wn)->elem->next = malloc(sizeof(t_elem))) == NULL ? exit(0) : 0;
	(*wn)->elem->next->name = ft_strdup("Rect");
	(*wn)->elem->next->x1 = 25;
	(*wn)->elem->next->y1 = 10;
	(*wn)->elem->next->x2 = 30;
	(*wn)->elem->next->y2 = 200;
	(*wn)->elem->next->next = NULL;
}

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
	initelem(wn);
	(*wn)->state = NULL;
	(*wn)->difficulty = 0;
	(*wn)->debug = 0;
	(*wn)->window = NULL;
	(*wn)->rend = NULL;
}
