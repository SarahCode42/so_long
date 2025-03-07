/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: YonathanetSarah <YonathanetSarah@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:44:20 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/07 13:51:06 by YonathanetS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg, t_game *g)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	if (g)
	{
		if (g->fd >= 0)
			close(g->fd);
		if (g->pars.map)
			free_map(g);
		if (g->pars.visited)
			free_visited(g);
		free(g);
	}
	exit(EXIT_FAILURE);
}

int open_file(t_game *g)
{
    g->fd = open(g->filename, O_RDONLY);
    if (g->fd < 0)
        return (-1);
    return (g->fd);
}

int close_file(t_game *g, int lines_read, int total_lines)
{
    close(g->fd);
    if (lines_read != total_lines)
        return (-1);
    return (0);
}

int	close_window(t_game *g)
{
	destroy_textures(g);
	if (g->window)
		mlx_destroy_window(g->mlx, g->window);
	if (g->mlx)
	{
		//mlx_destroy_display(g->mlx); //linux
		free(g->mlx);
	}
	if (g->pars.map)
		free_map(g);
	exit(0);
}
