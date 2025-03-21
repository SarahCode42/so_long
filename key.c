/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/19 12:07:07 by jbensimo         ###   ########.fr       */
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

int	key_loop(t_game *g)
{
	usleep(3000);
	g->frame++;
	if (g->frame > 1000000)
		g->frame = 0;
	if (!g->game_over && g->key_pressed != -1 && g->frame % 5 == 0)
	{
		if (g->key_pressed == W)
			move_player(g, 0, -1);
		else if (g->key_pressed == S)
			move_player(g, 0, 1);
		else if (g->key_pressed == A)
			move_player(g, -1, 0);
		else if (g->key_pressed == D)
			move_player(g, 1, 0);
		g->key_pressed = -1;
	}
	return (0);
}

void	key(t_game *g)
{
	if_not(g->window, "Window is NULL in key\n", g);
	if_not(g->mlx, "MLX is NULL in key\n", g);
	g->key_pressed = -1;
	mlx_hook(g->window, 17, 0, close_window, g);
	mlx_hook(g->window, 2, 1L << 0, key_press, g);
	mlx_hook(g->window, 3, 1L << 1, key_release, g);
	mlx_expose_hook(g->window, draw_map, g);
	mlx_loop_hook(g->mlx, key_loop, g);
}
