/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 00:52:44 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 23:08:08 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			make_game->collectible[make_game->current_frame], TITEL_SIZE * i,
			TITEL_SIZE * j);
	else if (c == 'E')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->exit_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == 'Z')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->enemy_texture, TITEL_SIZE * i, TITEL_SIZE * j);
	else if (c == 'P')
		mlx_put_image_to_window(make_game->mlx_ptr, make_game->mlx_win,
			make_game->player[make_game->current_frame], TITEL_SIZE * i,
			TITEL_SIZE * j);
	else
		return (FALSEE);
	return (TRUEE);
}

static int	helper(t_game *make_game)
{
	char	*st1;
	char	*st2;

	st1 = ft_itoa(make_game->move_count);
	if (st1 == NULL)
		return (FALSEE);
	st2 = ft_strjoin("Moves :", st1);
	if (st2 == NULL)
	{
		free(st1);
		return (FALSEE);
	}
	mlx_string_put(make_game->mlx_ptr, make_game->mlx_win, 10, 20, 0x00FFFFFF,
		st2);
	free(st1);
	free(st2);
	return (TRUEE);
}

// one every move we want to render
int	render_game(t_game *make_game)
{
	int		i;
	int		j;

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
	if (!helper(make_game))
		return (FALSEE);
	return (TRUEE);
}
