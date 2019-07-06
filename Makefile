# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: selly <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/25 15:15:09 by selly             #+#    #+#              #
#    Updated: 2019/07/06 16:44:40 by selly            ###   ########.fr        #
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
	   srcs/start_size.c		\
	   srcs/figures/square.c

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
OBJS_DIR = objs
OBJS_DIR_FIGURES = objs/figures

CC = clang
FLAGS = -Wall -Wextra -Werror
LFLAGS = -L./includes/libft -lft
INCLUDES = -I./includes

LIBFT = includes/libft/libft.a
LFT_DIR = includes/libft

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(FLAGS) $(INCLUDES) $(LFLAGS)

$(LIBFT):
	$(MAKE) -C $(LFT_DIR)

objs/%.o: srcs/%.c | $(OBJS_DIR) $(OBJS_DIR_FIGURES)
	$(CC) -c -o $@ $< $(FLAGS) $(INCLUDES)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR_FIGURES):
	mkdir -p $(OBJS_DIR_FIGURES)

clean:
	$(MAKE) clean -C $(LFT_DIR)
	rm -rf $(OBJS_DIR_FIGURES)
	rm -rf $(OBJS_DIR)

fclean: clean
	$(MAKE) fclean -C $(LFT_DIR)
	rm -rf $(NAME)

re: fclean all
