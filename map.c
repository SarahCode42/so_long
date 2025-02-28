/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 12:46:10 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_map(t_game *g)
{
	char	*line;
	int		i;
	int		lines;

	lines = count_lines(g);
	if (lines <= 0)
		return (NULL);
	g->fd = open(g->filename, O_RDONLY);
	if (g->fd < 0)
		return (NULL);
	g->map.grille = malloc(sizeof(char *) * (lines + 1));
	if (!g->map.grille)
		return (close(g->fd), NULL);
	i = 0;
	while (i < lines && (line = get_next_line(g->fd)) != NULL)
	{
		g->map.grille[i] = line;
		i++;
	}
	g->map.grille[i] = NULL;
	close(g->fd);
	if (i != lines)
		return (free_map(g->map.grille), NULL);
	find_player(g);
	g->player.moves = 0;
	g->start_time = time(NULL);
	return (g->map.grille);
}

int	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->textures.wall = mlx_xpm_file_to_image
		(g->mlx, "textures/wall.xpm", &w, &h);
	g->textures.floor = mlx_xpm_file_to_image
		(g->mlx, "textures/floor.xpm", &w, &h);
	g->textures.player = mlx_xpm_file_to_image
		(g->mlx, "textures/player.xpm", &w, &h);
	g->textures.collectible = mlx_xpm_file_to_image
		(g->mlx, "textures/collectible.xpm", &w, &h);
	g->textures.exit = mlx_xpm_file_to_image
		(g->mlx, "textures/exit.xpm", &w, &h);
	g->textures.background = mlx_xpm_file_to_image
		(g->mlx, "textures/background.xpm", &w, &h);
	if (!g->textures.wall || !g->textures.floor || !g->textures.player
		|| !g->textures.collectible || !g->textures.exit
		|| !g->textures.background)
	{
		write(2, "Error: Unable to load textures.\n", 32);
		return (1);
	}
	return (0);
}

int	draw_map(t_game *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			img = NULL;
			if (g->map.grille[y][x] == '1')
				img = g->textures.wall;
			else if (g->map.grille[y][x] == 'P')
				img = g->textures.player;
			else if (g->map.grille[y][x] == 'C')
				img = g->textures.collectible;
			else if (g->map.grille[y][x] == 'E')
				img = g->textures.exit;
			else if (g->map.grille[y][x] == '0')
				img = g->textures.background;
			if (img)
				mlx_put_image_to_window
					(g->mlx, g->window, img, x * TILE_SIZE, y * TILE_SIZE);
			x++;
		}
		y++;
	}
	return (0);
}

int	count_lines(t_game *g)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(g->filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}
