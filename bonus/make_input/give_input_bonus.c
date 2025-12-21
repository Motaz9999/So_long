/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_input_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 23:31:03 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 23:30:29 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

// for free the textures and map
int	exit_game(t_game *make_game)
{
	error_handle_map_free(make_game);
	mlx_destroy_image(make_game->mlx_ptr, make_game->collectible[0]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->collectible[1]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->collectible[2]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->collectible[3]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->exit_texture);
	mlx_destroy_image(make_game->mlx_ptr, make_game->player[0]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->player[1]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->player[2]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->player[3]);
	mlx_destroy_image(make_game->mlx_ptr, make_game->enemy_texture);
	mlx_destroy_image(make_game->mlx_ptr, make_game->floor_texture);
	mlx_destroy_image(make_game->mlx_ptr, make_game->wall_texture);
	mlx_destroy_window(make_game->mlx_ptr, make_game->mlx_win);
	mlx_destroy_display(make_game->mlx_ptr);
	free(make_game->mlx_ptr);
	exit(0);
	return (0);
}
// we have 5 keys W,S,D,A,ESC and x on the window

int	handle_keypress(int keycode, void *param)
{
	t_game	*make_game;

	make_game = (t_game *)param;
	if (keycode == KEY_ESC)
		exit_game(make_game);
	else if (keycode == KEY_W)
		move_player(make_game, 0, -1);
	else if (keycode == KEY_A)
		move_player(make_game, -1, 0);
	else if (keycode == KEY_S)
		move_player(make_game, 0, 1);
	else if (keycode == KEY_D)
		move_player(make_game, 1, 0);
	else
		return (0);
	return (1);
}
