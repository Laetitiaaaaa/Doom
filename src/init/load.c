/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:35:20 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/24 21:18:52 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"
#include "../includes/tga_reader.h"

static int	storetxt(t_win *wn, SDL_Texture *txt, char *name)
{
	t_text		*tmp;

	tmp = wn->texture;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->name = ft_strdup(name);
	tmp->txt = txt;
	(tmp->next = (t_text*)malloc(sizeof(t_text))) == NULL ? stop_exec("Malloc failed\n", wn): 0;
	tmp->next->next = NULL;
	return (0);
}

static int	tga2sur(t_tga *tga, SDL_Surface *surface, t_win *wn, char *name)
{
	SDL_Texture *txt;

//	SDL_SetRenderDrawColor(wn->rend, 0, 0, 0, 0);
//	SDL_RenderClear(wn->rend);
	if (tga->data == NULL)
		printf("data == null\n");
	surface = SDL_CreateRGBSurfaceWithFormatFrom(tga->data, tga->w, tga->h, 32, 4 * tga->w, SDL_PIXELFORMAT_ARGB32);
	txt = SDL_CreateTextureFromSurface(wn->rend, surface);
	storetxt(wn, txt, name);
	SDL_RenderCopy(wn->rend, txt, NULL, NULL);
	SDL_RenderPresent(wn->rend);
	SDL_FreeSurface(surface);
	return (0);
}

int			load_texture(char *path, t_win *wn, char *name)
{
	SDL_Surface	*surface;
	t_tga		*tga;

	surface = NULL;
	tga = NULL;
	if (!(tga = (t_tga *)malloc(sizeof(t_tga))))
		stop_exec("Cant malloc tga\n", wn);
	if ((tga = load_tga(path)) == NULL)
	{
		free(tga);
		return (1);
	}
	tga2sur(tga, surface, wn, name);
	return (0);
}

void		inittexture(t_win **wn)
{
	(((*wn)->texture = (t_text*)malloc(sizeof(t_text))) == NULL ? stop_exec("Cant init texture\n", *wn) : 0);
	(*wn)->texture->next = NULL;
}

void		initload(t_win **wn)
{
	inittexture(wn);
	SDL_PollEvent(&(*wn)->ev);
	printf("Debut load\n");
	load_texture("./texture/icon.tga", *wn, "32");
	load_texture("./texture/bg2-2.tga", *wn, "32");
//	load_texture("./texture/noodle.tga", *wn, "32");
//	load_texture("./texture/noodlenc.tga", *wn, "32");
	printf("DONE\n");
	//load_texture("./texture/test24c.tga", *wn, "24");
	//load_texture("./texture/test16c.tga", *wn, "16");
	printf("Fin load\n");
}
