# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:39:53 by kkeirouz          #+#    #+#              #
#    Updated: 2024/11/25 17:07:00 by kkeirouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = main.c init.c checks.c handle.c render.c free.c check_map.c flood_fill.c
SRCS_BONUS = ./bonus/bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I minilibx-linux  
CFLAGS_BONUS = $(CFLAGS) -DBONUS

MLX_LIB = ./minilibx-linux/libmlx.a -lX11 -lXext
LIBFT_LIB = ./Libft/libft.a

all: $(NAME)

bonus: $(OBJS) $(OBJS_BONUS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS_BONUS) $(OBJS) $(OBJS_BONUS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

$(MLX_LIB):
	$(MAKE) -C ./minilibx-linux

$(LIBFT_LIB):
	$(MAKE) -C ./Libft

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o : %.c
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)

clean:
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f ./Libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus

