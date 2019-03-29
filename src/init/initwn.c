/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:15:15 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 13:18:14 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	initelem(t_win **wn)
{
	t_elem	*new;


	((*wn)->elem = malloc(sizeof(t_elem))) == NULL ? exit(0) : 0;
	(*wn)->elem->name = ft_strdup("Line");
	(*wn)->elem->x1 = 0;
	(*wn)->elem->x2 = 200;
	(*wn)->elem->y1 = 0;
	(*wn)->elem->y2 = 200;
	((*wn)->elem->next = malloc(sizeof(t_elem))) == NULL ? exit(0) : 0;
	(*wn)->elem->next->name = ft_strdup("Rect");
	(*wn)->elem->next->x1 = 200;
	(*wn)->elem->next->y1 = 50;
	(*wn)->elem->next->x2 = 50;
	(*wn)->elem->next->y2 = 50;
	((*wn)->elem->next->next = malloc(sizeof(t_elem))) == NULL ? exit(0) : 0;
	new = (*wn)->elem->next->next;
	new->name = ft_strdup("Rect");
	new->x1 = 200;
	new->y1 = 200;
	new->x2 = 200;
	new->y2 = 200;
	new->next = NULL;
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

static void	initmenu(t_win **wn)
{
	((*wn)->menu = malloc(sizeof(t_menu))) == NULL ? exit(0) : 0;
	(*wn)->menu->choice = 0;
}

void	initwn(t_win **wn)
{
	(*wn)->interface = MENU;
	initmap(wn);
	initelem(wn);
	initmenu(wn);
	(*wn)->state = NULL;
	(*wn)->difficulty = 0;
	(*wn)->debug = 0;
	(*wn)->window = NULL;
	(*wn)->rend = NULL;
	(*wn)->txtnotload = NULL;
}
