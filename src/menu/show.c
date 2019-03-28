/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:44:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/28 16:53:12 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	showmenu(t_win *wn)
{
	SDL_Rect	dst;

	dst.x = 450;
	dst.y = 400 + (wn->menu->choice * 220);
	dst.w = 50;
	dst.h = 30;
	SDL_SetRenderDrawColor(wn->rend, 0, 0, 0, 0);
	SDL_RenderClear(wn->rend);
	SDL_RenderCopy(wn->rend, findtexture(wn, "menu"), NULL, NULL);
	SDL_RenderCopy(wn->rend, findtexture(wn, "cursor"), NULL, &dst);
	SDL_RenderPresent(wn->rend);
}
