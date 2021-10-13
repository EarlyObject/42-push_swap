# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/21 15:29:06 by asydykna          #+#    #+#              #
#    Updated: 2021/10/04 10:54:43 by asydykna         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_NAME = libft.a

SRC = push_swap.c utils.c s_functions.c r_functions.c rr_functions.c \
	p_functions.c sort.c manage_stack.c checks.c sort_utils.c \
	sort_large_nums.c prepare_place.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIBFT_PATH = ./libft

VPATH = src include
#vpath %.c src

#vpath %.h include

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/libft.a $(LIBFT_NAME)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT_PATH)/$(LIBFT_NAME) -o $(NAME) #check OBJ instead of SRC

clean:
	$(RM) $(OBJ)
	make clean -C $(LIBFT_PATH)

fclean: clean
	make fclean -C $(LIBFT_PATH)
	$(RM) $(NAME)
	$(RM) $(LIBFT_NAME)

re: fclean all

norm:
	norminette ./src ./include $(LIBFT_PATH)

.SILENT: $(OBJ)

.PHONY: all clean fclean re norm