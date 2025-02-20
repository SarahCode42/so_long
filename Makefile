# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/18 10:41:28 by jbensimo          #+#    #+#              #
#    Updated: 2025/02/19 19:21:27 by jbensimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = so_long.c window.c parsing.c
GNL_SRCS = ./GetNextLine/get_next_line.c ./GetNextLine/get_next_line_utils.c

GNL_OBJS = $(GNL_SRCS:.c=.o)
OBJS = $(SRCS:.c=.o) $(GNL_OBJS)

LIBFT = ./libft/libft.a
FT_PRINTF = ./ft_printf/ft_printf.a

MLX_DIR = ./minilibx-linux
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_INC = -I$(MLX_DIR)
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lbsd # LINUX
# MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit # MAC

all: $(LIBFT) $(FT_PRINTF) $(MLX_LIB) $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_LIB)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) $(FT_PRINTF) $(MLX_FLAGS) -o $(NAME)

%.o: %.c so_long.h
	$(CC) $(FLAGS) $(MLX_INC) -c $< -o $@

$(LIBFT):
	$(MAKE) -C libft

$(FT_PRINTF):
	$(MAKE) -C ft_printf

$(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean
	$(MAKE) -C ft_printf clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean
	$(MAKE) -C ft_printf fclean
	rm -f $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re