/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:38:12 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/19 19:29:42 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		len = s_len - start;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, len + 1);
	return (dst);
}
/*
int	main(void)
{
	char *s = "Hello, world!";
	char *substr;

	printf("Avant : %s\n", s);
	substr = ft_substr(s, 7, 5);
	printf("Après : %s\n", substr);
	free(substr);
	return 0;
}
*/
