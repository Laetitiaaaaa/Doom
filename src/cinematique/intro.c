/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:46:22 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/05 13:31:16 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

char	*changename(char *name)
{
	int		value;

	value = ft_atoi(&(name[20]));
	value++;
	name[21] = (value % 10) + '0';
	name[20] = (value / 10) + '0';
	return (name);
}

void	intro(t_win *wn)
{
	int			img;
	char		*name;
	SDL_Texture	*texture;

	name = ft_strdup("texture/intro/test0001.tga");
	img = 1;
	while (img < 60)
	{
		texture = initload2(&wn, name);
		SDL_RenderCopy(wn->rend, texture, NULL, NULL);
		SDL_RenderPresent(wn->rend);
		name = changename(name);
		img += 2;
	}
}

void	showintro(t_win *wn)
{
	t_text	*img;

	img = findpostxt(wn, "main", "intro", "1");
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
