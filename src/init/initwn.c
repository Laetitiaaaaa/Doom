/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initwn.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:15:15 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/16 21:19:15 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void	initwn(t_win **wn)
{
	(*wn)->interface = EDITEUR;
	(*wn)->state = NULL;
	(*wn)->difficulty = 0;
	(*wn)->debug = 0;
	(*wn)->window = NULL;
	(*wn)->rend = NULL;
}
