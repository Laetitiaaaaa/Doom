# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lomasse <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:24:01 by lomasse           #+#    #+#              #
#    Updated: 2019/03/11 13:43:47 by lomasse          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= doom

BASE_SRC		= main.c

INIT_SRC		= init.c										\
				  parse.c										\
				  initwn.c										\
				  sdl.c

GAME_SRC		= turn.c										\
				  maingame.c

MENU_SRC		= mainmenu.c

EDITOR_SRC		= mainedit.c									\
				  printscreen.c 								\
				  input.c

OPTION_SRC		= mainoption.c									\

PNG_SRC			= load.c										\
				  checkpng.c									\
				  newchunk.c									\
				  convert.c										\
				  newpngreader.c

PNG_PATH		= ./pngreader/

BASE_PATH		= ./src/

GAME_PATH		= ./src/game/

EDITOR_PATH		= ./src/editor/

INIT_PATH		= ./src/init/

MENU_PATH		= ./src/menu/

OPTION_PATH		= ./src/option/

BASE_PATH		= ./src/

OBJ_PATH		= ./OBJ

SRCS			=	$(addprefix $(BASE_PATH), $(BASE_SRC))			\
					$(addprefix $(GAME_PATH), $(GAME_SRC))			\
					$(addprefix $(INIT_PATH), $(INIT_SRC))			\
					$(addprefix $(MENU_PATH), $(MENU_SRC))			\
					$(addprefix $(OPTION_PATH), $(OPTION_SRC))		\
					$(addprefix $(EDITOR_PATH), $(EDITOR_SRC))		\
					$(addprefix $(PNG_PATH), $(PNG_SRC))			\

INC				= -I ./includes

LIB				= -L ./libft/

GCC				= gcc

FLAGS			= -Wall -Wextra -Werror

OBJS			= $(addprefix $(OBJ), $(SRCS:.c=.o))

MAKELIB			= make re -C libft/

LIBFT			= -Llibft/ -lft

LIBMLX			= -L ./libui -lSDL2 -lSDL2_image -lSDL2_mixer

FRAME			= -framework OpenGL -framework AppKit

RANDOM			= $$

%.o: %.c ./includes/doom.h
	@$(GCC) $(INC) -o $@ -c $< $(FLAGS)

$(NAME): $(OBJS)
	@$(GCC) -o $@ `sdl2-config --cflags --libs` $(OBJS) $(LIB) $(LIBFT) $(LIBMLX) $(FRAME) $(FLAGS)

all : $(NAME)

cake : $(NAME)
	@clear ; cat texture/portal.txt ; echo "\n\n" ; cat texture/cake.txt ;

clean :
	@rm -rf $(OBJS) ; echo "Obj Cleaned"

fclean : clean
	@rm -rf $(NAME) ; echo "Exec Cleaned"

re : fclean all

relibft : 
	$(MAKELIB)

.PHONY : all clean fclean re
