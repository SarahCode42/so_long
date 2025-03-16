/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 10:44:20 by jbensimo          #+#    #+#             */
/*   Updated: 2025/03/16 15:46:51 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *msg)
{
	write(2, "Error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(EXIT_FAILURE);
}

int	open_file(t_game *g)
{
	g->fd = open(g->filename, O_RDONLY);
	if_not((void *)(long)(g->fd >= 0), "Failed to open map file\n", g, free_parsing);
	return (g->fd);
}

int	close_file(t_game *g, int lines_read, int total_lines)
{
	close(g->fd);
	if_not((void *)(long)(lines_read == total_lines), "Map file is incomplete\n", g, free_parsing);
	return (0);
}

int	close_window(t_game *g)
{
	free_game(g);
	#ifdef __APPLE__
		exit(0);
	#else
		mlx_loop_end(g->mlx);
	#endif
	return (0);
}

int	if_not(void *ptr, char *msg, t_game *g, void (*free_func)(t_game *))
{
	if (!ptr)
	{
		if (free_func)
			free_func(g);
		error_exit(msg);
	}
	return (0);
}
