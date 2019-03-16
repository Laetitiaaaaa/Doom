/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:00:01 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/16 19:28:05 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

int		init(t_win **wn)
{
	((*wn) = malloc(sizeof(wn))) == NULL ?stop_exec("Malloc wn failed\n", *wn) : 0;
	initsdl(wn);
	initwn(wn);
	return (1);
}
