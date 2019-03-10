/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainedit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 17:20:52 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/10 19:10:46 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/doom.h"

void		edit(t_win *wn)
{
	inputeditor(wn);
/*	getpng(wn, "./texture/black.png");
	getpng(wn, "./texture/weird2.png");
	getpng(wn, "./texture/solob.png");
	getpng(wn, "./texture/solow.png");
	getpng(wn, "./texture/split.png");
	getpng(wn, "./texture/2x2.png");
	getpng(wn, "./texture/2x2b.png");
*/
	loadpng("./texture/2x2.png");
	stop_exec("THE END\n", wn);
	printeditor(wn);
}
