/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:05 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 12:49:39 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *g)
{
	int		i;
	char	*pos;

	i = 0;
	while (g->map.grille[i])
	{
		pos = ft_strchr(g->map.grille[i], 'P');
		if (pos)
		{
			g->player.x = pos - g->map.grille[i];
			g->player.y = i;
			return ;
		}
		i++;
	}
}

int	can_move(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->map.width || new_y < 0 || new_y >= g->map.height)
		return (0);
	if (g->map.grille[new_y][new_x] == '1')
		return (0);
	if (g->map.grille[new_y][new_x] == 'E'
		&& g->player.collected < g->map.collectible_count)
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
	if (g->map.grille[new_y][new_x] == 'E'
		&& g->player.collected == g->map.collectible_count)
	{
		g->game_over = 1;
		handle_endgame(g);
		return;
	}
	draw_map(g);
}


void	update_player_position(t_game *g, int new_x, int new_y)
{
	if (g->map.grille[new_y][new_x] == 'C')
		g->player.collected++;
	if (g->map.grille[g->player.y][g->player.x] == 'E')
		g->map.grille[g->player.y][g->player.x] = 'E';
	else
		g->map.grille[g->player.y][g->player.x] = '0';
	g->player.x = new_x;
	g->player.y = new_y;
	if (g->map.grille[new_y][new_x] == 'E'
		&& g->player.collected == g->map.collectible_count)
	{
		handle_endgame(g);
		return ;
	}
	g->map.grille[new_y][new_x] = 'P';
}

void handle_endgame(t_game *g)
{
    g->game_over = 1;
    mlx_clear_window(g->mlx, g->window);
    draw_map(g);
    mlx_string_put(g->mlx, g->window, g->map.width * TILE_SIZE / 2 - 70,
        g->map.height * TILE_SIZE / 2, 0x0000FF, "CONGRATULATIONS!");
    mlx_string_put(g->mlx, g->window, g->map.width * TILE_SIZE / 2 - 50,
        g->map.height * TILE_SIZE / 2 + 30, 0x0000FF, "Press ESC to exit.");
    mlx_key_hook(g->window, exit_hook, g);
}
