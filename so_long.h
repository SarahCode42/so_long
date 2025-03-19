/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:38:06 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/18 18:26:04 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/time.h>
# include "minilibx-linux/mlx.h"
//# include "minilibx-mac/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "GetNextLine/get_next_line.h"

# define TILE_SIZE 32

// Keyboard (Linux)
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100

/*// Keyboard (Mac)
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2*/

// Positions
typedef struct s_point
{
	int		x;
	int		y;
	int		moves;
	int		collected;
}t_point;

// Textures
typedef struct s_textures
{
	void	*wall;
	void	*background;
	void	*player;
	void	*exit;
	void	*collectible;
}	t_textures;

// Parsing
typedef struct s_parsing
{
	char	**map;
	int		**visited;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collect_count;
	int		collectibles_found;
}t_parsing;

// Game
typedef struct s_game
{
	void		*mlx;
	void		*window;
	void		*img;
	t_textures	*textures;
	t_point		player;
	t_point		exit;
	t_parsing	*parsing;
	int			fd;
	char		*filename;
	int			start_time;
	int			game_over;
	int			key_pressed;
	int			last_move_time;
	int			level;
	int			frame;
	char		*line;
}t_game;

// dfs.c
void		init_visited(t_game *g);
void		dfs_recurs(t_game *g, int x, int y);
void		check_accessibility(t_game *g);
int			dfs(t_game *g);

// free.c
void		free_map(char **map);
void		free_visited(t_game *g);
void		free_parsing(t_game *g);
void		free_textures(t_game *g);
void		free_game(t_game *g);

// map_utils.c
void		count_height(t_game *g);
int			count_width(t_game *g, int i);
void		find_player(t_game *g, int i, int j);
void		find_exit(t_game *g, int i, int j);

// map.c
void		load_map(t_game *g);
t_textures	*load_textures(t_game *g);
void		*get_texture(t_game *g, char c);
int			draw_map(t_game *g);
void		draw_moves(t_game *g);

// parsing.c
void		check_walls(t_game *g);
void		parse_map_line(t_game *g, int i);
int			check_elements(t_game *g);
void		check_extension(char *filename, t_game *g);
void		parsing(t_game *g);

// player.c
void		find_player(t_game *g, int i, int j);
int			can_move(t_game *g, int new_x, int new_y);
void		move_player(t_game *g, int dx, int dy);
void		update_player_position(t_game *g, int new_x, int new_y);

// utils.c
void		error_exit(char *msg);
int			open_file(t_game *g);
int			close_file(t_game *g, int lines_read, int total_lines);
int			close_window(t_game *g);
int			if_not(void *ptr, char *msg, t_game *g);

// key.c
int			key_press(int keycode, t_game *g);
int			key_release(int keycode, t_game *g);
int			key_loop(void *param);
void		key(t_game *g);

#endif