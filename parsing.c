/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 16:09:55 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/20 12:14:19 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	validate_map(t_data *f)
{
	if (!f->map)
		return (0);
	if (!check_walls(f))
		return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
	if (!check_elements(f))
		return (write(2, "Error: Map must have 1 'P', 1 'E', and at least 1 'C'\n", 53), 0);
	return (1);
}

int	check_walls(t_data *f)
{
	int	i;
	int	j;
	int	len;
	int	last;

	len = ft_strlen(f->map[0]);
	if (f->map[0][len - 1] == '\n') // Vérifie si la dernière colonne est un '\n'
		len--; // Ignore le '\n' pour éviter l'erreur
	last = 0;
	while (f->map[last])
		last++;
	last--;
	i = 0;
	while (f->map[i])
	{
		if (ft_strlen(f->map[i]) - (f->map[i][ft_strlen(f->map[i]) - 1] == '\n') != len)
			return (write(2, "Error: Map must be rectangular\n", 31), 0);
		if (f->map[i][0] != '1' || f->map[i][len - 1] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		i++;
	}	
	j = 0;
	while (j < len)
	{
		if (f->map[0][j] != '1' || f->map[last][j] != '1')
			return (write(2, "Error: Map must be enclosed by walls\n", 37), 0);
		j++;
	}
	return (1);
}


int	check_elements(t_data *f)
{
	int i;
	int	j;

	f->map_info.p = 0;
	f->map_info.e = 0;
	f->map_info.c = 0;
	i = 0;
	while (f->map[i])
	{
		j = 0;
		while (f->map[i][j])
		{
			if (f->map[i][j] == 'P')
				f->map_info.p++;
			if (f->map[i][j] == 'E')
				f->map_info.e++;
			if (f->map[i][j] == 'C')
				f->map_info.c++;
			j++;
		}
		i++;
	}
	return (1);
}
