/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_intro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 09:27:37 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/07 17:18:32 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

static void		load_main(t_win **wn)
{
	char	*name;
	int		img;

	name = ft_strdup("texture/intro/test0001.tga");
	img = 1;
	while (img <= 60)
	{
		(*wn)->tmp = name;
		load_texture(*wn, "main", "intro", ft_itoa(img));
		name = changename(name);
		img++;
	}
}

static void		load_option(t_win **wn)
{
	(void)wn;
}

static void		load_edit(t_win **wn)
{
	(void)wn;
}

static void		load_game(t_win **wn)
{
	(void)wn;
}

void			*load_intro(void	*params)
{
	t_thread	*thd;
	t_win 		*wn;
	int 		value;

	thd = (t_thread *)params;	
	wn = (t_win *)thd->wn;
	value = (int)thd->value;
	value == 0 ? load_main(&wn) : 0;
	value == 1 ? load_option(&wn) : 0;
	value == 2 ? load_edit(&wn) : 0;
	value == 3 ? load_game(&wn) : 0;
	return (0);
}
