# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:39:53 by kkeirouz          #+#    #+#              #
#    Updated: 2024/11/13 19:00:57 by kkeirouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

SRCS	=	main.c init.c checks.c handle.c render.c free.c check_map.c flood_fill.c

OBJS	=	$(SRCS:.c=.o)

CC	=	cc
CFLAGS	=	-Wall -Wextra -Werror -g3 -I minilibx-linux  

MLX_LIB = ./minilibx-linux/libmlx.a -lX11 -lXext
LIBFT_LIB = ./Libft/libft.a


all: $(NAME)

$(MLX_LIB):
	$(MAKE) -C ./minilibx-linux

$(LIBFT_LIB):
	$(MAKE) -C ./Libft

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

.o .c:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all

.PHONY: all clean fclean re

