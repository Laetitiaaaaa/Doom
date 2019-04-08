/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainmenu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 21:02:03 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:50:19 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	menu(t_win *wn)
{
	if (wn->oldinterface != wn->interface)
	{
		if (wn->oldinterface == EDITEUR)
			showreverseintro(wn);
		else if (wn->oldinterface == OPTION)
			showreverseintroedit2(wn);
		else if (wn->oldinterface == GAME)
			showreverseintrogame(wn);
		wn->oldinterface = wn->interface;
	}
	menuinput(wn);
	showmenu(wn);
}
