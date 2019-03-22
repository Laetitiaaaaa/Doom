/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:35:20 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/22 16:36:23 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"
#include "../includes/tga_reader.h"

static void	tga2sur(t_tga *tga, SDL_Surface *surface, t_win *wn)
{
	SDL_Texture *txt;

	SDL_SetRenderDrawColor(wn->rend,0,0,0,0);
	SDL_RenderClear(wn->rend);
//	surface = set_surface(tga);
	surface = SDL_CreateRGBSurfaceWithFormatFrom(tga->pxl,tga->w, tga->h, 32, 4 * tga->w, SDL_PIXELFORMAT_ARGB32);
	txt = SDL_CreateTextureFromSurface(wn->rend, surface);
	SDL_RenderCopy(wn->rend, txt, NULL, NULL);
	SDL_RenderPresent(wn->rend);
	SDL_FreeSurface(surface);
}

void		load_texture(char *path, t_win *wn)
{
	SDL_Surface	*surface;
	t_tga		*tga;

	surface = NULL;
	tga = NULL;
	if (!(tga = (t_tga *)malloc(sizeof(t_tga))))
		stop_exec("Cant malloc tga\n", wn);
	tga_load(tga, path);
	tga2sur(tga, surface, wn);
}

void		initload(t_win **wn)
{
	SDL_PollEvent(&(*wn)->ev);
	printf("Debut load\n");
	load_texture("./texture/icon.tga", *wn);
	SDL_Delay(3000);
	load_texture("./texture/04.tga", *wn);
	SDL_Delay(3000);
	load_texture("./texture/4.tga", *wn);
	SDL_Delay(3000);
	load_texture("./texture/pistol.tga", *wn);
	SDL_Delay(3000);
	load_texture("./texture/color.tga", *wn);
	SDL_Delay(3000);
	printf("Fin load\n");
}
