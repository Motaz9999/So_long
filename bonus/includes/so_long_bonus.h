/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moodeh <moodeh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:04:10 by moodeh            #+#    #+#             */
/*   Updated: 2025/11/20 22:19:26 by moodeh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ok first lets make the header

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# define TRUEE 1
# define FALSEE 0
# define TITEL_SIZE 32
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_ESC 65307
# include "../libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_game
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	**map;
	int		map_width;
	int		map_height;
	int		player_x;
	int		player_y;
	int		collectibles_count;
	int		move_count;

	void	*wall_texture;
	void	*floor_texture;
	void	*player[4];
	void	*collectible[4];
	void	*enemy_texture;
	void	*exit_texture;
	char	is_it_e;
	int		current_frame;
	int		frame_timer;
}			t_game;

typedef struct s_elments
{
	int		p_count;
	int		e_count;
	int		c_count;
	int		i;
	int		j;
	int		player_x;
	int		player_y;
}			t_counts;
void		inti_game(t_game *make_game);
int			make_map(t_game *make_game, char *map_path);
int			valid_map(t_game *make_game, char *map_path);
int			get_map_height(char *map_path);
int			check_on_map(t_game *make_game);
void		error_handle_map_free(t_game *make_game);
int			load_textures(t_game *make_game);
int			render_game(t_game *make_game);
int			handle_keypress(int keycode, void *param);
int			exit_game(t_game *make_game);
void		move_player(t_game *make_game, int x, int y);
void		error_handle_map_free(t_game *make_game);
int			check_on_map(t_game *make_game);
int			get_line_width(char *line);
int			can_solve_it(t_game *make_game);
int			ft_is_in_set_n(char *str, char *set, int n);
char		*get_next_line(int fd);
int			animate_p_c(t_game *make_game);

#endif