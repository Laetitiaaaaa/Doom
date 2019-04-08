/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 11:59:53 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:46:29 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	setkeyboard(Uint8 *new, Uint8 *current)
{
	int i;
		
	i = 0;
	while (i < 284)
	{
		new[i] = current[i];
		i++;
	}
}

void	gameinput(t_win *wn)
{
	wn->state[SDL_SCANCODE_ESCAPE] ? wn->interface = MENU : 0;
}
