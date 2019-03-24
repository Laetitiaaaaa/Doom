/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:20:52 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/24 14:59:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		edit(t_win *wn)
{
	t_text *tmp;

	tmp = wn->texture;
//	inputeditor(wn);
	while (tmp->next != NULL)
	{
		inputeditor(wn);
		printf("%s\n", tmp->name);
		SDL_SetRenderDrawColor(wn->rend, 0, 0, 0, 0);
		SDL_RenderClear(wn->rend);
		SDL_RenderCopy(wn->rend, wn->texture->txt, NULL, NULL);
		SDL_RenderCopy(wn->rend, tmp->txt, NULL, NULL);
		SDL_RenderPresent(wn->rend);
		SDL_Delay(1000);
		if (tmp->next == NULL || tmp == NULL)
			tmp = wn->texture->next->next;
		else
			tmp = tmp->next;
	}
//	printeditor(wn);
}
