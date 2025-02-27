/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/27 13:21:10 by jbensimo         ###   ########.fr       */
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
	while (i < lines && (line = get_next_line(g->fd)) != NULL)
	{
		g->map[i] = line;
		i++;
	}
	g->map[i] = NULL; // Assurer la terminaison

	close(g->fd);
	if (i != lines) // Si on n'a pas lu toutes les lignes, il y a un problème
		return (free_map(g->map), NULL);

	// 🔥 Trouver le joueur après chargement de la carte
	find_player(g);
	g->moves = 0;  
	g->start_time = time(NULL); // 🔥 Enregistre l'heure de début
	printf("Joueur trouvé à x=%d, y=%d\n", g->player_x, g->player_y);

	return (g->map);
}


int draw_map(t_game *g)
{
    int x, y;

    y = 0;
    while (y < g->map_height)
    {
        x = 0;
        while (x < g->map_width)
        {
            // Afficher le fond avant tout
            //mlx_put_image_to_window(g->mlx, g->win, g->textures.background, x * TILE_SIZE, y * TILE_SIZE);

            // Sélectionner la texture appropriée
            void *img = NULL;
            if (g->map[y][x] == '1')
                img = g->textures.wall;
            else if (g->map[y][x] == 'P')
                img = g->textures.player;
            else if (g->map[y][x] == 'C')
                img = g->textures.collectible;
            else if (g->map[y][x] == 'E')
                img = g->textures.exit;
			else if (g->map[y][x] == '0')
				img = g->textures.background;  // ✅ Mettre une texture blanche en fond
			

            // Afficher l'image uniquement si elle existe
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
	g->textures.floor = mlx_xpm_file_to_image(g->mlx, "textures/floor.xpm", &w, &h);
    g->textures.player = mlx_xpm_file_to_image(g->mlx, "textures/player.xpm", &w, &h);
    g->textures.collectible = mlx_xpm_file_to_image(g->mlx, "textures/collectible.xpm", &w, &h);
    g->textures.exit = mlx_xpm_file_to_image(g->mlx, "textures/exit.xpm", &w, &h);
	g->textures.background = mlx_xpm_file_to_image(g->mlx, "textures/background.xpm", &w, &h);


    if (!g->textures.wall || !g->textures.floor || !g->textures.player || !g->textures.collectible || !g->textures.exit || !g->textures.background)
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
