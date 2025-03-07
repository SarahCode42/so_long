/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 17:49:05 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_game *g)
{
	if (keycode == ESC)
		close_window(g);
	if (!g->game_over)
		g->key_pressed = keycode;
	return (0);
}

int	key_release(int keycode, t_game *g)
{
	if (g->key_pressed == keycode)
		g->key_pressed = -1;
	return (0);
}

int get_time()
{
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

int key_loop(t_game *g)
{
	int current_time;
	
	current_time = get_time();

	if (!g->game_over && g->key_pressed != -1 && (current_time - g->last_move_time > 150))
	{
		g->last_move_time = current_time;
		if (g->key_pressed == W)
			move_player(g, 0, -1);
		else if (g->key_pressed == S)
			move_player(g, 0, 1);
		else if (g->key_pressed == A)
			move_player(g, -1, 0);
		else if (g->key_pressed == D)
			move_player(g, 1, 0);
	}
	return (0);
}

void	key(t_game *g)
{
	g->key_pressed = -1;

	mlx_hook(g->window, 17, 0, close_window, g);
	mlx_hook(g->window, 2, 1L<<0, key_press, g);
	mlx_hook(g->window, 3, 1L<<1, key_release, g);
	mlx_expose_hook(g->window, draw_map, g);
	mlx_loop_hook(g->mlx, key_loop, g);
}
