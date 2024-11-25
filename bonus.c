/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:41:50 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/25 19:26:55 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	display_movements(t_game *game)
{
	char	*movement_text;

	movement_text = ft_itoa(game->player.movements);
	if (!movement_text)
		return ;
	mlx_string_put(game->mlx_ptr, game->win_ptr, 10, 20, 0xFFFFFF,
		"Number of Moves: ");
	mlx_string_put(game->mlx_ptr, game->win_ptr, 110, 20, 0xFFFFFF,
		movement_text);
	free(movement_text);
}
