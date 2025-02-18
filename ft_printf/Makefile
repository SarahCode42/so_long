# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/12 14:55:59 by jbensimo          #+#    #+#              #
#    Updated: 2025/01/31 08:54:02 by jbensimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a

CC = cc
FLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c ft_printf_utils.c
OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
