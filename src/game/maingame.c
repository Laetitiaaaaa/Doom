/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maingame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 21:01:14 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:45:41 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	game(t_win *wn)
{
	if (wn->oldinterface != wn->interface)
	{
		showintrogame(wn);
		wn->oldinterface = wn->interface;
	}
	gameinput(wn);
}
