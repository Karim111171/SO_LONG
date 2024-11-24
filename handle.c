/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:07:45 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 14:13:58 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static int	process_line(t_game *game, char *line)
{
	game->map.map[game->map.rows] = ft_strdup(line);
	game->map.copy_map[game->map.rows] = ft_strdup(line);
	if (!game->map.map[game->map.rows])
	{
		free_map(game);
		return (0);
	}
	game->map.rows++;
	return (1);
}

char	**build_map(char **av, t_game *game)
{
	int		fd;
	char	*line;

	game->map.map = malloc(sizeof(char *) * (game->map.rows + 1));
	game->map.copy_map = malloc(sizeof(char *) * (game->map.rows + 1));
	if (!game->map.map || !game->map.copy_map)
		return (NULL);
	game->map.rows = 0;
	fd = open(av[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!process_line(game, line))
		{
			free(line);
			close(fd);
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	game->map.map[game->map.rows] = NULL;
	close(fd);
	return (game->map.map);
}

int	handle_movement(int keycode, t_game *game)
{
	if (keycode == UP && movement_possible('U', game) == 0)
		game->player.y -= 1;
	else if (keycode == DOWN && movement_possible('D', game) == 0)
		game->player.y += 1;
	else if (keycode == RIGHT && movement_possible('R', game) == 0)
		game->player.x += 1;
	else if (keycode == LEFT && movement_possible('L', game) == 0)
		game->player.x -= 1;
	handle_move_tile(game);
	game->render_again = 1;
	return (0);
}

void	handle_move_tile(t_game *game)
{
	if (game->map.map[game->player.y][game->player.x] == COLLECTIBLE)
	{
		game->map.map[game->player.y][game->player.x] = FLOOR;
		game->map.collectible--;
	}
	else if (game->map.map[game->player.y][game->player.x] == EXIT)
	{
		if (game->map.collectible == 0)
			handle_cross(game);
	}
}

int	movement_possible(char direction, t_game *game)
{
	if (direction == 'U'
		&& game->map.map[game->player.y - 1][game->player.x] != WALL)
	{
		if (game->player.y - 1 >= 0)
			return (display_movements_number(game));
	}
	else if (direction == 'D'
		&& game->map.map[game->player.y + 1][game->player.x] != WALL)
	{
		if (game->player.y + 1 < game->map.rows)
			return (display_movements_number(game));
	}
	else if (direction == 'R'
		&& game->map.map[game->player.y][game->player.x + 1] != WALL)
	{
		if (game->player.x + 1 < game->map.columns)
			return (display_movements_number(game));
	}
	else if (direction == 'L'
		&& game->map.map[game->player.y][game->player.x - 1] != WALL)
	{
		if (game->player.x - 1 >= 0)
			return (display_movements_number(game));
	}
	return (1);
}
