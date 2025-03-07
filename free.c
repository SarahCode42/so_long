/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:52:29 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/07 17:48:19 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *g)
{
	int	i;

	if (!g->pars.map)
		return ;
	i = 0;
	while (g->pars.map[i])
		free(g->pars.map[i++]);
	free(g->pars.map);
	g->pars.map = NULL;
}

void	free_visited(t_game *g)
{
	int	i;

	if (!g->pars.visited)
		return;
	i = 0;
	while (i < g->pars.height)
	{
		free(g->pars.visited[i]);
		i++;
	}
	free(g->pars.visited);
	g->pars.visited = NULL;
}
