/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:27:39 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/16 21:27:37 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;
	unsigned char		chr;

	i = 0;
	str = s;
	chr = c;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	const unsigned char str[] = "Hello";
	int c = 'l';
	size_t	n = 12;

	printf("%s", (char *)ft_memchr(str, c, n));
	return (0);
}
*/
