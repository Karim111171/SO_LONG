/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student..fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:03:16 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 14:07:18 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_game *game)
{
	if (game->background.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->background.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->wall.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->exit.img_ptr);
	if (game->collectible.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->collectible.img_ptr);
	if (game->player.player.img_ptr)
		mlx_destroy_image(game->mlx_ptr, game->player.player.img_ptr);
}

void	ft_free(t_game *game)
{
	if (game->win_ptr)
	{
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		game->win_ptr = NULL;
	}
	if (game->mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
		game->mlx_ptr = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.map)
	{
		while (i < game->map.rows)
			free(game->map.map[i++]);
		free(game->map.map);
		game->map.map = NULL;
	}
	i = 0;
	if (game->map.copy_map)
	{
		while (i < game->map.rows)
			free(game->map.copy_map[i++]);
		free(game->map.copy_map);
		game->map.copy_map = NULL;
	}
}
