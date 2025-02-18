/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:06:19 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/18 09:53:43 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dst = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1, len1 + 1);
	ft_strlcat(dst, s2, len1 + len2 + 1);
	return (dst);
}
/*
int	main(void)
{
	char *s1 = "Hello, ";
	char *s2 = "World!";
	char *result;

	printf("Avant : s1 = \"%s\", s2 = \"%s\"\n", s1, s2);
	result = ft_strjoin(s1, s2);
	if (result)
	{
		printf("Après : result = \"%s\"\n", result);
		free(result);
	}
	else
		printf("Erreur : allocation mémoire échouée\n");
	return 0;
}
*/
