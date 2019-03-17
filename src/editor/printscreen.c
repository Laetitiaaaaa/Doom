/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:07:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/17 16:07:13 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	showline(t_win *wn)
{
	float		i;
	float		j;

	j = wn->map->y;
	SDL_SetRenderDrawColor(wn->rend, 200, 200, 200, 0);
	while (j <= (wn->map->h + wn->map->y + 1) && j < YSCREEN)
	{
		i = wn->map->x;
		while (i <= (wn->map->w + wn->map->x + 1) && i < XSCREEN)
		{
			SDL_RenderDrawLine(wn->rend, i, j, i, (wn->map->h + (wn->map->y < 0 ? wn->map->y : 0)));
			SDL_RenderDrawLine(wn->rend, i, j, (wn->map->w + (wn->map->x < 0 ? wn->map->x : 0)), j);
			i += wn->map->w / 10;
		}
		j += wn->map->h / 10;
	}
}

static void	showmap(t_win *wn)
{
	float	x;
	float	y;

	y = wn->map->y;
	while (y < (wn->map->y + wn->map->h) && y < YSCREEN)
	{
		x = wn->map->x;
		while(x < (wn->map->x + wn->map->w) && x < XSCREEN)
		{
			SDL_SetRenderDrawColor(wn->rend, 10, 10, 10, 0);
			SDL_RenderDrawPoint(wn->rend, x, y);
			x++;
		}
		y++;
	}
}

void		printeditor(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->rend, 50, 50, 50, 0);
	SDL_RenderClear(wn->rend);
	showmap(wn);
	showline(wn);
	SDL_RenderPresent(wn->rend);
}
