/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 12:19:06 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 16:30:48 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *rmd)
{
	char	*buffer;
	ssize_t	bytes_read;
	char	*temp;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(rmd), NULL);
		buffer[bytes_read] = '\0';
		temp = rmd;
		rmd = ft_strjoin(rmd, buffer);
		free(temp);
		if (!rmd)
			return (free(buffer), NULL);
		if (ft_str_chr_len(rmd, '\n') >= 0 || bytes_read == 0)
			break ;
	}
	free(buffer);
	return (rmd);
}

char	*find_line(char *rmd)
{
	char	*line;
	ssize_t	len_char;
	ssize_t	i;

	if (!rmd || !*rmd)
		return (NULL);
	len_char = ft_str_chr_len(rmd, '\n');
	if (len_char == -1)
		len_char = ft_strlen(rmd);
	else
		len_char++;
	line = malloc(sizeof(char) * (len_char + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < len_char)
	{
		line[i] = rmd[i];
		i++;
	}
	line[len_char] = '\0';
	return (line);
}

char	*clean_rmd(char *rmd)
{
	char	*temp;
	ssize_t	len_chr;
	ssize_t	i;

	len_chr = ft_str_chr_len(rmd, '\n');
	if (len_chr == -1)
		return (free(rmd), NULL);
	len_chr++;
	temp = malloc(sizeof(char) * (ft_strlen(rmd) - len_chr + 1));
	if (!temp)
		return (free(rmd), NULL);
	i = 0;
	while (rmd[len_chr + i])
	{
		temp[i] = rmd[len_chr + i];
		i++;
	}
	temp[i] = '\0';
	free(rmd);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*rmd = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(rmd), rmd = NULL, NULL);
	rmd = read_line(fd, rmd);
	if (!rmd)
		return (NULL);
	line = find_line(rmd);
	if (!line)
		return (free(rmd), rmd = NULL, NULL);
	rmd = clean_rmd(rmd);
	return (line);
}
/*
int	main(void)
{
	int fd;
	char *line;

	fd = open("fichier.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	while ((line = get_next_line(fd)) != NULL)
	{
			printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/