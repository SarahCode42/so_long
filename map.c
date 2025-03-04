/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/04 15:56:43 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *g)
{
	char	*line;
	int		i;

	count_height(g);
	if (g->pars.height <= 0)
		return ;
	g->fd = open_file(g);
    g->pars.map = malloc(sizeof(char *) * (g->pars.height + 1));
	if (!g->pars.map)
		error_exit("Error: Failed to allocate memory for map\n", g);
	i = 0;
	line = get_next_line(g->fd);
	//ft_printf("i = %d et height = %d et line = %s et fd = %d et filename = %s\n", i, g->pars.height, line, g->fd, g->filename);
	while (i < g->pars.height && line)
	{
		g->pars.map[i] = line;
		line = get_next_line(g->fd);
		i++;
	}
	//ft_printf("Je passe ici!\n");
	g->pars.map[i] = NULL;
	//ft_printf("i = %d et height = %d\n", i, g->pars.height);
	if (i < g->pars.height)
		error_exit("Error: Map file is incomplete\n", g);
}

int	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->textures.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	if (!g->textures.wall)
		return (write(2, "Error: Unable to load wall texture.\n", 36), 1);
	g->textures.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
	if (!g->textures.floor)
		return (destroy_textures(g), write(2, "Error: Unable to load floor texture.\n", 37), 1);
	g->textures.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &w, &h);
	if (!g->textures.player)
		return (destroy_textures(g), write(2, "Error: Unable to load player texture.\n", 38), 1);
	g->textures.collectible = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &w, &h);
	if (!g->textures.collectible)
		return (destroy_textures(g), write(2, "Error: Unable to load collectible texture.\n", 42), 1);
	g->textures.exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
	if (!g->textures.exit)
		return (destroy_textures(g), write(2, "Error: Unable to load exit texture.\n", 35), 1);
	g->textures.background = mlx_xpm_file_to_image(g->mlx, "textures/background.xpm", &w, &h);
	if (!g->textures.background)
		return (destroy_textures(g), write(2, "Error: Unable to load background texture.\n", 41), 1);
	return (0);
}

int	draw_map(t_game *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g->pars.height)
	{
		x = 0;
		while (x < g->pars.width)
		{
			img = NULL;
			if (g->pars.map[y][x] == '1')
				img = g->textures.wall;
			else if (g->pars.map[y][x] == 'P')
				img = g->textures.player;
			else if (g->pars.map[y][x] == 'C')
				img = g->textures.collectible;
			else if (g->pars.map[y][x] == 'E')
				img = g->textures.exit;
			else if (g->pars.map[y][x] == '0')
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

