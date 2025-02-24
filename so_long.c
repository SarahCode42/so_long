/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/24 19:22:24 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (write(2, "Usage: ./so_long <map.ber>\n", 28), 1);

	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (write(2, "Error: Memory allocation failed\n", 33), 1);
	g->filename = argv[1];

	// Initialisation de MiniLibX
	g->mlx = mlx_init();
	if (!g->mlx)
		return (free(g), write(2, "Error: Failed to initialize MLX\n", 33), 1);

	// Chargement de la carte
	g->map = load_map(g);
	if (!g->map || !validate_map(g))
		return (free_map(g->map), free(g), 1);

	// Calcul des dimensions de la carte
	g->map_height = 0;
	while (g->map[g->map_height])
		g->map_height++;
	g->map_width = ft_strlen(g->map[0]);
	if (g->map_width > 0 && g->map[0][g->map_width - 1] == '\n')
		g->map_width--; // Correction si un '\n' est présent

	// Création de la fenêtre avec la bonne taille
	g->win = mlx_new_window(g->mlx, g->map_width * TILE_SIZE, g->map_height * TILE_SIZE, "so_long");
	if (!g->win)
		return (free_map(g->map), free(g), write(2, "Error: Failed to create window\n", 32), 1);

	// Chargement des textures
	if (load_textures(g))
		return (free_map(g->map), free(g), write(2, "Error: Failed to load textures\n", 32), 1);

	// Affichage de la carte
	draw_map(g);

	// Gestion des événements
	mlx_hook(g->win, 17, 0, close_window, g);
	mlx_key_hook(g->win, key_hook, g);
	
	mlx_loop(g->mlx);
	return (0);
}

