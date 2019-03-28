/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menuinput.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 16:39:46 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/28 18:10:21 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	menuinput(t_win *wn)
{
	static Uint8 	*last = NULL;

	wn->state[SDL_SCANCODE_UP] == 1 && wn->menu->choice < 3 && last[SDL_SCANCODE_UP] == 0 ? wn->menu->choice += 1 : 0;
	wn->state[SDL_SCANCODE_DOWN] == 1 && wn->menu->choice > 0 && last[SDL_SCANCODE_DOWN] == 0 ? wn->menu->choice -= 1 : 0;
	last = wn->state;
}
