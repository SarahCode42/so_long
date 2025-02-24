/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/24 19:11:35 by jbensimo         ###   ########.fr       */
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
	g->map = malloc(sizeof(char *) * (lines + 1));
	if (!g->map)
		return (close(g->fd), NULL);
	i = 0;
	while ((line = get_next_line(g->fd)) != NULL)
	{
		g->map[i] = line;
		i++;
	}
	g->map[i] = NULL;
	close(g->fd);
	return (g->map);
}

int draw_map(t_game *g)
{
    int x;
	int y;

    y = 0;
    while (y < g->map_height)
    {
        x = 0;
        while (x < g->map_width)
        {
            void *img = NULL;
            if (g->map[y][x] == '1')
                img = g->textures.wall;
            else if (g->map[y][x] == '0')
                img = NULL;
            else if (g->map[y][x] == 'P')
                img = g->textures.player;
            else if (g->map[y][x] == 'C')
                img = g->textures.collectible;
            else if (g->map[y][x] == 'E')
                img = g->textures.exit;
            if (img)
                mlx_put_image_to_window(g->mlx, g->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
    return (0);
}

int load_textures(t_game *g)
{
    int w;
	int	h;

    g->textures.wall = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
    g->textures.player = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
    g->textures.collectible = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
    g->textures.exit = mlx_xpm_file_to_image(g->mlx, "textures/wall.xpm", &w, &h);
    if (!g->textures.wall || !g->textures.player || !g->textures.collectible || !g->textures.exit)
    {
		printf("Error: Unable to load textures.\n");
		return (1);
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

void	free_map(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}
