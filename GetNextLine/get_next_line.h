/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:57:22 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/11 16:48:17 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*read_line(int fd, char *rmd);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *s);
ssize_t	ft_str_chr_len(char *s, char c);
char	*find_line(char *rmd);
char	*clean_rmd(char *rmd);

#endif
