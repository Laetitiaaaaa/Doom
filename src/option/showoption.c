/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showoption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 13:45:38 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/31 21:38:13 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		showoption(t_win *wn)
{
	SDL_SetRenderDrawColor(wn->rend, 100, 0, 100, 0);
	SDL_RenderCopy(wn->rend, findtexture(wn, "ajfbkn"), NULL, NULL);
	SDL_RenderClear(wn->rend);
	SDL_RenderPresent(wn->rend);
}
