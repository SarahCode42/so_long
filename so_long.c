/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 10:37:36 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/18 20:34:28 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		fd;

	if (argc != 2)
        return (1);
	mlx = mlx_init();
	if (!mlx)
		return (1);
	win = mlx_new_window(mlx, 1400, 1000, "so_long");
	if (!win)
		return (1);
	fd = open_ber(argv[1]);
	if (fd < 0)
		return (1);
	mlx_hook(win, 17, 0, close_window, NULL);
	mlx_key_hook(win, key_hook, NULL);
	mlx_loop(mlx);
	close(fd);
	return (0);
}
