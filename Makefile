########################################################################
### ETNA PROJECT, 2022
### TIC-DVC1/Runner
### File description:
### this makefile is used to compile the project
### you can use make .PHONY to do a clean install or make install clean
########################################################################

CC = gcc
SRC = sources/main.c \
			sources/draw_interface.c \
			sources/init.c \
			sources/input.c \
			sources/stage.c \
			sources/frame.c \
			sources/collision.c \
			sources/audio.c \
			sources/text.c \
			sources/score.c \
			sources/memory.c \
			sources/draw_element.c \
			sources/linked_lists.c \
			sources/stars.c \
			sources/explosion.c \
			sources/player.c \
			sources/meteore.c \
			sources/bullet.c \
			sources/background.c \
			sources/debri.c \
			sources/game_loop.c

NAME = runner
OBJ = $(SRC:%.c=%.o)
CFLAGS += -I headers
CFLAGS += -Wall -Wextra -Werror
RM = rm -f
LDFLAGS += -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer

$(NAME):	$(OBJ)
				$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

all:		$(NAME)

install:    all	

clean:	
				$(RM) $(OBJ)

fclean:		clean
				$(RM) $(NAME)

re: fclean all

.PHONY: all clean
