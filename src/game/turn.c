/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:12:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/16 21:40:51 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void	loadpics(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->rend, 50, 50, 50, 255);
	SDL_RenderClear(wn->rend);
	SDL_RenderPresent(wn->rend);
	SDL_UpdateWindowSurface(wn->window);
}

void	turn(t_win *wn)
{
	loadpics(wn);
	while (TRUE)
	{
		loadpics(wn);
		printf("1\n");
		SDL_PollEvent(wn->ev);
		printf("2\n");
		wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
		printf("3\n");
		wn->interface == MENU ? menu(wn) : 0 ;
		wn->interface == GAME ? game(wn) : 0 ;
		wn->interface == EDITEUR ? edit(wn) : 0;
		wn->interface == OPTION ? option(wn) : 0 ;
		printf("5\n");
		wn->state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n", wn) : 0;
		printf("6\n");
	}
}
