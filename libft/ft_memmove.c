/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:55:55 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/14 17:31:09 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dest;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (d > s)
	{
		while (n > 0)
		{
			d[n - 1] = s[n - 1];
			n--;
		}
	}
	return (d);
}
/*
int main(void)
{
	char src[] = "Bonjour";
	char *dest = src + 1;
	size_t n = 5;

        printf("Avant    memmove: src: %s, dest: %s\n", src, dest);

	//ft_memmove(dest, src, n);
	memmove(dest, src, n);

	printf("Après    memmove: src: %s, dest: %s\n", src, dest);
	printf("Après ft_memmove: src: %s, dest: %s\n", src, dest);
	return (0);
}
*/
