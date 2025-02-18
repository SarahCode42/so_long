/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:50:33 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/14 16:22:07 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int	main(void)
{
	char	s[] = "jwkndkljwdn";

	ft_memset(s, 'b', 5);
	printf("ft_memset : %s\n", s);
        memset(s, 'b', 5);
        printf("   memset : %s\n", s);
	return (0);
}
*/
