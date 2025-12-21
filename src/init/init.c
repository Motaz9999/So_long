/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 00:37:08 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/11 21:25:47 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	inti_game(t_game *make_game)
{
	make_game->collectible_texture = NULL;
	make_game->collectibles_count = 0;
	make_game->exit_texture = NULL;
	make_game->floor_texture = NULL;
	make_game->map = NULL;
	make_game->map_height = 0;
	make_game->map_width = 0;
	make_game->mlx_ptr = NULL;
	make_game->mlx_win = NULL;
	make_game->move_count = 0;
	make_game->player_texture = NULL;
	make_game->player_x = 0;
	make_game->player_y = 0;
	make_game->wall_texture = NULL;
}
