/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:20:52 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/07 16:38:58 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		edit(t_win *wn)
{
	if (wn->oldinterface != wn->interface)
	{
		printf("CINEMATIQUE\n");
		if (wn->oldinterface == LEDITEUR)
			printf("INVERSE CINEMATIQUE\n");
		wn->oldinterface = wn->interface;
	}
	inputeditor(wn);
	SDL_SetRenderDrawColor(wn->rend, 50, 50, 50, 0);
	SDL_RenderClear(wn->rend);
	printeditor(wn);
}
