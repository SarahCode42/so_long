/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:38:06 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/24 19:21:32 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft/libft.h"
# include "GetNextLine/get_next_line.h"

# define TILE_SIZE 32  // Taille d’un bloc de la carte

// Gestion des textures
typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
} t_textures;

// Informations sur la carte
typedef struct s_map
{
	int		player_count;
	int		exit_count;
	int		collectible_count;
} t_map;

// Structure principale du jeu
typedef struct s_game
{
	void		*mlx;
	void		*win;
	char		**map;
	int			map_width;
	int			map_height;
	int			fd;
	char		*filename;
	t_map		map_info;
	t_textures	textures;
} t_game;

// map.c
char	**load_map(t_game *g);
int		draw_map(t_game *g);
int		load_textures(t_game *g);
int		count_lines(t_game *g);
void	free_map(char **map);

// parsing.c
int		validate_map(t_game *g);
int		check_walls(t_game *g);
int		check_elements(t_game *g);

// so_long.c


// window.c
int		close_window(void *param);
int		key_hook(int keycode, void *param);

#endif
