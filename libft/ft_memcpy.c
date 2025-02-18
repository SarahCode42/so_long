/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:02:18 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/17 11:26:23 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dest && !src)
		return (NULL);
	if (n == 0)
		return (dest);
	d = dest;
	s = src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	char	dest[12] = "";
	char	src[] = "Hello word";
	size_t	n = 7;

	ft_memcpy(dest, src, n);
	printf("ft_memcpy : %s\n", dest);
        memcpy(dest, src, n);
        printf("   memcpy : %s\n", dest);

	return (0);
}
*/
