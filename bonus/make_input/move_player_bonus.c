/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:18:44 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 21:46:23 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	e_case(t_game *make_game, int x, int y, char ch)
{
	if (make_game->collectibles_count == 0)
	{
		make_game->move_count++;
		ft_printf("Moves: %d\n", make_game->move_count);
		ft_printf("You Win!\n");
		exit_game(make_game);
	}
	else if (make_game->collectibles_count != 0 && ch == 'E')
	{
		make_game->is_it_e = 'E';
		make_game->map[make_game->player_y + y][make_game->player_x + x] = 'P';
		make_game->map[make_game->player_y][make_game->player_x] = '0';
		make_game->player_x = make_game->player_x + x;
		make_game->player_y = make_game->player_y + y;
		render_game(make_game);
		make_game->move_count++;
		ft_printf("move count : %d\n", make_game->move_count);
	}
}

// this just to replace the loc of p
void	take(t_game *make_game, int x, int y, int casee)
{
	char	ch_for_replace;

	if (casee == 1)
		ch_for_replace = make_game->map[make_game->player_y
			+ y][make_game->player_x + x];
	else if (casee == 2)
		ch_for_replace = '0';
	else
	{
		ch_for_replace = 'E';
		make_game->is_it_e = '\0';
	}
	make_game->map[make_game->player_y + y][make_game->player_x + x] = 'P';
	make_game->map[make_game->player_y][make_game->player_x] = ch_for_replace;
	make_game->player_x = make_game->player_x + x;
	make_game->player_y = make_game->player_y + y;
	render_game(make_game);
	make_game->move_count++;
	ft_printf("move count : %d\n", make_game->move_count);
}

void	enemy_touch(t_game *make_game)
{
	make_game->move_count++;
	ft_printf("Moves: %d\n", make_game->move_count);
	ft_printf("You Lose!\n");
	exit_game(make_game);
}

// here we change on the map by switchg the player pos with
// just 0 and the E,C disapper and 1 cant be replace
// this what well happend on the make_game.player_x and player_y
void	move_player(t_game *make_game, int x, int y)
{
	char	ch;

	ch = make_game->map[make_game->player_y + y][make_game->player_x + x];
	if (make_game->is_it_e == 'E' && (ch == '0' || ch == 'C'))
		take(make_game, x, y, 3);
	else if (ch == '0')
		take(make_game, x, y, 1);
	else if (ch == 'C')
	{
		take(make_game, x, y, 2);
		make_game->collectibles_count--;
	}
	else if (ch == 'E')
		e_case(make_game, x, y, 'E');
	else if (ch == 'Z')
		enemy_touch(make_game);
	else if (ch == '1')
		return ;
	else
		return ;
}
