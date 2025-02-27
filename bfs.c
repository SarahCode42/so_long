/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 20:58:56 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/27 22:16:18 by jbensimo         ###   ########.fr       */
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

void	process_neighbors(t_game *g, t_queue *queue, int **visited, t_point p)
{
	int		i;
	t_point	directions[4] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

	i = 0;
	while (i < 4)
	{
		int new_x = p.x + directions[i].x;
		int new_y = p.y + directions[i].y;

		if (new_y >= 0 && new_y < g->map_height && new_x >= 0 && new_x < g->map_width
			&& g->map[new_y][new_x] != '1' && !visited[new_y][new_x])
		{
			enqueue(queue, (t_point){new_x, new_y});
			visited[new_y][new_x] = 1;
		}
		i++;
	}
}

void	free_visited(int **visited, int height)
{
	int	i;
	
	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

int	init_bfs_and_run(t_game *g, t_queue *queue, int **visited, char start_char)
{
	t_point	p;

	p.x = g->player_x;
	p.y = g->player_y;
	enqueue(queue, p);
	visited[p.y][p.x] = 1;
	ft_printf("✅ BFS commence à (%d, %d)\n", p.x, p.y);
	if (!queue->top)
	{
		ft_printf("❌ Erreur : %c non trouvé sur la carte\n", start_char);
		return (0);
	}
	while (queue->top)
	{
		p = dequeue(queue);
		ft_printf("BFS explore : (%d, %d) - %c\n", p.x, p.y, g->map[p.y][p.x]);
		if (g->map[p.y][p.x] == 'C')
		{
			g->map_info.collectible_count--;
			ft_printf("Collectible trouvé ! Restants : %d\n", g->map_info.collectible_count);
		}
	
		process_neighbors(g, queue, visited, p);
	}
	return (g->map_info.collectible_count == 0);
}


int bfs(t_game *g, char start_char)
{
	ft_printf("BFS lancé pour : %c\n", start_char);
	int		**visited;
	t_queue	*queue;
	int		result;

	queue = init_queue();
	printf("jai init queue\n");
	if (!queue)
		return (0);
	visited = init_visited(g->map_height, g->map_width);
	printf("jai viseited\n");
	if (!visited)
		return (0);
	result = init_bfs_and_run(g, queue, visited, start_char);
	printf("jai resulat\n");
	free_visited(visited, g->map_height);
	printf("jai free visited\n");
	//free(queue);
	printf("free queue\n");
	return (result);
}


