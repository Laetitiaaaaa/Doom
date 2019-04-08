/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introedit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:46:22 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 14:11:00 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	introedit(t_win *wn)
{
	int			img;
	char		*name;
	SDL_Texture	*texture;

	name = ft_strdup("texture/intro/edit/test0001.tga");
	img = 1;
	while (img < 60)
	{
		texture = initload2(&wn, name);
		SDL_RenderCopy(wn->rend, texture, NULL, NULL);
		SDL_RenderPresent(wn->rend);
		name = changename(name, 23);
		img += 1;
	}
}

void	showreverseintro(t_win *wn)
{
	t_text	*img;

	img = findpostxt(wn, "editor", "intro", "120");
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

void	showintroedit(t_win *wn)
{
	t_text	*img;

	img = findpostxt(wn, "editor", "intro", "60");
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
