/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printscreen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 11:07:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/24 11:58:05 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	showelem(t_win *wn)
{
	t_elem		*curr;
	SDL_Rect	rect;

	curr = wn->elem;
	while (curr != NULL)
	{
		SDL_SetRenderDrawColor(wn->rend, 200, 200, 200, 0);
		if (ft_strcmp(curr->name, "Line") == 0)
		{
			SDL_RenderDrawLine(wn->rend, (curr->x1 * wn->map->size) + wn->map->x, (curr->y1 * wn->map->size) + wn->map->y, (curr->x2 * wn->map->size) + wn->map->x, (curr->y2 * wn->map->size) + wn->map->y);
		}
		else if (ft_strcmp(curr->name, "Rect") == 0)
		{
			rect.x = (curr->x1 * wn->map->size) + wn->map->x;
			rect.y = (curr->y1 * wn->map->size) + wn->map->y;
			rect.h = (curr->x2 * wn->map->size);
			rect.w = (curr->y2 * wn->map->size);
			SDL_RenderDrawRect(wn->rend, &rect);
		}
		if (curr->next == NULL)
			break;
		curr = curr->next;
	}
}

static void	showline2(t_win *wn)
{
	float		i;
	float		j;

	j = wn->map->y;
	if (wn->map->size > 1)
	{
		SDL_SetRenderDrawColor(wn->rend, 50 + (wn->map->size * 20 / 6), 50 + (wn->map->size * 20 / 6), 50 + (wn->map->size * 20 / 6), 0);
		while (j <= (wn->map->h + wn->map->y + 1) && j < YSCREEN)
		{
			i = wn->map->x;
			while (i <= (fabs(wn->map->w) + wn->map->x + 1) && i < XSCREEN)
			{
				SDL_RenderDrawLine(wn->rend, i, j, i, (wn->map->h + (wn->map->y < 0 ? wn->map->y : 0)));
				SDL_RenderDrawLine(wn->rend, i, j, (wn->map->w + (wn->map->x < 0 ? wn->map->x : 0)), j);
				i += wn->map->w / 40;
			}
			j += wn->map->h / 40;
		}
	}
}

static void	showline(t_win *wn)
{
	float		i;
	float		j;

	j = wn->map->y;
	showline2(wn);
	SDL_SetRenderDrawColor(wn->rend, 150, 100, 100, 0);
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
//	float	x;
//	float	y;

//	y = wn->map->y;
/*	while (y < (wn->map->y + wn->map->h) && y < YSCREEN)
	{
		x = wn->map->x;
		while(x < (wn->map->x + wn->map->w) && x < XSCREEN)
		{
			SDL_SetRenderDrawColor(wn->rend, 50, 50, 50, 0);
			SDL_RenderDrawPoint(wn->rend, x, y);
			x++;
		}
		y++;
	}
*/	showline(wn);
	showelem(wn);
}

void		printeditor(t_win *wn)
{
//	SDL_SetRenderDrawColor(wn->rend, 0, 0, 0, 0);
//	SDL_RenderClear(wn->rend);
	SDL_RenderCopy(wn->rend, wn->texture->txt, NULL, NULL);
	showmap(wn);
	SDL_RenderPresent(wn->rend);
}
