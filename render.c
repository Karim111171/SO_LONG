/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:17:01 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 14:20:12 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int render(t_game *game)
{
    if (game->win_ptr)
    {
        mlx_clear_window(game->mlx_ptr, game->win_ptr);
        render_map(game);
        display_movements(game);
        game->render_again = 0;
    }
    return (0);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->player.x == x && game->player.y == y)
			{
				if (game->player.player.img_ptr)
					mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
						game->player.player.img_ptr,
						x * TILE_SIZE, y * TILE_SIZE);
			}
			else
				render_tile(game, x, y, game->map.map[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_tile(t_game *game, int x, int y, char tile)
{
	if (tile == FLOOR && game->background.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->background.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == WALL && game->wall.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->wall.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == EXIT && game->exit.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == COLLECTIBLE && game->collectible.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->collectible.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	else if (tile == PLAYER && game->player.player.img_ptr)
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->background.img_ptr, x * TILE_SIZE, y * TILE_SIZE);
	return (0);
}
