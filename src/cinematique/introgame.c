/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introgame.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:06:27 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:48:49 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	showreverseintrogame(t_win *wn)
{
	t_text *img;

	img = findpostxt(wn, "game", "intro", "239");
	if (img != NULL)
	{
		while (img->before != NULL)
		{
			SDL_RenderCopy(wn->rend, img->txt, NULL, NULL);
			SDL_RenderPresent(wn->rend);
			img = img->before;
			SDL_Delay(30);
		}
	}
}

void	showintrogame(t_win *wn)
{
	t_text *img;

	img = findpostxt(wn, "game", "intro", "180");
	if (img != NULL)
	{
		while (img->next != NULL)
		{
			SDL_RenderCopy(wn->rend, img->txt, NULL, NULL);
			SDL_RenderPresent(wn->rend);
			img = img->next;
			SDL_Delay(30);
		}
	}
}
