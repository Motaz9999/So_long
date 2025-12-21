/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:37:08 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 23:30:46 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	inti_game(t_game *make_game)
{
	make_game->collectible[0] = NULL;
	make_game->collectible[1] = NULL;
	make_game->collectible[2] = NULL;
	make_game->collectible[3] = NULL;
	make_game->collectibles_count = 0;
	make_game->exit_texture = NULL;
	make_game->floor_texture = NULL;
	make_game->map = NULL;
	make_game->map_height = 0;
	make_game->map_width = 0;
	make_game->mlx_ptr = NULL;
	make_game->mlx_win = NULL;
	make_game->move_count = 0;
	make_game->player[0] = NULL;
	make_game->player[1] = NULL;
	make_game->player[2] = NULL;
	make_game->player[3] = NULL;
	make_game->enemy_texture = NULL;
	make_game->player_x = 0;
	make_game->player_y = 0;
	make_game->wall_texture = NULL;
}
