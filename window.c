/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:16:38 by jbensimo          #+#    #+#             */
/*   Updated: 2025/02/19 19:07:20 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(void *param)
{
	(void)param;
	exit(0);
}

int	key_hook(int keycode, void *param)
{
	(void)param;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	open_ber(t_data *f)
{
	f->fd = open(f->filename, O_RDONLY);
	if (f->fd < 0)
	{
		write(2, "Error: cannot open file\n", 24);
		return (-1);
	}
	return (f->fd);
}

int	count_lines(t_data *f)
{
	int		count;
	int		fd;
	char	*line;

	count = 0;
	fd = open(f->filename, O_RDONLY); // ✅ Ouvre le fichier
	if (fd == -1)
		return (-1); // ✅ Vérifie si le fichier existe

	line = get_next_line(fd);
	while (line)
	{
		free(line);
		count++;
		line = get_next_line(fd);
	}
	close(fd); // ✅ Ferme le fichier après lecture
	return (count);
}


char	**load_map(t_data *f)
{
	char	*line;
	int		i;
	int		lines;

	lines = count_lines(f);
	if (lines <= 0)
		return (NULL);
	f->fd = open(f->filename, O_RDONLY);
	if (f->fd < 0)
		return (NULL);
	f->map = malloc(sizeof(char *) * (lines + 1));
	if (!f->map)
		return (close(f->fd), NULL);
	
	i = 0;
	line = get_next_line(f->fd);
	while (line)
	{
		f->map[i] = line;
		i++;
		line = get_next_line(f->fd);
	}
	f->map[i] = NULL;
	close(f->fd);
	return (f->map);
}


