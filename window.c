/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/04 15:29:04 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	close_window(t_game *g)
{
	destroy_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		//mlx_destroy_display(g->mlx); //linux
		free(g->mlx);
	}
	if (g->pars.map)
		free_map(g);
	exit(0);
}

int key_hook(int keycode, void *param)
{
    t_game *g;

    g = (t_game *)param;
    if (g->game_over)
    {
        if (keycode == ESC)
            close_window(g);
        return (0);
    }
	else if (keycode == W)
		move_player(g, 0, -1);
	else if (keycode == S)
		move_player(g, 0, 1);
	else if (keycode == A)
		move_player(g, -1, 0);
	else if (keycode == D)
		move_player(g, 1, 0);	
	return (0);
}

int exit_hook(int keycode, void *param)
{
    t_game *g;

    g = (t_game *)param;
    if (keycode == ESC)
        close_window(g);
    return (0);
}
