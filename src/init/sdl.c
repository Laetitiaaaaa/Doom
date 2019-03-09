/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 12:05:00 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/09 11:24:35 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	initsdl(t_win **wn)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	(*wn)->window = SDL_CreateWindow("Doom Nukem", 0, SDL_WINDOWPOS_CENTERED, XSCREEN, YSCREEN, SDL_WINDOW_SHOWN);
	(*wn)->rend = SDL_CreateRenderer((*wn)->window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_RenderPresent((*wn)->rend);
	SDL_UpdateWindowSurface((*wn)->window);
}
