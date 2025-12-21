/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_p_c_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 23:31:59 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 23:32:00 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animate_p_c(t_game *make_game)
{
	make_game->frame_timer++;
	if (make_game->frame_timer < 2000)
		return (FALSEE);
	make_game->frame_timer = 0;
	make_game->current_frame++;
	if (make_game->current_frame >= 4)
		make_game->current_frame = 0;
	render_game(make_game);
	return (TRUEE);
}
