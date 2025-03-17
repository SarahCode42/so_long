/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:39:31 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/17 14:29:19 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_height(t_game *g)
{
	char	*line;

	if_not(g->parsing, "Parsing structure is NULL in count_height\n", g, free_game);
	if_not((void *)(long)(open_file(g) >= 0), "Failed to open map file\n", g, free_parsing);
	g->parsing->height = 0;
	line = get_next_line(g->fd);
	while (line)
	{
		if_not((void *)(long)(ft_strlen(line) > 1), "Map contains an empty line\n", g, free_parsing);
		g->parsing->height++;
		free(line);
		line = get_next_line(g->fd);
	}
	close(g->fd);
	if_not((void *)(long)(g->parsing->height > 0), "Map file is empty\n", g, free_parsing);
}

int	count_width(t_game *g, int i)
{
	int	len;

	if_not(g->parsing->map[i], "Invalid map row\n", g, free_parsing);
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
	if_not(g, "Game structure is NULL in find_exit\n", NULL, NULL);
	g->exit.x = j;
	g->exit.y = i;
	g->parsing->exit_count++;
	if_not((void *)(long)(g->parsing->exit_count == 1), "Multiple exit positions found\n", g, free_parsing);
}
