/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:45:45 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 23:31:36 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// for the coin
static int	coll_text(t_game *make_game)
{
	int	width;
	int	height;

	(make_game)->collectible[0] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/collectible/coin_1.xpm", &width, &height);
	(make_game)->collectible[1] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/collectible/coin_2.xpm", &width, &height);
	(make_game)->collectible[2] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/collectible/coin_3.xpm", &width, &height);
	(make_game)->collectible[3] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/collectible/coin_4.xpm", &width, &height);
	if (!make_game->collectible[1] || !make_game->collectible[3]
		|| !make_game->collectible[2] || !make_game->collectible[0])
		return (FALSEE);
	return (TRUEE);
}
// the player idel like aizen soske or goku

static int	player_text(t_game *make_game)
{
	int	width;
	int	height;

	(make_game)->player[0] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/player_1.xpm", &width, &height);
	(make_game)->player[1] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/player_2.xpm", &width, &height);
	(make_game)->player[2] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/player_3.xpm", &width, &height);
	(make_game)->player[3] = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/player_4.xpm", &width, &height);
	if (!make_game->player[1] || !make_game->player[2] || !make_game->player[3]
		|| !make_game->player[0])
		return (FALSEE);
	return (TRUEE);
}
// here we want to load 6 kind of textuers
// 1.p  2.c  3.e  4.(1)   5.(0)   6.background

int	load_textures(t_game *make_game)
{
	int	width;
	int	height;

	(make_game)->floor_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/floor.xpm", &width, &height);
	(make_game)->exit_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/exit.xpm", &width, &height);
	(make_game)->wall_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/wall.xpm", &width, &height);
	(make_game)->enemy_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/enemy.xpm", &width, &height);
	if (!player_text(make_game) || !make_game->wall_texture
		|| !make_game->floor_texture || !coll_text(make_game)
		|| !make_game->exit_texture)
	{
		ft_printf("Error\nFailed to load textures.\n");
		return (FALSEE);
	}
	make_game->current_frame = 0;
	make_game->frame_timer = 0;
	return (TRUEE);
}
