/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/27 13:31:24 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_game *g = (t_game *)param;

	free_map(g->map);
    mlx_destroy_window(g->mlx, g->win);
	exit(0);
}

int	exit_hook(int keycode, void *param)
{
    t_game *g = (t_game *)param;
    if (keycode == ESC)
        close_window(g);
    return (0);
}

int key_hook(int keycode, void *param)
{
    t_game *g = (t_game *)param;

    if (keycode == ESC)
        close_window(g);
    else if (keycode == W)
        move_player(g, -1, 0);
    else if (keycode == S)
        move_player(g, 1, 0);
    else if (keycode == A)
        move_player(g, 0, -1);
    else if (keycode == D)
        move_player(g, 0, 1);
    return (0);
}

/*void display_stats(t_game *g)
{
    char stats[50];
    ft_printf(stats, "Coups: %d | Temps: %d sec", g->moves, (int)difftime(time(NULL), g->start_time));
    mlx_string_put(g->mlx, g->win, 20, 20, 0x0000FF, stats);
}*/
