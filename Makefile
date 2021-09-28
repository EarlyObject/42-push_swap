# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:29:06 by asydykna          #+#    #+#              #
#   Updated: 2021/09/27 14:34:02 by                  ###   ########.fr       # #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_NAME = libft.a

SRC = src/push_swap.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = ./libft

vpath %.c src

vpath %.h include

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	$(CC) -g3 $(CFLAGS) $(SRC) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) #check OBJ instead of SRC

#	cp $(LIBFT_PATH)/libft.a $(NAME)
# $(CC) $(CFLAGS) $(OBJ) -o $(NAME)
#ar rcs $(NAME) ./$(OBJ)

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)

re: fclean all

norm:
	norminette

#.SILENT: $(OBJ)

.PHONY: all clean fclean re norm