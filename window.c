/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/24 19:18:08 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_game *g = (t_game *)param;

	free_map(g->map);
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	t_game *g = (t_game *)param;

	if (keycode == 65307) // Touche ESC
	{
		free_map(g->map);
		exit(0);
	}
	if (keycode == 119) // Touche W (haut)
		move_player(g, 0, -1);
	if (keycode == 115) // Touche S (bas)
		move_player(g, 0, 1);
	if (keycode == 97) // Touche A (gauche)
		move_player(g, -1, 0);
	if (keycode == 100) // Touche D (droite)
		move_player(g, 1, 0);
	return (0);
}
