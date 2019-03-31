/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:00:01 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/31 21:34:59 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void		loadmenu(t_win **wn)
{
	load_texture("./texture/menu/menu.tga", *wn, "menu");
	load_texture("./texture/menu/cursor.tga", *wn, "cursor");
	showload(wn, 40);
	load_texture("./texture/menuedit.tga", *wn, "menuedit");
	load_texture("./texture/menugame.tga", *wn, "menugame");
	showload(wn, 50);
	load_texture("./texture/transitioneditor.tga", *wn, "transitionedit");
	load_texture("./texture/transitiongame.tga", *wn, "transitiongame");
	load_texture("./texture/transitionoption.tga", *wn, "transitionoption");
	showload(wn, 70);
	load_texture("./texture/option.tga", *wn, "transitionoption");
	showload(wn, 99);
}

void			showload(t_win **wn, int load)
{
	SDL_Rect	loading;

	loading.x = 20;
	loading.y = (YSCREEN / 4) * 3;
	loading.w = (load * XSCREEN / 100) - 40;
	loading.h = 20;
	SDL_RenderCopy((*wn)->rend, (*wn)->loadingscreen, NULL, NULL);
	SDL_RenderCopy((*wn)->rend, (*wn)->loading, NULL, &loading);
	SDL_RenderPresent((*wn)->rend);
}

int				init(t_win **wn)
{
	SDL_Event	ev;

	initwn(wn);
	initsdl(wn);
	SDL_PollEvent(&ev);
	(*wn)->loading = initload2(wn, "./texture/loading.tga");
	(*wn)->loadingscreen = initload2(wn, "./texture/loadingscreen.tga");
	showload(wn, 10);
	(*wn)->txtnotload = initload2(wn, "./texture/failedload.tga");
	showload(wn, 15);
	inittexture(wn);
	showload(wn, 30);
	loadmenu(wn);
	return (1);
}
