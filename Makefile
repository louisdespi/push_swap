# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/19 10:33:54 by lode-spi          #+#    #+#              #
#    Updated: 2018/10/04 00:17:22 by lode-spi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
INCLUDES = -Iincludes/ -Iminilibx_macos/
LIB = -Llibft/
CFLAGS = -Wall #-fsanitize=address

SRCPATH = src
BINPATH = bin

CHECKER_SRC = ps_build_list.c \
			  reader.c \
			  swap.c \
			  push.c \
			  rotate.c \
			  is_sorted.c \
			  checker.c \
			  visualizer.c
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
CHECKER_BIN = $(addprefix $(BINPATH)/, $(CHECKER_OBJ))

PUSHSWAP_SRC = push_swap.c \
			   ps_build_list.c \
			   sort.c \
			   sort_helper.c \
			   rotate.c \
			   push.c \
			   swap.c \
			   print_do_action.c \
			   hidden_quicksort.c \
			   qs_helper.c
PUSHSWAP_OBJ = $(PUSHSWAP_SRC:.c=.o)
PUSHSWAP_BIN = $(addprefix $(BINPATH)/, $(PUSHSWAP_OBJ))

all: push_swap checker

#compiler la libft !!

push_swap: $(PUSHSWAP_BIN)
	@$(CC) -o push_swap $(PUSHSWAP_BIN) $(LIB) -lft
	@echo "▶ Building \033[34m$@\033[0m \033[32;1m✓\033[0m"

checker: $(CHECKER_BIN)
	@$(CC) -o checker $(CHECKER_BIN) $(LIB) -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -lft
	@echo "▶ Building \033[34m$@\033[0m \033[32;1m✓\033[0m"

$(BINPATH)/%.o: $(SRCPATH)/%.c
	@$(CC) -o $@ -c $(CFLAGS) $< $(INCLUDES)
	@echo "▶ Generating object file : \033[34m$@\033[0m"

clean:
	@rm -rf ./bin/*.o

fclean: clean
	@rm -rf push_swap
	@rm -rf checker

re : fclean all
