/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:58:56 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/02 00:29:17 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	**init_visited(int height, int width)
{
	int	**visited;
	int	i;

	visited = malloc(height * sizeof(int *));
	if (!visited)
		return (NULL);
	i = 0;
	while (i < height)
	{
		visited[i] = malloc(width * sizeof(int));
		if (!visited[i])
		{
			while (--i >= 0)
				free(visited[i]);
			free(visited);
			return (NULL);
		}
		ft_memset(visited[i], 0, width * sizeof(int));
		i++;
	}
	return (visited);
}

void	dfs(t_game *g, int **visited, int x, int y)
{
	if (x < 0 || x >= g->map.width || y < 0 || y >= g->map.height ||
		g->map.grille[y][x] == '1' || visited[y][x])
		return ;
	visited[y][x] = 1;
	dfs(g, visited, x + 1, y);
	dfs(g, visited, x - 1, y);
	dfs(g, visited, x, y + 1);
	dfs(g, visited, x, y - 1);
}

int	check_accessibility(t_game *g, int **visited)
{
    int	x;
    int	y;

    y = 0;
    while (y < g->map.height)
    {
        x = 0;
        while (x < g->map.width)
        {
            if (g->map.grille[y][x] == 'C' || g->map.grille[y][x] == 'E')
            {
                if (!visited[y][x])
                {
                    ft_printf("Element %c inaccesssible at (%d, %d)\n", g->map.grille[y][x], x, y);
                    return (0);
                }
                else
                {
                    ft_printf("Element %c accessible at (%d, %d)\n", g->map.grille[y][x], x, y);
                }
            }
            x++;
        }
        y++;
    }
    return (1);
}

int	init_dfs_and_run(t_game *g, int start_x, int start_y)
{
	int	**visited;
	int	accessible;

	visited = init_visited(g->map.height, g->map.width);
	if (!visited)
		return (0);
	dfs(g, visited, start_x, start_y);
	accessible = check_accessibility(g, visited);
	free_visited(visited, g->map.height);
	return (accessible);
}
