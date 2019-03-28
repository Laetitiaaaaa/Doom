/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:46:50 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/28 12:33:38 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

SDL_Texture		*findtexture(t_win *wn, const char *name)
{
	t_text	*loaded;

	loaded = wn->texture;
	while (loaded->next != NULL && ft_strcmp(loaded->name, name) != 0)
	{
		loaded = loaded->next;
		if (loaded == NULL || loaded->name == NULL)
			break;
	}
	if (loaded->next == NULL || loaded->name == NULL)
		return (wn->txtnotload);
	return (loaded->txt);
}
