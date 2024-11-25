/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:09:47 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/25 19:39:36 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define TILE_SIZE 64
# define EXIT 'E'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define WALL '1'
# define FLOOR '0'

# define ESCAPE 65307

# include "./minilibx-linux/mlx.h"
# include "./Libft/libft.h"
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
}	t_img;

typedef struct s_player
{
	int		x;
	int		y;
	int		movements;
	t_img	player;
}	t_player;

typedef struct s_map
{
	char		**map;
	char		**copy_map;
	int			rows;
	int			columns;
	int			collectible;
	int			collectible_ff;
	int			exit_ff;
	int			exit;
	int			ok;
	int			player;
	int			up;
	int			down;
	int			left;
	int			right;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_map		map;
	t_img		background;
	t_img		wall;
	t_img		collectible;
	t_img		exit;
	t_player	player;
	int			render_again;
	int			win_width;
	int			win_height;
}	t_game;

int		game_init(t_game *game);
void	init_game_struct(t_game *game);
int		initialize_xpm(t_game *game);
int		check_argv(char **av, t_game *game);
int		ft_key_funct(int keycode, t_game *game);
int		check_args(int ac, char**av, t_game *game);
int		handle_cross(t_game *game);
char	**build_map(char **av, t_game *game);
int		check_map_components(t_game *game);
int		check_map_components1(t_game *game);
int		render(t_game *game);
int		render_map(t_game *game);
int		render_tile(t_game *game, int x, int y, char tile);
void	init_player_pos(t_game *game);
int		handle_movement(int keycode, t_game *game);
void	free_images(t_game *game);
void	ft_free(t_game *game);
void	free_map(t_game *game);
void	handle_move_tile(t_game *game);
int		display_movements_number(t_game *game);
int		movement_possible(char direction, t_game *game);
int		check_map_struct(t_game *game);
int		check_walls_top_bottom(t_game *game);
int		check_walls_middle(t_game *game);
int		flood_fill(t_game *flood_game, int x, int y);
int		flood_fill_master(t_game *game);
void	display_movements(t_game *game);

#endif
