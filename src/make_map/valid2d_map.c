/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid2d_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:56:36 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 19:57:17 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// to see if it rectangular

int	get_line_width(char *line)
{
	int	width;

	width = 0;
	if (!line)
		return (0);
	while (line[width] && line[width] != '\n')
		width++;
	return (width);
}

// here we need to check on every row but not the first
static int	is_rectangular(t_game *make_game)
{
	int	i;

	i = 1;
	while (make_game->map[i] != NULL)
	{
		if (get_line_width(make_game->map[i]) != make_game->map_width)
		{
			ft_printf("Error\n Error: not rectangular \n");
			return (FALSEE);
		}
		i++;
	}
	return (TRUEE);
}

// to see it close or not
// first we need to spcial check on the first and last row then loop
static int	is_closed(t_game *make_game)
{
	int	i;

	i = 0;
	while (make_game->map[0][i] == '1' && make_game->map[make_game->map_height
		- 1][i] == '1' && i < make_game->map_width)
		i++;
	if (i != make_game->map_width)
	{
		ft_printf("Error\n Error:a top or bottom wall is broken.\n");
		return (FALSEE);
	}
	i = 1;
	while (i < make_game->map_height - 1)
	{
		if (make_game->map[i][0] != '1'
			|| make_game->map[i][make_game->map_width - 1] != '1')
		{
			ft_printf("Error\n Error:a side wall is broken.\n");
			return (FALSEE);
		}
		i++;
	}
	return (TRUEE);
}

// to count and see if it anything else
// now we need to check on every thing in the list
// if it inside the set or not and count for every c,p,e
static int	all_in_set(t_game *make_game, char **map, char *set, t_counts *all)
{
	while (map[(*all).i] != NULL)
	{
		if (!ft_is_in_set_n(map[(*all).i], set, get_line_width(map[(*all).i])))
			return (FALSEE);
		(*all).j = 0;
		while (map[(*all).i][(*all).j] != '\0'
			&& map[(*all).i][(*all).j] != '\n')
		{
			if (map[(*all).i][(*all).j] == 'C')
				(*all).c_count++;
			else if (map[(*all).i][(*all).j] == 'P')
			{
				(*all).p_count++;
				(make_game)->player_x = (*all).j;
				(make_game)->player_y = (*all).i;
			}
			else if (map[(*all).i][(*all).j] == 'E')
				(*all).e_count++;
			(*all).j++;
		}
		(*all).i++;
	}
	if ((*all).c_count < 1 || (*all).e_count != 1 || (*all).p_count != 1)
		return (FALSEE);
	return (TRUEE);
}

// here we need to check on 3 things 1.rectangle
//  2.have 1s on borders
// 3.have just 1,0,e,p,c 4.can solve it
int	check_on_map(t_game *make_game)
{
	char		*set;
	t_counts	all;

	set = "10EPC";
	all.c_count = 0;
	all.e_count = 0;
	all.p_count = 0;
	all.i = 0;
	if (!is_rectangular(make_game))
		return (FALSEE);
	if (!is_closed(make_game))
		return (FALSEE);
	if (!all_in_set(make_game, (make_game)->map, set, &all))
	{
		ft_printf("Error\n Error: invalid or not found  char\n");
		return (FALSEE);
	}
	if (!can_solve_it(make_game))
	{
		ft_printf("Error\n Error: the map not solvable\n");
		return (FALSEE);
	}
	(make_game)->collectibles_count = all.c_count;
	return (TRUEE);
}
