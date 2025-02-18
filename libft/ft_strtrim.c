/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 10:02:14 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/19 11:09:06 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	len1;

	start = 0;
	len1 = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (len1 > start && (ft_strrchr(set, s1[len1 - 1])))
		len1--;
	return (ft_substr(s1, start, len1 - start));
}
/*
int	main(void)
{
	char *s1 = "-+-+Hello, World!-+-+";
	char *set = "-+";
	char *result;

	printf("Avant : \"%s\"\n", s1);
	result = ft_strtrim(s1, set);
	if (result)
	{
		printf("Après : \"%s\"\n", result);
        	free(result);
	}
	else
        	printf("Erreur : allocation mémoire échouée\n");
	return 0;
}
*/
