/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainoption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 21:03:30 by lomasse           #+#    #+#             */
/*   Updated: 2019/04/08 16:43:58 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	option(t_win *wn)
{
	if (wn->oldinterface != wn->interface)
	{
		showintroedit2(wn);
		wn->oldinterface = wn->interface;
	}
	optioninput(wn);
	showoption(wn);
}
