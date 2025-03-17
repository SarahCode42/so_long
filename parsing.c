/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:09:55 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/17 14:29:57 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_game *g)
{
	int	i;
	int	j;
	g->parsing->width = count_width(g, 0);
	i = 0;
	while (i < g->parsing->height)
	{
		if_not((void *)(long)(count_width(g, i) == g->parsing->width), 
			"Map must be rectangular\n", g, free_parsing);
		if_not((void *)(long)(g->parsing->map[i][0] == '1' && g->parsing->map[i][g->parsing->width - 1] == '1'),
			"Map must be enclosed by walls\n", g, free_parsing);
		i++;
	}
	j = 0;
	while (j < g->parsing->width)
	{
		if_not((void *)(long)(g->parsing->map[0][j] == '1' && g->parsing->map[g->parsing->height - 1][j] == '1'),
			"Map must be enclosed by walls\n", g, free_parsing);
		j++;
	}
}

void	parse_map_line(t_game *g, int i)
{
	int	j;
	int	len;

	j = 0;
	len = ft_strlen(g->parsing->map[i]);
	while (j < len)
	{
		char c = g->parsing->map[i][j];
		if (c == '\n' && j != len - 1)
			if_not(0, "Map contains misplaced newline characters\n", g, free_parsing);
		else if (c == 'P')
			find_player(g, i, j);
		else if (c == 'E')
			find_exit(g, i, j);
		else if (c == 'C')
			g->parsing->collect_count++;
		else if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && (c != '\n' || j != len - 1))
			if_not(0, "Map contains invalid characters\n", g, free_parsing);
		j++;
	}
}

int	check_elements(t_game *g)
{
	int	i;

	i = 0;
	while (g->parsing->map[i])
	{
		parse_map_line(g, i);
		i++;
	}
	if_not((void *)(long)(g->parsing->player_count == 1 && g->parsing->exit_count == 1 && g->parsing->collect_count > 0),
		"Map must have 1 'P', 1 'E', and at least 1 'C'\n", g, free_parsing);
	return (1);
}

void	check_extension(char *filename, t_game *g)
{
	int	len;

	len = ft_strlen(filename);
	if_not((void *)(long)(len >= 4 && ft_strncmp(filename + len - 4, ".ber", 4) == 0),
		"Map file must have a .ber extension\n", g, free_parsing);
}

void	parsing(t_game *g)
{
	g->parsing = ft_calloc(1, sizeof(t_parsing));
	if_not(g->parsing, "Memory allocation failed for parsing\n", g, free_game);
	check_extension(g->filename, g);
	g->fd = open_file(g);
	load_map(g);
	check_walls(g);
	if_not((void *)(long)(check_elements(g)), "Map must have 1 'P', 1 'E', and at least 1 'C'\n", g, free_parsing);
	if_not((void *)(long)(dfs(g)), "Not all collectibles are accessible\n", g, free_parsing);
}
