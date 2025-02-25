/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:09:55 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/25 18:00:40 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_game *g)
{
	if (!g->map)
		return (0);
	if (!check_walls(g))
		return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
	if (!check_elements(g))
		return (write(2, "Error: Map must have 1 'P', 1 'E', and at least 1 'C'\n", 53), 0);
	return (1);
}

int	check_walls(t_game *g)
{
	int	i;
	int	j;
	int	len;
	int	last;

	len = ft_strlen(g->map[0]);
	if (g->map[0][len - 1] == '\n') // Vérifie si la dernière colonne est un '\n'
		len--; // Ignore le '\n' pour éviter l'erreur
	last = 0;
	while (g->map[last])
		last++;
	last--;
	i = 0;
	while (g->map[i])
	{
		if (ft_strlen(g->map[i]) - (g->map[i][ft_strlen(g->map[i]) - 1] == '\n') != len)
			return (write(2, "Error: Map must be rectangular\n", 31), 0);
		if (g->map[i][0] != '1' || g->map[i][len - 1] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		i++;
	}	
	j = 0;
	while (j < len)
	{
		if (g->map[0][j] != '1' || g->map[last][j] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		j++;
	}
	return (1);
}


int	check_elements(t_game *g)
{
	int i;
	int	j;

	g->map_info.player_count = 0;
	g->map_info.exit_count = 0;
	g->map_info.collectible_count = 0;
	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
				g->map_info.player_count++;
			if (g->map[i][j] == 'E')
				g->map_info.exit_count++;
			if (g->map[i][j] == 'C')
				g->map_info.collectible_count++;
			j++;
		}
		i++;
	}
	return (1);
}
