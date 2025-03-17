/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/17 15:34:58 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;
	
	if (argc != 2)
    	error_exit("Usage: ./so_long map.ber\n");
	g = ft_calloc(1, sizeof(t_game));
	if_not(g, "Memory allocation failed\n", NULL, NULL);
	g->filename = ft_strdup(argv[1]);
	if_not(g->filename, "Memory allocation failed\n", g, free_game);
	g->mlx = mlx_init();
	if_not(g->mlx, "Failed to initialize MLX\n", g, free_game);
	parsing(g);
	if_not(g->parsing, "Parsing error\n", g, free_game);
	g->window = mlx_new_window(g->mlx, g->parsing->width * TILE_SIZE, g->parsing->height * TILE_SIZE, "so_long");
	if_not(g->window, "Failed to create window\n", g, free_game);
	if_not(load_textures(g), "Failed to load textures\n", g, free_game);
	draw_map(g);
	key(g);
	mlx_hook(g->window, 17, 0, close_window, g);
	mlx_loop(g->mlx);
	free_game(g);
	return (0);
}
