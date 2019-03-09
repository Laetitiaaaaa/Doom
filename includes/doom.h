/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:14:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/09 19:08:05 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <stdlib.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libui/SDL2/SDL.h"
# define	XSCREEN 800
# define	YSCREEN 500

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef enum		e_interface
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
	PAUSE,
}					t_interface;

typedef struct		s_png
{
	int				sizex;
	int				sizey;
	int				bpp;
	int				typecolor;
	int				compression;
	int				filtrage;
	int				entrelacement;
	int				len;
	int				fd;
	char			*path;
	char			*data;
}					t_png;

typedef struct		s_win
{
	char			difficulty;
	char			debug;
	char			interface;
	Uint8			*state;
	SDL_Event		ev;
	SDL_Window		*window;
	SDL_Renderer	*rend;
}					t_win;

void				edit(t_win *wn);
void				inputeditor(t_win *wn);
void				printeditor(t_win *wn);
void				getpng(t_win *wn, char *path);
void				checksignatur(t_win *wn, t_png file);

int					parsearg(int argc, char **argv, t_win **wn);
int					init(t_win **wn);
void				initwn(t_win **wn);
void				initsdl(t_win **wn);

void				option(t_win *wn);

void				menu(t_win *wn);

void				turn(t_win *wn);
void				game(t_win *wn);

void				stop_exec(char *msg, t_win *wn);

#endif
