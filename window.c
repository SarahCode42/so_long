/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/25 18:24:33 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	t_game *g = (t_game *)param;

	free_map(g->map);
	exit(0);
}

void find_player(t_game *g)
{
    int i;
    char *pos;

    i = 0;
    while (g->map[i])
    {
        pos = ft_strchr(g->map[i], 'P'); // 🔍 Cherche 'P' dans la ligne
        if (pos)
        {
            g->player_x = i;
            g->player_y = pos - g->map[i]; // 🔢 Position colonne trouvée
            return;
        }
        i++;
    }
}

int key_hook(int keycode, void *param)
{
    t_game *g = (t_game *)param;

    printf("Touche pressée: %d\n", keycode);

    if (keycode == ESC)
        close_window(g);
    else if (keycode == W)
        move_player(g, -1, 0);
    else if (keycode == S)
        move_player(g, 1, 0);
    else if (keycode == A)
        move_player(g, 0, -1);
    else if (keycode == D)
        move_player(g, 0, 1);
    
    return (0);
}

void move_player(t_game *g, int dx, int dy)
{
    int new_x = g->player_x + dx;
    int new_y = g->player_y + dy;

    if (g->map[new_x][new_y] == '1') // Mur, pas de déplacement
        return;
    
    if (g->map[new_x][new_y] == 'E' && g->collected < g->map_info.collectible_count)
    {
        printf("🚫 La sortie est bloquée ! Il reste des collectibles.\n");
        return; // 🔥 Bloque le passage tant que tous les `C` ne sont pas pris
    }

    if (g->map[new_x][new_y] == 'C') // Collectible ramassé
        g->collected++;

    if (g->map[g->player_x][g->player_y] == 'E') // 🔥 Si on quitte une sortie, elle reste
        g->map[g->player_x][g->player_y] = 'E';
    else
        g->map[g->player_x][g->player_y] = '0';

    g->player_x = new_x;
    g->player_y = new_y;

    if (g->map[new_x][new_y] == 'E' && g->collected == g->map_info.collectible_count)
    {
        printf("🎉 Tous les collectibles ont été pris !\n");
        printf("🏁 Partie terminée !\n");
        close_window(g); // 🔥 Quitte proprement le jeu
    }

    g->map[new_x][new_y] = 'P'; // Déplacer le joueur

    draw_map(g); // 🔥 Redessine la carte après le déplacement
}



