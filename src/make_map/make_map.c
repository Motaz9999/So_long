/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:34:18 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/12 19:56:49 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_ber(char *map_path)
{
	int	i;

	i = ft_strlen(map_path);
	if (i < 4)
		return (FALSEE);
	if (ft_strncmp(map_path + i - 4, ".ber", 4) == 0)
	{
		return (TRUEE);
	}
	return (FALSEE);
}

// return true if the map is done and fasle if the map isnt valid
// now we need to check on the path if it exisit  and if there something in it

int	make_map(t_game *make_game, char *map_path)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		close(fd);
		ft_printf("Error\n Error: Cannot open map file\n");
		return (FALSEE);
	}
	line = get_next_line(fd);
	if (line == NULL || !check_ber(map_path))
	{
		close(fd);
		ft_printf("Error\n Error:Map not .ber or error file is empty\n");
		free(line);
		return (FALSEE);
	}
	free(line);
	close(fd);
	if (!valid_map(make_game, map_path))
		return (FALSEE);
	return (TRUEE);
}
