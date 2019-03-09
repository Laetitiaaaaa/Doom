/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:20:52 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/09 19:55:26 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		edit(t_win *wn)
{
	inputeditor(wn);
	getpng(wn, "./black.png");
	getpng(wn, "./weird2.png");
	getpng(wn, "./solob.png");
	getpng(wn, "./solow.png");
	getpng(wn, "./split.png");
	getpng(wn, "./2x2.png");
	getpng(wn, "./2x2b.png");
	stop_exec("THE END\n", wn);
	printeditor(wn);
}
