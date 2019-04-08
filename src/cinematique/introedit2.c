/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   introedit2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:06:27 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:48:57 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	showreverseintroedit2(t_win *wn)
{
	t_text *img;

	img = findpostxt(wn, "option", "intro", "179");
	showlinkedlist(&wn, "option", "intro");
	if (img != NULL)
	{
		while (img->before != NULL)
		{
			printf("Name => %s\n", img->name);
			SDL_RenderCopy(wn->rend, img->txt, NULL, NULL);
			SDL_RenderPresent(wn->rend);
			img = img->before;
			SDL_Delay(30);
		}
	}
}

void	showintroedit2(t_win *wn)
{
	t_text *img;

	img = findpostxt(wn, "option", "intro", "121");
	showlinkedlist(&wn, "option", "intro");
	if (img != NULL)
	{
		while (img->next != NULL)
		{
			printf("Name => %s\n", img->name);
			SDL_RenderCopy(wn->rend, img->txt, NULL, NULL);
			SDL_RenderPresent(wn->rend);
			img = img->next;
			SDL_Delay(30);
		}
	}
}
