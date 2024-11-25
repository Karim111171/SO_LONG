# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/13 15:39:53 by kkeirouz          #+#    #+#              #
#    Updated: 2024/11/25 19:19:53 by kkeirouz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

C_SRCS = main.c init.c checks.c handle.c free.c check_map.c flood_fill.c 
SRCS = $(C_SRCS) render.c
SRCS_BONUS = $(C_SRCS) render_bonus.c bonus.c

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -I minilibx-linux  

MLX_LIB = ./minilibx-linux/libmlx.a -lX11 -lXext
LIBFT_LIB = ./Libft/libft.a

all: $(NAME)

$(NAME): $(MLX_LIB) $(LIBFT_LIB) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	
bonus: $(OBJS_BONUS) $(MLX_LIB) $(LIBFT_LIB)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME_BONUS)

$(MLX_LIB):
	$(MAKE) -C ./minilibx-linux

$(LIBFT_LIB):
	$(MAKE) -C ./Libft

$(OBJS): %.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_BONUS): %.o : %.c
	$(CC) $(CFLAGS_BONUS) -c $< -o $@

clean:
	$(MAKE) clean -C ./minilibx-linux
	$(MAKE) clean -C ./Libft
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	rm -f ./Libft/libft.a

re: fclean all

.PHONY: all clean fclean re bonus

