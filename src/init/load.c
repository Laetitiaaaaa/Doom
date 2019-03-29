/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 13:35:20 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 15:40:49 by lomasse          ###   ########.fr       */
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

	if (tga->data == NULL)
		printf("data == null\n");
	surface = SDL_CreateRGBSurfaceWithFormatFrom(tga->data, tga->w, tga->h, 32, 4 * (tga->w), SDL_PIXELFORMAT_ARGB32);
	txt = SDL_CreateTextureFromSurface(wn->rend, surface);
	storetxt(wn, txt, name);
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
		free_tga(tga);
		return (1);
	}
	tga2sur(tga, surface, wn, name);
	return (0);
}

void		inittexture(t_win **wn)
{
	(((*wn)->texture = (t_text*)malloc(sizeof(t_text))) == NULL ? stop_exec("Cant init texture\n", *wn) : 0);
	(*wn)->texture->next = NULL;
	(*wn)->texture->name = NULL;
}

void		initload(t_win **wn)
{
	inittexture(wn);
	SDL_PollEvent(&(*wn)->ev);
	load_texture("./texture/menu/menu.tga", *wn, "menu");
	load_texture("./texture/menu/cursor.tga", *wn, "cursor");
}
