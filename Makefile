# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haranivo <haranivo@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/13 12:51:14 by haranivo          #+#    #+#              #
#    Updated: 2026/02/19 16:52:30 by haranivo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME =  libftprintf.a

SRC =

OBJ = $(SRC:.c=.o)

RM = rm -f

AR = ar src

all : $(NAME) 

# libft.a: libft
# 	./libft/make all

$(NAME) : $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)
	
re: fclean all

.PHONY: all re clean fclean 
