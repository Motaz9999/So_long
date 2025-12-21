/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:23:14 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 20:02:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// replace with f and return true

static void	ft_free_split(char **substring)
{
	int	i;

	if (!substring)
		return ;
	i = 0;
	while (substring[i])
	{
		free(substring[i]);
		i++;
	}
	free(substring);
}

char	**make_new_map(t_game *make_game)
{
	char	**copy;
	int		i;

	copy = malloc(sizeof(char *) * (make_game->map_height + 1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (make_game->map[i] != NULL)
	{
		copy[i] = ft_strdup(make_game->map[i]);
		if (copy[i] == NULL)
		{
			ft_free_split(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y, t_game make_game)
{
	if (y >= make_game.map_height || y < 0 || x >= make_game.map_width || x < 0)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	else
		map[y][x] = 'F';
	flood_fill(map, x + 1, y, make_game);
	flood_fill(map, x - 1, y, make_game);
	flood_fill(map, x, y - 1, make_game);
	flood_fill(map, x, y + 1, make_game);
}
// here it well cheeck on the map line by line

int	check_for_f_1(char **map, int width)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (!ft_is_in_set_n(map[i], "1F", width))
			return (FALSEE);
		i++;
	}
	return (TRUEE);
}

int	can_solve_it(t_game *make_game)
{
	char	**copy;

	copy = make_new_map(make_game);
	if (copy == NULL)
	{
		ft_printf("Error\n malloc for copy map failed\n");
		return (FALSEE);
	}
	flood_fill(copy, make_game->player_x, make_game->player_y, *make_game);
	if (!check_for_f_1(copy, make_game->map_width))
	{
		ft_free_split(copy);
		return (FALSEE);
	}
	ft_free_split(copy);
	return (TRUEE);
}
