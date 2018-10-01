# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/24 22:11:22 by lode-spi          #+#    #+#              #
#    Updated: 2018/09/25 00:05:47 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCLUDES = -I../includes/
NAME = ft_printf.a
SRC = dispatch.c \
	  ft_printf.c \
	  get_formspec.c \
	  handle_ptr.c \
	  handle_sint.c \
	  handle_string.c \
	  handle_uint.c \
	  handle_wchar.c \
	  imtob.c \
	  ordered_release.c \
	  print_formated.c \
	  uimtob.c wctob.c
LIB = -L../
CFLAGS = -Wall
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)

%.o : %.c
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCLUDES)
	@echo "▶ Generating object file : \033[34m$@\033[0m"

clean:
	@rm -rf *.o

fclean: clean

re : fclean all