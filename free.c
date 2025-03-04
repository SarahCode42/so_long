/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:52:29 by YonathanetS       #+#    #+#             */
/*   Updated: 2025/03/04 15:27:14 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *g)
{
	int	i;

	i = 0;
	while (g->pars.map[i])
		free(g->pars.map[i++]);
	free(g->pars.map);
}

void	free_visited(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->pars.height)
		free(g->pars.visited[i++]);
	free(g->pars.visited);
}