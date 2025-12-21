/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:52:44 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/11 21:26:08 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// also it have to peast the steps
// its who paset the image (make it)
// soo it well look at the map then paset the imeges like 0-> wall ...
// mlx_put_image_to_window this what we will use to put it inside the window
// were to start inside the screen(i is Y and j is X)
static int	draw_one_char(t_game *make_game, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->floor_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == '1')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->wall_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == 'C')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->collectible_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == 'E')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->exit_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == 'P')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->player_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else
		return (FALSEE);
	return (TRUEE);
}

int	render_game(t_game *make_game)
{
	int	i;
	int	j;

	i = 0;
	while (i < make_game->map_height)
	{
		j = 0;
		while (j < make_game->map_width)
		{
			if (!draw_one_char(make_game, make_game->map[i][j], j, i))
			{
				ft_printf("Error\n :error happend in render the game\n");
				return (FALSEE);
			}
			j++;
		}
		i++;
	}
	return (TRUEE);
}
