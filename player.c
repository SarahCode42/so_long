/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:05 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/27 15:50:13 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void find_player(t_game *g)
{
    int i;
    char *pos;

    i = 0;
    while (g->map[i])
    {
        pos = ft_strchr(g->map[i], 'P');
        if (pos)
        {
            g->player_x = i;
            g->player_y = pos - g->map[i];
            return ;
        }
        i++;
    }
}

int can_move(t_game *g, int new_x, int new_y)
{
    if (g->map[new_x][new_y] == '1')
        return (0);
    if (g->map[new_x][new_y] == 'E' && g->collected < g->map_info.collectible_count)
    {
        ft_printf("La sortie est bloquée ! Il reste des collectibles.\n");
        return (0);
    }
    return (1);
}

void update_player_position(t_game *g, int new_x, int new_y)
{
    if (g->map[new_x][new_y] == 'C')
        g->collected++;

    if (g->map[g->player_x][g->player_y] == 'E')
        g->map[g->player_x][g->player_y] = 'E';
    else
        g->map[g->player_x][g->player_y] = '0';

    g->player_x = new_x;
    g->player_y = new_y;

    if (g->map[new_x][new_y] == 'E' && g->collected == g->map_info.collectible_count)
    {
        handle_endgame(g);
        return;
    }

    g->map[new_x][new_y] = 'P'; 
}

void handle_endgame(t_game *g)
{
    mlx_clear_window(g->mlx, g->win);
    draw_map(g);
    mlx_string_put(g->mlx, g->win, g->map_width * TILE_SIZE / 2 - 70, g->map_height * TILE_SIZE / 2, 0x0000FF, "CONGRATULATIONS!");
    mlx_string_put(g->mlx, g->win, g->map_width * TILE_SIZE / 2 - 50, g->map_height * TILE_SIZE / 2 + 30, 0x0000FF, "Press ESC to exit.");
    mlx_key_hook(g->win, exit_hook, g);
}

void move_player(t_game *g, int dx, int dy)
{
    int new_x;
	int new_y;
	
	new_x = g->player_x + dx;
    new_y = g->player_y + dy;
    if (!can_move(g, new_x, new_y))
        return;
    g->moves++;
    update_player_position(g, new_x, new_y);
    if (g->map[new_x][new_y] == 'E' && g->collected == g->map_info.collectible_count)
    {
        handle_endgame(g);
        return ;
    }
    draw_map(g);
}

