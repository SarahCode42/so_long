/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:05 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/16 15:26:35 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->parsing->width || new_y < 0 || new_y >= g->parsing->height)
		return (0);
	if (!g->parsing->map[new_y] || !g->parsing->map[new_y][new_x])
		return (0);
	if (g->parsing->map[new_y][new_x] == '1')
		return (0);
	if (g->parsing->map[new_y][new_x] == 'E'
		&& g->player.collected < g->parsing->collect_count)
		return (0);

	return (1);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	if (g->game_over)
		return;
	new_x = g->player.x + dx;
	new_y = g->player.y + dy;
	if (!can_move(g, new_x, new_y))
		return ;
	g->player.moves++;
	update_player_position(g, new_x, new_y);
	if (g->parsing->map[new_y][new_x] == 'E' && g->player.collected == g->parsing->collect_count)
	{
		ft_printf("Level completed! in %d moves\n", g->player.moves);
		#ifdef __APPLE__
			exit(0);
		#else
			mlx_loop_end(g->mlx);
		#endif
		return;
	}
	draw_map(g);
	draw_moves(g);
}

void	update_player_position(t_game *g, int new_x, int new_y)
{
	if_not(g->parsing->map, "Map structure is NULL in update_player_position\n", g, free_game);
	if (new_x < 0 || new_x >= g->parsing->width || new_y < 0 || new_y >= g->parsing->height)
		return ;
	if (g->parsing->map[new_y][new_x] == 'C')
		g->player.collected++;
	if (g->parsing->map[g->player.y][g->player.x] != 'E')
		g->parsing->map[g->player.y][g->player.x] = '0';
	g->player.x = new_x;
	g->player.y = new_y;
	if (g->parsing->map[new_y][new_x] != 'E')
		g->parsing->map[new_y][new_x] = 'P';
}
