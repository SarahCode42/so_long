/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/25 19:16:34 by jbensimo         ###   ########.fr       */
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
        return;
    }

    g->moves++; // 🔥 Compte le déplacement

    if (g->map[new_x][new_y] == 'C') 
        g->collected++;

    if (g->map[g->player_x][g->player_y] == 'E') 
        g->map[g->player_x][g->player_y] = 'E';
    else
        g->map[g->player_x][g->player_y] = '0';

    g->player_x = new_x;
    g->player_y = new_y;
	if (g->map[new_x][new_y] == 'E' && g->collected == g->map_info.collectible_count)
	{
		printf("🎉 Tous les collectibles récupérés !\n");
		printf("🏁 Partie terminée !\n");
	
		// 🔥 Supprimer le joueur et restaurer la sortie
		g->map[g->player_x][g->player_y] = '0'; // Ancienne position devient vide
		g->map[new_x][new_y] = 'E'; // La sortie reste visible
	
		// 🔥 Afficher le message de victoire
		mlx_clear_window(g->mlx, g->win); // Efface l'affichage avant d'écrire
		draw_map(g); // 🔥 Redessine la carte SANS le joueur
		mlx_string_put(g->mlx, g->win, g->map_width * TILE_SIZE / 2 - 70, g->map_height * TILE_SIZE / 2, 0x0000FF, "CONGRATULATIONS!");
		mlx_string_put(g->mlx, g->win, g->map_width * TILE_SIZE / 2 - 50, g->map_height * TILE_SIZE / 2 + 30, 0x0000FF, "Press ESC to exit.");
	
		// 🔥 Bloquer les mouvements
		mlx_key_hook(g->win, exit_hook, g); // 🔥 Seul ESC fonctionne après la victoire
	
		return; // 🔥 Ne pas exécuter `draw_map(g)` après pour éviter de redessiner `P`
	}

    g->map[new_x][new_y] = 'P'; 
    draw_map(g); // Redessine la carte après le déplacement
	display_stats(g); // 🔥 Met à jour les stats sur la fenêtre
}

void display_stats(t_game *g)
{
    char stats[50];
    sprintf(stats, "Coups: %d | Temps: %d sec", g->moves, (int)difftime(time(NULL), g->start_time));

    //mlx_string_put(g->mlx, g->win, 20, 20, 0xFFFFFF, "STATISTIQUES :");
    mlx_string_put(g->mlx, g->win, 20, 20, 0x0000FF, stats); // Affiche les stats en rouge
}

int	exit_hook(int keycode, void *param)
{
    t_game *g = (t_game *)param;
    if (keycode == 65307) // 🔥 Code de ESC (Linux) -> Quitte le jeu
        close_window(g);
    return (0);
}



