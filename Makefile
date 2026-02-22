# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 12:51:14 by haranivo          #+#    #+#              #
#    Updated: 2026/02/23 00:28:58 by haranivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME =  libftprintf.a

SRC =

OBJ = $(SRC:.c=.o)

RM = rm -f

AR = ar src

MAKE = make -C

LIBFT_DIR = libft/

LIBFT_A = $(LIBFT_DIR)/libft.a

all : $(NAME) 

$(NAME) : libft $(OBJ)
	cp $(LIBFT_A) $(NAME)
	$(AR) $(NAME) $(OBJ)

libft:
	$(MAKE) $(LIBFT_DIR) all

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all re clean fclean 
