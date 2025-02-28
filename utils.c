/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:44:20 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/28 15:19:36 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **grille)
{
	int	i;

	i = 0;
	while (grille[i])
		free(grille[i++]);
	free(grille);
}

void	find_exit(t_game *g)
{
	int	y;
	int	x;

	y = 0;
	while (y < g->map.height)
	{
		x = 0;
		while (x < g->map.width)
		{
			if (g->map.grille[y][x] == 'E')
			{
				g->exit.x = x;
				g->exit.y = y;
				return;
			}
			x++;
		}
		y++;
	}
}

void	free_visited(int **visited, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(visited[i++]);
	free(visited);
}

void	error_exit(char *msg, t_game *g)
{
	if (g)
		free_map(g->map.grille);
	free(g);
	write(2, msg, ft_strlen(msg));
	exit(1);
}
