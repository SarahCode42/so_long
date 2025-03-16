/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:52:29 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/16 15:39:34 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	free(map);
	map = NULL;
}

void	free_visited(t_game *g)
{
	int	i;

	if (!g || !g->parsing || !g->parsing->visited)
		return;
	i = 0;
	while (i < g->parsing->height)
	{
		free(g->parsing->visited[i]);
		g->parsing->visited[i] = NULL;
		i++;
	}
	free(g->parsing->visited);
	g->parsing->visited = NULL;
}

void	free_parsing(t_game *g)
{
	if (!g || !g->parsing)
		return;
	if (g->parsing->visited)
	{
		free_visited(g);
		g->parsing->visited = NULL;
	}
	free(g->parsing);
	g->parsing = NULL;
}

void	free_textures(t_game *g)
{
	if (!g || !g->textures)
		return;
	if (g->textures->wall)
		mlx_destroy_image(g->mlx, g->textures->wall);
	if (g->textures->floor)
		mlx_destroy_image(g->mlx, g->textures->floor);
	if (g->textures->player)
		mlx_destroy_image(g->mlx, g->textures->player);
	if (g->textures->collectible)
		mlx_destroy_image(g->mlx, g->textures->collectible);
	if (g->textures->exit)
		mlx_destroy_image(g->mlx, g->textures->exit);
	free(g->textures);
	g->textures = NULL;
}

void	free_game(t_game *g)
{
	if (!g)
		return;
	if (g->parsing->visited)
	{
		free_parsing(g);
		g->parsing->visited = NULL;
	}
	free_textures(g);
	if (g->window)
	{
		mlx_destroy_window(g->mlx, g->window);
		g->window = NULL;
	}
	if (g->mlx)
	{
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		g->mlx = NULL;
	}
	if (g->filename)
	{
		free(g->filename);
		g->filename = NULL;
	}
	free(g);
}
