/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:10:50 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/20 18:39:33 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dst;
	size_t	len;

	len = ft_strlen(s) + 1;
	dst = malloc(sizeof(char) * len);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s, len);
	return (dst);
}
/*
int main()
{
	const char *str = "Hello, world!";
	char *copy;

	printf("Avant : %s\n", str);
	copy = strdup(str);
	printf("Après : %s\n", copy);
	free(copy);
	return 0;
}
*/
