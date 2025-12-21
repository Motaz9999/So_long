/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 22:45:45 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 20:13:33 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// here we want to load 6 kind of textuers
// 1.p  2.c  3.e  4.(1)   5.(0)   6.background
int	load_textures(t_game *make_game)
{
	int	width;
	int	height;

	(make_game)->floor_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/floor.xpm", &width, &height);
	(make_game)->collectible_texture = mlx_xpm_file_to_image(
			(make_game)->mlx_ptr, "./textures/collectible/coin_1.xpm",
			&width, &height);
	(make_game)->exit_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/exit.xpm", &width, &height);
	(make_game)->wall_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/wall.xpm", &width, &height);
	(make_game)->player_texture = mlx_xpm_file_to_image((make_game)->mlx_ptr,
			"./textures/player_1.xpm", &width, &height);
	if (!make_game->wall_texture || !make_game->floor_texture
		|| !make_game->player_texture || !make_game->collectible_texture
		|| !make_game->exit_texture)
	{
		ft_printf("Error\nFailed to load textures.\n");
		return (FALSEE);
	}
	return (TRUEE);
}
