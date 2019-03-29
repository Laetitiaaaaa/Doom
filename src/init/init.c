/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:00:01 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 15:38:09 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

int		init(t_win **wn)
{
	SDL_Rect	loading;
	SDL_Event	ev;

	loading.x = 20;
	loading.y = 200;
	loading.h = 20;
	loading.w = (XSCREEN / 4);
	initwn(wn);
	initsdl(wn);
	SDL_PollEvent(&ev);
	SDL_SetRenderDrawColor((*wn)->rend, 100, 100, 100, 0);
	SDL_RenderClear((*wn)->rend);
	(*wn)->loading = initload2(wn, "./texture/loading.tga");
	SDL_RenderCopy((*wn)->rend, (*wn)->loading, NULL, &loading);
	SDL_RenderPresent((*wn)->rend);
	loading.w += (XSCREEN / 4);
	SDL_Delay(3000);
	(*wn)->txtnotload = initload2(wn, "./texture/failedload.tga");
	SDL_SetRenderDrawColor((*wn)->rend, 100, 100, 100, 0);
	SDL_RenderClear((*wn)->rend);
	SDL_RenderCopy((*wn)->rend, (*wn)->loading, NULL, &loading);
	SDL_RenderPresent((*wn)->rend);
	SDL_Delay(3000);
	loading.w += (20 / XSCREEN);
	initload(wn);
	return (1);
}
