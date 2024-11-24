/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:36:51 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 13:41:13 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map_struct(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if ((int)ft_strlen(game->map.map[i]) - 1 != game->map.columns)
		{
			ft_printf("Error\nThe map file is not rectangle.\n");
			return (1);
		}
		i++;
	}
	if (check_map_components(game) == 1 || check_map_components1(game) == 1
		|| check_walls_top_bottom(game) == 1 || check_walls_middle(game) == 1)
		return (1);
	if (flood_fill_master(game) == 1)
		return (1);
	return (0);
}

int	check_map_components(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.rows)
	{
		j = 0;
		while (game->map.map[i][j++])
		{
			if (game->map.map[i][j] == EXIT)
				game->map.exit++;
			else if (game->map.map[i][j] == PLAYER)
			{
				game->player.x = j;
				game->player.y = i;
				game->map.player++;
			}
			else if (game->map.map[i][j] == COLLECTIBLE)
				game->map.collectible++;
			else if (game->map.map[i][j] != WALL && game->map.map[i][j] != '0'
				&& game->map.map[i][j] != '\0' && game->map.map[i][j] != '\n')
				game->map.ok++;
		}
	}
	return (0);
}

int	check_map_components1(t_game *game)
{
	if (game->map.exit != 1 || game->map.player != 1
		|| game->map.collectible < 1 || game->map.ok != 0)
	{
		ft_printf("Error\nThe map doesn't have all required elements.\n");
		return (1);
	}
	return (0);
}

int	check_walls_top_bottom(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.map[0][i] != '\n')
	{
		if (game->map.map[0][i] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (game->map.map[game->map.rows - 1][i] != '\n')
	{
		if (game->map.map[game->map.rows - 1][i] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_walls_middle(t_game *game)
{
	int	i;

	i = 1;
	while (i < game->map.rows)
	{
		if (game->map.map[i][0] != WALL
			|| game->map.map[i][game->map.columns - 1] != WALL)
		{
			ft_printf("Error\nThe map is not surrounded by walls.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
