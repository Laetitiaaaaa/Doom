/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doom.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomasse <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 16:14:06 by lomasse           #+#    #+#             */
/*   Updated: 2019/03/29 14:27:56 by lomasse          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOM_H
# define DOOM_H

# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include "../libui/SDL2/SDL.h"

# define	XSCREEN 1500
# define	YSCREEN 1200

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef enum		e_interface
{
	MENU,
	GAME,
	MGAME,
	LGAME,
	RGAME,
	EDITEUR,
	MEDITEUR,
	LEDITEUR,
	NEDITEUR,
	REDITEUR,
	OPTION,
	BOPTION,
	KEYOPTION,
	LOADING,
	PAUSE,
}					t_interface;

typedef struct		s_elem
{
	char			*name;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				*pos;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_map
{
	float			w;
	float			h;
	float			x;
	float			y;
	float			size;
}					t_map;

typedef struct		s_text
{
	char			*name;
	SDL_Texture		*txt;
	struct s_text	*next;
}					t_text;

typedef struct		s_menu
{
	int				choice;
}					t_menu;

typedef struct		s_win
{
	char			difficulty;
	char			debug;
	char			interface;
	Uint8			*state;
	SDL_Event		ev;
	SDL_Window		*window;
	SDL_Renderer	*rend;
	t_text			*texture;
	SDL_Texture		*txtnotload;
	SDL_Texture		*loading;
	t_map			*map;
	t_elem			*elem;
	t_menu			*menu;
}					t_win;

void				edit(t_win *wn);
void				inputeditor(t_win *wn);
void				printeditor(t_win *wn);

int					parsearg(int argc, char **argv, t_win **wn);
int					init(t_win **wn);
void				initwn(t_win **wn);
void				initsdl(t_win **wn);
int					load_texture(char *path, t_win *wn, char *name);
SDL_Texture			*initload2(t_win **wn, const char *path);
void				initload(t_win **wn);
SDL_Texture			*findtexture(t_win *wn, const char *path);

void				option(t_win *wn);

void				menu(t_win *wn);
void				menuinput(t_win *wn);
void				showmenu(t_win *wn);

void				turn(t_win *wn);
void				game(t_win *wn);
void				setkeyboard(Uint8 *new, Uint8 *current);

void				stop_exec(char *msg, t_win *wn);

#endif
