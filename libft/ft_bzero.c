/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:39:43 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/14 16:19:10 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}
/*
int	main(void)
{
	char	s[] = "Hello";

	ft_bzero(s, 3);
	printf("ft_bzero : %s\n", s);
        bzero(s, 3);
        printf("   bzero : %s\n", s);
	return (0);
}
*/
