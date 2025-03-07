/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:34:05 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 15:01:29 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->pars.width || new_y < 0 || new_y >= g->pars.height)
		return (0);
	if (g->pars.map[new_y][new_x] == '1')
		return (0);
	if (g->pars.map[new_y][new_x] == 'E'
		&& g->player.collected < g->pars.collect_count)
		return (0);
	return (1);
}

void	move_player(t_game *g, int dx, int dy)
{
	int	new_x;
	int	new_y;

	new_x = g->player.x + dx;
	new_y = g->player.y + dy;
	if (g->game_over || !can_move(g, new_x, new_y))
		return;
	g->player.moves++;
	update_player_position(g, new_x, new_y);
	if (g->pars.map[new_y][new_x] == 'E' && g->player.collected == g->pars.collect_count)
	{
		ft_printf("Level completed! in %d moves\n", g->player.moves);
		g->game_over = 1;
		#ifdef __APPLE__
			exit(0);  // MacOS
		#else
			mlx_loop_end(g->mlx);  // Linux
		#endif
	}
	draw_map(g);
	draw_moves(g);
}

void	update_player_position(t_game *g, int new_x, int new_y)
{
	if (g->pars.map[new_y][new_x] == 'C')
		g->player.collected++;
	if (g->pars.map[g->player.y][g->player.x] != 'E')
		g->pars.map[g->player.y][g->player.x] = '0';
	g->player.x = new_x;
	g->player.y = new_y;
	if (g->pars.map[new_y][new_x] != 'E')
		g->pars.map[new_y][new_x] = 'P';
}

void next_level(t_game *g)
{
    char    *level_str;
    char    new_level[30];
    
    g->level++;
    level_str = ft_itoa(g->level);
    if (!level_str)
        error_exit("Memory allocation failed\n", g);
    ft_strlcpy(new_level, "maps/level_", 30);
    ft_strlcat(new_level, level_str, 30);
    ft_strlcat(new_level, ".ber", 30);
    free(level_str);
    g->fd = open(new_level, O_RDONLY);
    if (g->fd < 0)
    {
        g->game_over = 1;
        return;
    }
    close(g->fd);
    free_map(g);
    parsing(g);
    draw_map(g);
}
