# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chmondev <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/22 23:05:08 by chmondev          #+#    #+#              #
#    Updated: 2019/03/31 02:54:21 by chmondev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

LIBFT := libft/

FLAG = -Wall -Wextra -Werror

REMO = rm -f

SRC = filsrc/free.c filsrc/inbounds.c filsrc/valid.c 
SRC += filsrc/fillit.c filsrc/link.c filsrc/aug.c filsrc/filereader.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT)
	gcc $(OBJ) -L. ./libft/libft.a filsrc/main.c -o $(NAME)

%.o: %.c
	gcc $(FLAG) -c $< -o $@

clean:
	@$(REMO) $(OBJ)
	@$(MAKE) -C $(LIBFT) clean

fclean: clean
	@$(REMO) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean

re: fclean all

.PHONY: all, clean, fclean, re
