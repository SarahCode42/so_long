/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/25 18:07:03 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, t_game *g)
{
	if (g)
		free_map(g->map);
	free(g);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

void	init_game(t_game *g, char *filename)
{
	g->filename = filename;
	g->mlx = mlx_init();
	if (!g->mlx)
		error_exit("Error: Failed to initialize MLX\n", g);

	g->map = load_map(g);
	if (!g->map || !validate_map(g))
		error_exit("Error: Invalid map\n", g);

	// Calcul de la taille de la carte
	g->map_height = 0;
	while (g->map[g->map_height])
		g->map_height++;
	g->map_width = ft_strlen(g->map[0]);
	if (g->map_width > 0 && g->map[0][g->map_width - 1] == '\n')
		g->map_width--;

	g->win = mlx_new_window(g->mlx, g->map_width * TILE_SIZE, g->map_height * TILE_SIZE, "so_long");
	if (!g->win)
		error_exit("Error: Failed to create window\n", g);

	if (load_textures(g))
		error_exit("Error: Failed to load textures\n", g);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 28), 1);

	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (write(2, "Error: Memory allocation failed\n", 33), 1);

	init_game(g, argv[1]);

	draw_map(g);
	mlx_hook(g->win, 17, 0, close_window, g);
	mlx_key_hook(g->win, key_hook, g);
	mlx_loop(g->mlx);
	return (0);
}
 