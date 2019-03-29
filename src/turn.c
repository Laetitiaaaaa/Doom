/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:12:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 14:30:59 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void	turn(t_win *wn)
{
	Uint8	difftime;
	Uint8	time;

	while (TRUE)
	{
		time = SDL_GetTicks();
		SDL_PollEvent(&(wn->ev));
		wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
		wn->state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n", wn) : 0;
		wn->interface == MENU ? menu(wn) : 0 ;
		wn->interface == GAME ? game(wn) : 0 ;
		wn->interface == EDITEUR ? edit(wn) : 0;
		wn->interface == OPTION ? option(wn) : 0 ;
		difftime = SDL_GetTicks();
		(difftime - time) <  1000 / 60 ? SDL_Delay((1000 / 60) - (difftime - time)) : 0;
	}
}
