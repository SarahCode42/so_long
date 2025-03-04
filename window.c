/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/05 00:06:35 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    if (keycode == ESC)
		close_window(g);
	if (g->game_over)
		return (0);
	if (keycode == W)
		move_player(g, 0, -1);
	else if (keycode == S)
		move_player(g, 0, 1);
	else if (keycode == A)
		move_player(g, -1, 0);
	else if (keycode == D)
		move_player(g, 1, 0);	
	return (0);
}
