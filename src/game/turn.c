/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:12:44 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/22 09:42:06 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	turn(t_win *wn)
{
	initload(&wn);
	while (TRUE)
	{
		printf("A\n");
		SDL_PollEvent(&(wn->ev));
		printf("B\n");	
		wn->state = (Uint8*)SDL_GetKeyboardState(NULL);
		wn->state[SDL_SCANCODE_ESCAPE] ? stop_exec("Escape\n", wn) : 0;
		wn->interface == MENU ? menu(wn) : 0 ;
		wn->interface == GAME ? game(wn) : 0 ;
		wn->interface == EDITEUR ? edit(wn) : 0;
		wn->interface == OPTION ? option(wn) : 0 ;
	}
}
