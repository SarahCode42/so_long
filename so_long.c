/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/20 12:56:14 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

int	main(int argc, char **argv)
{
	t_data	*f;

	if (argc != 2)
		return (1);
	f = ft_calloc(1, sizeof(t_data));
	if (!f)
		return (1);
	f->filename = argv[1];
	f->mlx = mlx_init();
	if (!f->mlx)
		return (free_map(f->map), 1);
	f->win = mlx_new_window(f->mlx, 1400, 1000, "so_long");
	if (!f->win)
		return (free_map(f->map), 1);
	f->map = load_map(f);
	if (!validate_map(f))
		return (free_map(f->map), 1);
	load_map(f);
	draw_map(f);
	mlx_hook(f->win, 17, 0, close_window, f);
	mlx_key_hook(f->win, key_hook, f);
	mlx_loop(f->mlx);
	return (0);
}
