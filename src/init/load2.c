/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 11:10:40 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/21 17:26:39 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"
#include "../../includes/tga_reader.h"

SDL_Surface      *ui_make_surface(int height, int width)
{
	SDL_Surface     *surface;
	Uint32          color[4];

	color[0] = 0xff;
	color[1] = 0xff00;
	color[2] = 0xff0000;
	color[3] = 0xff000000;
	if (!(surface = SDL_CreateRGBSurface(0, width, height, 32, color[1], color[2], color[3], color[0])))
		return (0);
	return (surface);
}

SDL_PixelFormat		*fill_pxlformat(SDL_PixelFormat *fmt)
{
	fmt->format = SDL_PIXELFORMAT_ARGB8888;
	fmt->palette = NULL;
	fmt->BitsPerPixel = 32;
	fmt->BytesPerPixel = 4;
	fmt->Amask = 0xff000000;
	fmt->Rmask = 0xff0000;
	fmt->Gmask = 0xff00;
	fmt->Bmask = 0xff;
	return (fmt);
}



SDL_Surface        *set_surface(t_tga *tga)
{
	SDL_Surface					*surface;
	SDL_PixelFormat				*fmt;
	Uint32						*pixel;
	int							i;

	i = 0;
	fmt = malloc(sizeof(fmt));
	fill_pxlformat(fmt);
	surface = ui_make_surface(tga->w, tga->h);
	surface->format = fmt;
	surface->w = tga->w;
	surface->h = tga->h;
	surface->pitch = (tga->bitspix >> 3) * tga->w;
	pixel = surface->pixels;
	SDL_LockSurface(surface);
	while (i < (tga->w * tga->h))
	{
		pixel[i] = tga->pxl[i].a << 24;		// BLUE
		pixel[i] += tga->pxl[i].r << 16;	 	//RED
		pixel[i] += tga->pxl[i].g << 8;		//GREEN
		pixel[i] += tga->pxl[i].b;		//ALPHA
		printf("[%d, %d, %d, %d]\t", tga->pxl[i].r, tga->pxl[i].g, tga->pxl[i].b, tga->pxl[i].a);
		printf("[%d, %d, %d, %d]\t", (pixel[i] & 0xff000000) >> 24, (pixel[i] & 0xff0000) >> 16, (pixel[i] & 0xff00) >> 8, pixel[i] & 0xff);
		i++;
	}
	printf("YOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\n");
	SDL_UnlockSurface(surface);
	return (surface);
}
