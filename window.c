/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 12:45:58 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#include "so_long.h"

int	close_window(void *param)
{
	t_game	*g;

	g = (t_game *)param;
	free_map(g->map.grille);
	mlx_destroy_window(g->mlx, g->window);
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
