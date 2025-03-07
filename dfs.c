/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:58:56 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 17:48:48 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_visited(t_game *g)
{
	int	i;

	g->pars.visited = ft_calloc(g->pars.height, sizeof(int *));
	if (!g->pars.visited)
		return ;
	i = 0;
	while (i < g->pars.height)
	{
		g->pars.visited[i] = ft_calloc(g->pars.width, sizeof(int));
		if (!g->pars.visited[i])
		{
			while (--i >= 0)
				free(g->pars.visited[i]);
			free(g->pars.visited);
			return ;
		}
		i++;
	}
}

void	dfs_recurs(t_game *g, int x, int y)
{
	if (x < 0 || x >= g->pars.width || y < 0 || y >= g->pars.height ||
		g->pars.map[y][x] == '1' || g->pars.visited[y][x])
		return ;
	g->pars.visited[y][x] = 1;
	dfs_recurs(g, x + 1, y);
	dfs_recurs(g, x - 1, y);
	dfs_recurs(g, x, y + 1);
	dfs_recurs(g,x, y - 1);
}

void	check_accessibility(t_game *g)
{
    int	x;
    int	y;

	if (g->pars.visited[g->player.y][g->player.x] == 0)
		error_exit("Player is blocked\n",g);
	if (g->pars.visited[g->exit.y][g->exit.x] == 0)
		error_exit("Exit is not accessible\n", g);
    y = 0;
    while (y < g->pars.height)
    {
        x = 0;
        while (x < g->pars.width)
        {
			if (g->pars.map[y][x] == 'C' && g->pars.visited[y][x] == 0)
				error_exit("Not all collectibles are accessible\n", g);
            x++;
        }
        y++;
    }
}

int	dfs(t_game *g)
{
	init_visited(g);
	dfs_recurs(g, g->player.x, g->player.y);
	check_accessibility(g);
	free_visited(g);
	return (1);
}
