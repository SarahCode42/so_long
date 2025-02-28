/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 15:19:01 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *g, char *filename)
{
	g->filename = filename;
	g->mlx = mlx_init();
	if (!g->mlx)
		error_exit("Error: Failed to initialize MLX\n", g);
	g->map.grille = load_map(g);
	if (!g->map.grille || !validate_map(g))
		error_exit("Error: Invalid map\n", g);
	g->map.height = 0;
	while (g->map.grille[g->map.height])
		g->map.height++;
	g->map.width = ft_strlen(g->map.grille[0]);
	if (g->map.width > 0 && g->map.grille[0][g->map.width - 1] == '\n')
		g->map.width--;
	g->window = mlx_new_window(g->mlx, g->map.width * TILE_SIZE, g->map.height * TILE_SIZE, "so_long");
	if (!g->window)
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
	mlx_hook(g->window, 17, 0, close_window, g);
	mlx_key_hook(g->window, key_hook, g);
	mlx_loop(g->mlx);
	//free_game(g);
	return (0);
}

 