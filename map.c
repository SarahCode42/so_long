/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 17:49:43 by YonathanetS      ###   ########.fr       */
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
		error_exit("Failed to allocate memory for map\n", g);
	i = 0;
	line = get_next_line(g->fd);
	while (i < g->pars.height && line)
	{
		g->pars.map[i] = line;
		line = get_next_line(g->fd);
		i++;
	}
	g->pars.map[i] = NULL;
	if (i < g->pars.height)
		error_exit("Map file is incomplete\n", g);
}

int	load_textures(t_game *g)
{
	int	w;
	int	h;

	g->textures.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	if (!g->textures.wall)
		return (write(2, "Unable to load wall texture.\n", 36), 1);
	g->textures.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
	if (!g->textures.floor)
		return (destroy_textures(g), write(2, "Unable to load floor texture.\n", 37), 1);
	g->textures.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &w, &h);
	if (!g->textures.player)
		return (destroy_textures(g), write(2, "Unable to load player texture.\n", 38), 1);
	g->textures.collectible = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &w, &h);
	if (!g->textures.collectible)
		return (destroy_textures(g), write(2, "Unable to load collectible texture.\n", 42), 1);
	g->textures.exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
	if (!g->textures.exit)
		return (destroy_textures(g), write(2, "Unable to load exit texture.\n", 35), 1);
	g->textures.background = mlx_xpm_file_to_image(g->mlx, "textures/background.xpm", &w, &h);
	if (!g->textures.background)
		return (destroy_textures(g), write(2, "Unable to load background texture.\n", 41), 1);
	return (0);
}

void	destroy_textures(t_game *g)
{
	if (g->textures.wall)
		mlx_destroy_image(g->mlx, g->textures.wall);
	if (g->textures.floor)
		mlx_destroy_image(g->mlx, g->textures.floor);
	if (g->textures.player)
		mlx_destroy_image(g->mlx, g->textures.player);
	if (g->textures.collectible)
		mlx_destroy_image(g->mlx, g->textures.collectible);
	if (g->textures.exit)
		mlx_destroy_image(g->mlx, g->textures.exit);
	if (g->textures.background)
		mlx_destroy_image(g->mlx, g->textures.background);
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

void draw_moves(t_game *g)
{
    char *moves_str;
    char *display_str;

    moves_str = ft_itoa(g->player.moves);
    if (!moves_str)
        return;
    display_str = ft_strjoin("Moves: ", moves_str);
    free(moves_str);
    if (!display_str)
        return;
    mlx_string_put(g->mlx, g->window, 10, 10, 0x0000FF, display_str);
    free(display_str);
}

