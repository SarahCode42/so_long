/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 12:19:17 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/20 17:11:53 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_data *f)
{
	int i;
	int j;

	i = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == '1')
				mlx_put_image_to_window(f->mlx, f->win, f->textures.wall, j * 32, i * 32);
			if (f->map[i][j] == 'P')
				mlx_put_image_to_window(f->mlx, f->win, f->textures.player, j * 32, i * 32);
			if (f->map[i][j] == 'E')
				mlx_put_image_to_window(f->mlx, f->win, f->textures.exit, j * 32, i * 32);
			if (f->map[i][j] == 'C')
				mlx_put_image_to_window(f->mlx, f->win, f->textures.collectible, j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	load_textures(t_data *f)
{
	int	width;
	int	height;

	f->textures.wall = mlx_xpm_file_to_image(f->mlx, "textures/wall.xpm", &width, &height);
	f->textures.player = mlx_xpm_file_to_image(f->mlx, "textures/wall.xpm", &width, &height);
	f->textures.exit = mlx_xpm_file_to_image(f->mlx, "textures/wall.xpm", &width, &height);
	f->textures.collectible = mlx_xpm_file_to_image(f->mlx, "textures/wall.xpm", &width, &height);
	if (!(f->textures.wall || f->textures.player || f->textures.exit || f->textures.collectible))
	{
		write(2, "Error: Failed to load textures\n", 31);
		exit(1);
	}
}
