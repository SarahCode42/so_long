/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:58:56 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/17 19:15:16 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_visited(t_game *g)
{
	int	i;

	g->parsing->visited = ft_calloc(g->parsing->height, sizeof(int *));
	if_not(g->parsing->visited, "Memory allocation failed for visited array\n", g);
	i = 0;
	while (i < g->parsing->height)
	{
		g->parsing->visited[i] = ft_calloc(g->parsing->width, sizeof(int));
		if_not(g->parsing->visited[i], "Memory allocation failed for visited row\n", g);
		i++;
	}
}

void dfs_recurs(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->parsing->width || y < 0 || y >= g->parsing->height ||
		g->parsing->map[y][x] == '1' || g->parsing->visited[y][x])
		return ;
	if (g->parsing->map[y][x] == 'E')
	{
		g->parsing->visited[y][x] = 1;
		return ;
	}
	g->parsing->visited[y][x] = 1;
	if (g->parsing->map[y][x] == 'C')
		g->parsing->collectibles_found++;
	dfs_recurs(g, x + 1, y);
	dfs_recurs(g, x - 1, y);
	dfs_recurs(g, x, y + 1);
	dfs_recurs(g, x, y - 1);
}

void check_accessibility(t_game *g)
{
	if_not((void *)(long)(g->parsing->collectibles_found == g->parsing->collect_count),
		"Not all collectibles are accessible\n", g);
	if_not((void *)(long)g->parsing->visited[g->exit.y][g->exit.x],
		"Exit is blocked, cannot access all collectibles\n", g);
	if_not((void *)(long)g->parsing->visited[g->player.y][g->player.x],
		"Player is blocked\n", g);
}

int	dfs(t_game *g)
{
	g->parsing->collectibles_found = 0;
	init_visited(g);
	dfs_recurs(g, g->player.x, g->player.y);
	check_accessibility(g);
	free_visited(g);
	return (1);
}
