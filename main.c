/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:24:57 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/23 14:16:30 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_game	game;

	if (check_args(ac, av, &game) == 1)
		return (1);
	game.map.map = build_map(av, &game);
	if (!game.map.map)
		return (1);
	if (check_map_struct(&game) == 1)
	{
		free_map(&game);
		return (1);
	}
	if (game_init(&game) == 1)
	{
		free_images(&game);
		ft_free(&game);
		free_map(&game);
		return (1);
	}
	free_images(&game);
	ft_free(&game);
	free_map(&game);
	return (0);
}
