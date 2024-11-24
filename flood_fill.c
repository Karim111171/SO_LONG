/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:46:43 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 14:22:14 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	flood_fill(t_game *flood_game, int x, int y)
{
	if (x > flood_game->map.columns || y > flood_game->map.rows)
		return (0);
	if (flood_game->map.copy_map[y][x] == COLLECTIBLE)
		flood_game->map.collectible_ff--;
	if (flood_game->map.copy_map[y][x] == EXIT)
		flood_game->map.exit_ff--;
	if (flood_game->map.copy_map[y + 1][x] == WALL &&
		flood_game->map.copy_map[y - 1][x] == WALL &&
		flood_game->map.copy_map[y][x + 1] == WALL &&
		flood_game->map.copy_map[y][x - 1] == WALL)
		return (0);
	else
	{
		flood_game->map.copy_map[y][x] = WALL;
		if (flood_game->map.copy_map[y][x + 1] != WALL)
			flood_fill(flood_game, x + 1, y);
		if (flood_game->map.copy_map[y][x - 1] != WALL)
			flood_fill(flood_game, x - 1, y);
		if (flood_game->map.copy_map[y + 1][x] != WALL)
			flood_fill(flood_game, x, y + 1);
		if (flood_game->map.copy_map[y - 1][x] != WALL)
			flood_fill(flood_game, x, y - 1);
		return (0);
	}
}

int	flood_fill_master(t_game *game)
{
	game->map.collectible_ff = game->map.collectible;
	game->map.exit_ff = game->map.exit;
	flood_fill(game, game->player.x, game->player.y);
	if (game->map.collectible_ff != 0 || game->map.exit_ff != 0)
	{
		ft_printf("Error\nThe map cannot be completed.\n");
		ft_free(game);
		return (1);
	}
	else
	{
		ft_free(game);
		return (0);
	}
}
