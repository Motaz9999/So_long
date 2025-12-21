/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:10:49 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/11 01:44:54 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc main.c -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd -o my_app
//./my_app
#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_game	make_game;

	if (argc != 2)
	{
		ft_printf("Error\nUsage: %s <path_to_map.ber>\n", argv[0]);
		return (1);
	}
	inti_game(&make_game);
	if (!make_map(&make_game, argv[1]))
		return (1);
	make_game.mlx_ptr = mlx_init();
	make_game.mlx_win = mlx_new_window(make_game.mlx_ptr, make_game.map_width
			* TITEL_SIZE, make_game.map_height * TITEL_SIZE, "so_long");
	if (!load_textures(&make_game) || !render_game(&make_game))
	{
		error_handle_map_free(&make_game);
		return (1);
	}
	mlx_key_hook(make_game.mlx_win, handle_keypress, &make_game);
	mlx_hook(make_game.mlx_win, 17, (1L << 0), exit_game, &make_game);
	mlx_loop(make_game.mlx_ptr);
}
