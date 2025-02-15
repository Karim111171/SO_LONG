/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:57 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/25 22:11:49 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	game_init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error\nMLX initialization failed\n");
		return (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->map.columns
			* TILE_SIZE, game->map.rows * TILE_SIZE, "so_long");
	if (!game->win_ptr)
		return (1);
	if (initialize_xpm(game) == 1)
	{
		ft_putstr_fd("Error:\nOne texture is missing\n", 2);
		return (1);
	}
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	render_map(game);
	mlx_hook (game->win_ptr, KeyPress, KeyPressMask, &ft_key_funct, game);
	mlx_hook(game->win_ptr, DestroyNotify, StructureNotifyMask,
		&handle_cross, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}

void	init_game_struct(t_game *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->map.map = NULL;
	game->map.copy_map = NULL;
	game->map.rows = 0;
	game->map.columns = 0;
	game->map.collectible = 0;
	game->map.collectible_ff = 0;
	game->map.exit_ff = 0;
	game->map.exit = 0;
	game->map.ok = 0;
	game->map.player = 0;
	game->render_again = 1;
	game->background.img_ptr = NULL;
	game->wall.img_ptr = NULL;
	game->exit.img_ptr = NULL;
	game->collectible.img_ptr = NULL;
	game->player.player.img_ptr = NULL;
	game->player.movements = 0;
	game->win_height = 0;
	game->win_width = 0;
}

int	initialize_xpm(t_game *game)
{
	game->wall.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/wall.xpm", &game->wall.width, &game->wall.height);
	if (game->wall.img_ptr == NULL)
		return (1);
	game->background.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/floor.xpm", &game->background.width,
			&game->background.height);
	if (game->background.img_ptr == NULL)
		return (1);
	game->exit.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/door.xpm", &game->exit.width, &game->exit.height);
	if (game->exit.img_ptr == NULL)
		return (1);
	game->collectible.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/collectible.xpm", &game->collectible.width,
			&game->collectible.height);
	if (game->collectible.img_ptr == NULL)
		return (1);
	game->player.player.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"./sprites/playersheikh.xpm", &game->player.player.width,
			&game->player.player.height);
	if (game->player.player.img_ptr == NULL)
		return (1);
	init_player_pos(game);
	return (0);
}

void	init_player_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.map[y][x] == PLAYER)
			{
				game->player.x = x;
				game->player.y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}
