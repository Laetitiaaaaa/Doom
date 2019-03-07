/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:14:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/07 18:30:44 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <stdlib.h>
# include "../libft/libft.h"

typedef enum	e_bool
{
	FALSE = 0,
	TRUE = 1,
}				t_bool;

typedef enum	e_interface
{
	MENU,
	GAME,
	LGAME,
	RGAME,
	EDITEUR,
	LEDITEUR,
	TEDITEUR,
	REDITEUR,
	OPTION,
	COPTION,
	TOPTION,
	LOADING,
}				t_interface;

typedef struct	s_win
{
	char		difficulty;
	char		debug;
	char		interface;
}				t_win;

void			edit(t_win *wn);

int				parsearg(int argc, char **argv, t_win **wn);
int				init(t_win **wn);
void			initwn(t_win **wn);

void			turn(t_win *wn);

void			stop_exec(char *msg, t_win *wn);

#endif
