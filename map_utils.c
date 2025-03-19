/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:39:31 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/19 12:39:23 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_height(t_game *g)
{
	int	width;

	if_not(g->parsing, "Parsing structure is NULL in count_height\n", g);
	g->fd = open_file(g);
	if_not((void *)(long)(g->fd >= 0), "Failed to open map file\n", g);
	g->parsing->height = 0;
	g->line = get_next_line(g->fd);
	while (g->line)
	{
		width = ft_strlen(g->line);
		if (width > 0)
			g->parsing->height++;
		free(g->line);
		g->line = get_next_line(g->fd);
	}
	close(g->fd);
	if_not((void *)(long)(g->parsing->height > 0), "Map file is empty\n", g);
}

int	count_width(t_game *g, int i)
{
	int	len;

	if_not(g->parsing->map[i], "Invalid map row\n", g);
	len = ft_strlen(g->parsing->map[i]);
	if (g->parsing->map[i][len - 1] == '\n')
		len--;
	return (len);
}

void	find_player(t_game *g, int i, int j)
{
	g->player.x = j;
	g->player.y = i;
	g->parsing->player_count++;
}

void	find_exit(t_game *g, int i, int j)
{
	if_not(g, "Game structure is NULL in find_exit\n", NULL);
	g->exit.x = j;
	g->exit.y = i;
	g->parsing->exit_count++;
	if_not((void *)(long)(g->parsing->exit_count == 1),
		"Multiple exit positions found\n", g);
}
