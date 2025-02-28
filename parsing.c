/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:09:55 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 12:46:13 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *g)
{
	int original_collectible_count;
	int i;

	i = 0;
	if (!g->map.grille)
		return (0);
	while (g->map.grille[i])
	{
		i++;
	}
	if (!check_walls(g))
		return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
	if (!check_elements(g))
		return (write(2, "Error: Map must have 1 'P', 1 'E', and at least 1 'C'\n", 53), 0);
	find_player(g);
	original_collectible_count = g->map.collectible_count;
	if (!init_dfs_and_run(g, g->player.x, g->player.y))
		return (write(2, "Error: Not all collectibles are reachable\n", 41), 0);
	g->map.collectible_count = original_collectible_count;
	if (!init_dfs_and_run(g, g->exit.x, g->exit.y))
		return (write(2, "Error: The exit is not reachable\n", 33), 0);
	return (1);
}

int	check_walls(t_game *g)
{
	int	i;
	int	j;
	int	len;
	int	last;

	len = ft_strlen(g->map.grille[0]);
	if (g->map.grille[0][len - 1] == '\n')
		len--;
	last = 0;
	while (g->map.grille[last])
		last++;
	last--;
	i = 0;
	while (g->map.grille[i])
	{
		if (ft_strlen(g->map.grille[i]) - (g->map.grille[i][ft_strlen(g->map.grille[i]) - 1] == '\n') != len)
			return (write(2, "Error: Map must be rectangular\n", 31), 0);
		if (g->map.grille[i][0] != '1' || g->map.grille[i][len - 1] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		i++;
	}	
	j = 0;
	while (j < len)
	{
		if (g->map.grille[0][j] != '1' || g->map.grille[last][j] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		j++;
	}
	return (1);
}

int	check_elements(t_game *g)
{
	int	i;
	int	j;

	g->map.player_count = 0;
	g->map.exit_count = 0;
	g->map.collectible_count = 0;
	i = 0;
	while (g->map.grille[i])
	{
		j = 0;
		while (g->map.grille[i][j])
		{
			if (g->map.grille[i][j] == 'P')
				g->map.player_count++;
			if (g->map.grille[i][j] == 'E')
				g->map.exit_count++;
			if (g->map.grille[i][j] == 'C')
				g->map.collectible_count++;
			j++;
		}
		i++;
	}
	return (1);
}
