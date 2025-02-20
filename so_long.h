/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:38:06 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/20 17:06:00 by jbensimo         ###   ########.fr       */
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

typedef struct s_textures
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*collectible;
}t_textures;

typedef struct s_map
{
	int		p;
	int		e;
	int		c;
}t_map;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	t_map		map_info;
	char		*filename;
	int			fd;
	t_textures	textures;
}t_data;

// map.c
void	draw_map(t_data *f);
void	load_textures(t_data *f);

// parsing.c
int		validate_map(t_data *f);
int		check_walls(t_data *f);
int		check_elements(t_data *f);

// so_long.c
void	free_map(char **map);

// window.c
int		close_window(void *param);
int		key_hook(int keycode, void *param);
int		count_lines(t_data *f);
int		open_ber(t_data *f);
char	**load_map(t_data *f);

#endif