/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/04 16:25:57 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*g;

	if (argc != 2)
		return (write(2, "Usage: ./so_long map.ber\n", 25), 1);
	g = ft_calloc(1, sizeof(t_game));
	if (!g)
		return (write(2, "Error: Memory allocation failed\n", 33), 1);
	g->filename = argv[1];
	g->mlx = mlx_init();
	if (!g->mlx)
		return (write(2, "Error: Failed to initialize MLX\n", 32), 1);
	parsing(g);
	g->window = mlx_new_window(g->mlx, g->pars.width * TILE_SIZE, g->pars.height * TILE_SIZE, "so_long");
	if (!g->window)
		error_exit("Error: Failed to create window\n", g);
	if (load_textures(g))
		error_exit("Error: Failed to load textures\n", g);
		draw_map(g);
	mlx_hook(g->window, 17, 0, close_window, g);
	mlx_key_hook(g->window, key_hook, g);
	mlx_loop(g->mlx);
	g->start_time = time(NULL);
	close(g->fd);
	return (0);
}
