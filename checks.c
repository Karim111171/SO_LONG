/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:57 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 13:46:06 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	check_args(int ac, char**av, t_game *game)
{
	size_t	i;

	if (ac != 2)
	{
		ft_printf("Error\nInvalid number of arguments.\n");
		return (1);
	}
	if (ac == 2)
	{
		i = ft_strlen(av[1]);
		if (i > 4 && ft_strncmp(av[1] + i - 4, ".ber", i) != 0)
		{
			ft_printf("Error\nFile Format of %s not valid.\n", av[1]);
			return (1);
		}
		if (check_argv(av, game) == 1)
			return (1);
	}
	return (0);
}

int	check_argv(char **av, t_game *game)
{
	int		fd;
	char	*line;

	init_game_struct(game);
	fd = open(av[1], O_RDWR);
	if (fd == -1)
	{
		ft_printf("Error\nImpossible to read the file or file empty.\n");
		return (1);
	}
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (game->map.rows == 0)
			game->map.columns = (int) ft_strlen(line) - 1;
		free(line);
		game->map.rows++;
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	ft_key_funct(int keycode, t_game *game)
{
	(void) game;
	if (keycode == ESCAPE)
		handle_cross(game);
	else
		handle_movement(keycode, game);
	return (0);
}

int	handle_cross(t_game *game)
{
	mlx_loop_end(game->mlx_ptr);
	return (0);
}

int	display_movements_number(t_game *game)
{
	game->player.movements++;
	ft_printf("Number of moves: %d\n", game->player.movements);
	return (0);
}
