/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:10:40 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 14:31:20 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"
#include "../../includes/tga_reader.h"

SDL_Texture	*initload2(t_win **wn, const char *path)
{
	t_tga		*tga;
	SDL_Surface	*surface;
	SDL_Texture	*txt;

	txt = NULL;
	if ((tga = load_tga(path)) == NULL)
	{
		free_tga(tga);
		stop_exec("Fail to load texture", *wn);
	}
	else
	{
		surface = SDL_CreateRGBSurfaceWithFormatFrom(tga->data, tga->w, tga->h, 32, 4 * tga->w, SDL_PIXELFORMAT_ARGB32);
		txt = SDL_CreateTextureFromSurface((*wn)->rend, surface);
	}
	return (txt);
}
