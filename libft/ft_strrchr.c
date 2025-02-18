/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:16:00 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/16 22:07:15 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	uc;

	i = ft_strlen((char *)s);
	uc = c;
	if (uc == '\0')
		return ((char *) &s[i]);
	while (i >= 0)
	{
		if (s[i] == uc)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
int	main(void)
{
	char	str[] = "Hello";
	char	c = 'o';

	printf("%s, %c", str, c);
	ft_strrchr(str, c);
	printf("%s, %c", str, c);
	return (0);
}
*/
