/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:05:00 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/22 13:43:04 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	initsdl(t_win **wn)
{
	SDL_Init(SDL_INIT_EVERYTHING) != 0 ? stop_exec("Init Sdl failed\n", *wn) : 0;
	(*wn)->window = SDL_CreateWindow("Doom Nukem", 0, 0, XSCREEN, YSCREEN, SDL_WINDOW_SHOWN);
	(*wn)->window == NULL ? stop_exec("Window error\n", *wn): 0;
	(*wn)->rend = SDL_CreateRenderer((*wn)->window, -1, SDL_RENDERER_ACCELERATED);
	(*wn)->rend == NULL ? stop_exec("Rend error\n", *wn): 0;
	SDL_RenderPresent((*wn)->rend);
}
