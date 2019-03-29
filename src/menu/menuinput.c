/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menuinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:39:46 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 12:37:58 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	menuinput(t_win *wn)
{
	static Uint8 	*last = NULL;

	if (last == NULL)
		last = malloc(sizeof(Uint8));
	wn->state[SDL_SCANCODE_UP] == 1 && wn->menu->choice > 0 && !last[SDL_SCANCODE_UP] ? wn->menu->choice -= 1 : 0;
	wn->state[SDL_SCANCODE_DOWN] == 1 && wn->menu->choice < 3 && !last[SDL_SCANCODE_DOWN] ? wn->menu->choice += 1 : 0;
	if (wn->state[SDL_SCANCODE_RETURN] == 1 && !last[SDL_SCANCODE_RETURN])
	{
		wn->menu->choice == 0 ? wn->interface = GAME: 0;
		wn->menu->choice == 1 ? wn->interface = EDITEUR: 0;
		wn->menu->choice == 2 ? wn->interface = OPTION: 0;
	}
	setkeyboard(last, wn->state);
}
