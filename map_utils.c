/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 19:39:31 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/04 15:54:23 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_height(t_game *g)
{
	char	*line;

	open_file(g);
	line = get_next_line(g->fd);
	while (line)
	{
		free(line);
		g->pars.height++;
		line = get_next_line(g->fd);
	}
	close(g->fd);
	g->fd = -1;
}

int	count_width(t_game *g, int i)
{
	int	len;

	if (!g->pars.map[i])
		return (0);
	len = ft_strlen(g->pars.map[i]);
	if (g->pars.map[i][len - 1] == '\n')
		len--;
	return (len);
}

void	find_player(t_game *g, int i, int j)
{
	g->player.x = j;
	g->player.y = i;
	g->pars.player_count++;
}

void	find_exit(t_game *g, int i, int j)
{
	g->exit.x = j;
	g->exit.y = i;
	g->pars.exit_count++;
}
