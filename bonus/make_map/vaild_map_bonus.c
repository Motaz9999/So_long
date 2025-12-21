/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaild_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:48:14 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 20:05:44 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	get_map_height_width(t_game *make_game, char *map_path)
{
	int		fd;
	char	*line;
	int		height;

	if (map_path == NULL)
		return (FALSEE);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (FALSEE);
	height = 0;
	line = get_next_line(fd);
	if (line == NULL)
		return (FALSEE);
	make_game->map_width = get_line_width(line);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	make_game->map_height = height;
	return (TRUEE);
}

// free the malloc and the map
void	error_handle_map_free(t_game *make_game)
{
	int	i;

	if (!(make_game)->map)
		return ;
	i = 0;
	while ((make_game)->map[i])
	{
		free((make_game)->map[i]);
		i++;
	}
	free((make_game)->map);
}

static int	fill_map(t_game *make_game, char *map_path)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open(map_path, O_RDONLY);
	(make_game)->map = (char **)malloc(sizeof(char *) * ((make_game)->map_height
				+ 1));
	if ((make_game)->map == NULL)
	{
		ft_printf("Error\n Error: malloc failed \n");
		return (FALSEE);
	}
	line = get_next_line(fd);
	while ((line) != NULL && i < (make_game)->map_height)
	{
		(make_game)->map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	(make_game)->map[i] = NULL;
	return (TRUEE);
}

// at least height and width 3,3
// first i want to malloc for the map but i need the height and width
// now i malloc but first i need to check if it have recatangle
// now the check on the 2d map is easeire
// dont forget to do the return truee if the map is valid and false if not!!!!
static int	make2d_map(t_game *make_game, char *map_path)
{
	if (!get_map_height_width(make_game, map_path))
		return (FALSEE);
	if (!fill_map(make_game, map_path))
	{
		error_handle_map_free(make_game);
		return (FALSEE);
	}
	if (!check_on_map(make_game))
	{
		error_handle_map_free(make_game);
		return (FALSEE);
	}
	return (TRUEE);
}

// here i want to check on everything 
//else like its a rectangle its 
//have [10EPC] and 1 E,P and atleast 1 C
// and i want also to check if 
//it enclosed soo the first thing is to make it an 2D array
int	valid_map(t_game *make_game, char *map_path)
{
	if (!make2d_map(make_game, map_path))
		return (FALSEE);
	return (TRUEE);
}
