##
## EPITECH PROJECT, 2019
## dante
## File description:
## Makefile
##

SRC     =	src/*

OBJ     =       $(SRC:.c=.o)

CC	=	gcc -I./include -g3 -O3

NAME    =       ai

FLAG	=	-W -Wall -Werror -Wextra -pedantic -g3

all:    $(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ)

clean:
	rm -f $(shell find $(SOURCEDIR) -name '*.o')
	rm -f $(shell find $(SOURCEDIR) -name '*~')
	rm -f $(shell find $(SOURCEDIR) -name '*#')
	rm -f vgcore*

fclean: clean
	rm -f $(NAME)

re:     fclean all

.PHONY: all clean fclean re
