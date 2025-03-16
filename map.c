/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/16 15:46:28 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_map(t_game *g)
{
	char	*line;
	int		i;

	count_height(g);
	if_not((void *)(long)(g->parsing->height > 0), "Invalid map height\n", g, free_parsing);
	g->fd = open_file(g);
	g->parsing->map = malloc(sizeof(char *) * (g->parsing->height + 1));
	if_not(g->parsing->map, "Failed to allocate memory for map\n", g, free_parsing);
	i = 0;
	line = get_next_line(g->fd);
	while (i < g->parsing->height && line)
	{
		g->parsing->map[i] = line;
		line = get_next_line(g->fd);
		i++;
	}
	g->parsing->map[i] = NULL;
	if_not((void *)(long)(i == g->parsing->height), "Map file is incomplete\n", g, free_parsing);
}

t_textures	*load_textures(t_game *g)
{
	int	w;
	int	h;

	g->textures = ft_calloc(1, sizeof(t_textures));
	if_not(g->textures, "Memory allocation failed\n", g, free_game);

	g->textures->wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
	if_not(g->textures->wall, "Unable to load wall texture.\n", g, free_textures);

	g->textures->floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
	if_not(g->textures->floor, "Unable to load floor texture.\n", g, free_textures);

	g->textures->player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &w, &h);
	if_not(g->textures->player, "Unable to load player texture.\n", g, free_textures);

	g->textures->collectible = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &w, &h);
	if_not(g->textures->collectible, "Unable to load collectible texture.\n", g, free_textures);

	g->textures->exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
	if_not(g->textures->exit, "Unable to load exit texture.\n", g, free_textures);

	return (g->textures);
}

void	*get_texture(t_game *g, char c)
{
	if (c == '1')
		return (g->textures->wall);
	if (c == 'P')
		return (g->textures->player);
	if (c == 'C')
		return (g->textures->collectible);
	if (c == 'E')
		return (g->textures->exit);
	if (c == '0')
		return (g->textures->floor);
	return (NULL);
}

int	draw_map(t_game *g)
{
	int		x;
	int		y;
	void	*img;

	y = 0;
	while (y < g->parsing->height)
	{
		x = 0;
		while (x < g->parsing->width)
		{
			img = get_texture(g, g->parsing->map[y][x]);
			if_not(img, "Map contains an unknown element\n", g, free_game);
			if_not((void *)(long)(mlx_put_image_to_window(g->mlx, g->window, img, x * TILE_SIZE, y * TILE_SIZE) != -1),
				"Failed to render image\n", g, free_game);
	 
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
    if_not(moves_str, "Failed to allocate memory for moves string\n", g, NULL);
    display_str = ft_strjoin("Moves: ", moves_str);
    free(moves_str);
    if_not(display_str, "Failed to allocate memory for display string\n", g, NULL);
    mlx_string_put(g->mlx, g->window, 10, 10, 0x0000FF, display_str);
    free(display_str);
}
