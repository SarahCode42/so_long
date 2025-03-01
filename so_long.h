/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:38:06 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/02 00:29:09 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
//# include "minilibx-linux/mlx.h"
# include "minilibx-mac/mlx.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include "GetNextLine/get_next_line.h"

# define TILE_SIZE 32

/*// Keyboard (Linux)
# define ESC 65307
# define W 119
# define S 115
# define A 97
# define D 100*/

// Keyboard (Mac)
# define ESC 53
# define W 13
# define S 1
# define A 0
# define D 2

// Positions
typedef struct s_point
{
	int	x;
	int	y;
}t_point;

// Map
typedef struct s_map
{
	char	**grille;
	int		width;
	int		height;
	int		player_count;
	int		exit_count;
	int		collectible_count;
}t_map;

// Textures
typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
	void	*background;
}t_textures;

// Player
typedef struct s_player
{
	int		x;
	int		y;
	int		moves;
	int		collected;
}t_player;

// Game
typedef struct s_game
{
	void		*mlx;
	void		*window;
	t_map		map;
	t_textures	textures;
	t_player	player;
	t_point		exit;
	int			fd;
	char		*filename;
	int			start_time;
	int			game_over;
}t_game;

// dfs.c
int		**init_visited(int height, int width);
void	dfs(t_game *g, int **visited, int x, int y);
int		check_accessibility(t_game *g, int **visited);
int		init_dfs_and_run(t_game *g, int start_x, int start_y);

// map.c
char	**load_map(t_game *g);
int		load_textures(t_game *g);
int		draw_map(t_game *g);
int		count_lines(t_game *g);

// parsing.c
int		validate_map(t_game *g);
int		check_walls(t_game *g);
int		check_elements(t_game *g);

// player.c
void	find_player(t_game *g);
int		can_move(t_game *g, int new_x, int new_y);
void	move_player(t_game *g, int dx, int dy);
void	update_player_position(t_game *g, int new_x, int new_y);
void	handle_endgame(t_game *g);

// so_long.c
void	init_game(t_game *g, char *filename);

// utils.c
void	free_map(char **grille);
void	find_exit(t_game *g);
void	free_visited(int **visited, int height);
void	error_exit(char *msg, t_game *g);

// window.c
void	destroy_textures(t_game *g);
int		close_window(t_game *g);
int		key_hook(int keycode, void *param);
int		exit_hook(int keycode, void *param);

#endif