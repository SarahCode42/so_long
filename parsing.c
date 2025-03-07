/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:09:55 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 18:05:04 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_walls(t_game *g)
{
	int	i;
	int	j;

	g->pars.width = count_width(g, 0);
	i = 0;
	while (i < g->pars.height)
	{
		if (count_width(g, i) != g->pars.width)
			error_exit("Map must be rectangular\n", g);
		if (g->pars.map[i][0] != '1' || g->pars.map[i][g->pars.width - 1] != '1')
			error_exit("Map must be enclosed by walls\n", g);
		i++;
	}
	j = 0;
	while (j < g->pars.width)
	{
		if (g->pars.map[0][j] != '1' || g->pars.map[g->pars.height - 1][j] != '1')
			error_exit("Map must be enclosed by walls\n", g);
		j++;
	}
	return (1);
}

int	check_elements(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->pars.map[i])
	{
		j = 0;
		while (g->pars.map[i][j])
		{
			if (g->pars.map[i][j] == 'P')
				find_player(g, i, j);
			if (g->pars.map[i][j] == 'E')
				find_exit(g, i, j);
			if (g->pars.map[i][j] == 'C')
				g->pars.collect_count++;
			j++;
		}
		i++;
	}
	if (g->pars.player_count != 1 || g->pars.exit_count != 1 || g->pars.collect_count <= 0)
		return (0);
	return (1);
}

int	check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4 || ft_strncmp(filename + len - 4, ".ber", 4) != 0)
		return (0);
	return (1);
}

void	parsing(t_game *g)
{
	if (!check_extension(g->filename))
		error_exit("Map file must have a .ber extension\n", g);
	g->fd = open_file(g);
	load_map(g);
	if (!g->pars.map)
		error_exit("Map is empty\n", g);
	check_walls(g);
	if (!check_elements(g))
		error_exit("Map must have 1 'P', 1 'E', and at least 1 'C'\n", g);
	if (!dfs(g))
		error_exit("Not all collectibles are accessible\n", g);
	free_visited(g);
}
