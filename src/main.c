/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 15:27:26 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/16 19:36:56 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/doom.h"

void	stop_exec(char *msg, t_win *wn)
{
	ft_putstr(msg);
	(void)wn;
	exit(0);
}

int		main(int argc, char **argv)
{
	t_win	*wn;

	init(&wn) == 0 ? stop_exec("Init failed\n", wn) : 0;
	parsearg(argc, argv, &wn) == 0 ? stop_exec("", wn) : 0;
	turn(wn);
}
