/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:58:01 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/19 12:53:55 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	lensrc;

	i = 0;
	lensrc = ft_strlen(src);
	if (size == 0)
		return (lensrc);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (lensrc);
}
/*
int	main()
{
	char	dest[] = "Hello";
	char	*src = "Bonjour";
	size_t	size = 5;

	printf("avant dest: %s, src: %s, size: %zu\n", dest, src, size);
	ft_strlcpy(dest, src, size);
        printf("apres dest: %s, src: %s, size: %zu", dest, src, size);
	return (0);
}
*/
