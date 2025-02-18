# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 10:03:46 by jbensimo          #+#    #+#              #
#    Updated: 2024/11/25 16:42:05 by jbensimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRCS = ft_isalpha.c ft_memchr.c ft_putchar_fd.c ft_strchr.c ft_strlcpy.c ft_strrchr.c ft_atoi.c ft_isascii.c ft_memcmp.c ft_putendl_fd.c \
		ft_strdup.c ft_strlen.c ft_strtrim.c ft_bzero.c ft_isdigit.c ft_memcpy.c ft_putnbr_fd.c ft_striteri.c ft_strmapi.c \
		ft_substr.c ft_calloc.c ft_isprint.c ft_memmove.c ft_putstr_fd.c ft_strjoin.c ft_strncmp.c ft_tolower.c ft_isalnum.c \
		ft_itoa.c ft_memset.c ft_split.c ft_strlcat.c ft_strnstr.c ft_toupper.c

OBJS = $(SRCS:%.c=%.o)

BONUS_FUNCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS_FUNCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(NAME) $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

.PHONY: re clean fclean all bonus
