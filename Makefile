# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 15:15:09 by selly             #+#    #+#              #
#    Updated: 2019/06/25 15:56:54 by selly            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRCS = srcs/additional.c		\
	   srcs/figura.c			\
	   srcs/for_print.c			\
	   srcs/main.c				\
	   srcs/output.c			\
	   srcs/solve.c				\
	   srcs/tetrimino.c			\
	   srcs/tetriminos_type.c	\
	   srcs/start_size.c

FLAGS = -Wall -Wextra -Werror

LFT = cd includes/libft
BACK = cd ../..

all: $(NAME)

$(NAME):
	$(LFT) ; make all ; $(BACK)
	gcc -o $(NAME) $(FLAGS) $(SRCS) -I/includes -L./includes/libft -lft

clean:
	$(LFT) ; make clean ; $(BACK)

fclean: clean
	rm -rf $(NAME)
	$(LFT) ; make fclean ; $(BACK)

re: fclean all
