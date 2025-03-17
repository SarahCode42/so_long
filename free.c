/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:52:29 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/17 15:13:13 by jbensimo         ###   ########.fr       */
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
	if (g->parsing->map)
	{
		free_map(g->parsing->map);
		g->parsing->map = NULL;
	}
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
	if (g->textures->background)
		mlx_destroy_image(g->mlx, g->textures->background);
	if (g->textures->player)
		mlx_destroy_image(g->mlx, g->textures->player);
	if (g->textures->exit)
		mlx_destroy_image(g->mlx, g->textures->exit);
	if (g->textures->collectible)
		mlx_destroy_image(g->mlx, g->textures->collectible);
	free(g->textures);
	g->textures = NULL;
}

void	free_game(t_game *g)
{
	if (!g)
		return;
	if (g->parsing)
	{
		free_parsing(g);
		g->parsing = NULL;
	}
	if (g->textures)
	{
		free_textures(g);
		g->textures = NULL;
	}
	if (g->img) // Suppression d'une éventuelle image unique
	{
		mlx_destroy_image(g->mlx, g->img);
		g->img = NULL;
	}
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
	g = NULL;
}


