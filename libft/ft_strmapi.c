/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:06:06 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 15:06:15 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dst;

	i = 0;
	if (!s)
		return (NULL);
	dst = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!dst)
		return (NULL);
	while (s[i])
	{
		dst[i] = f(i, s[i]);
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
/*
char    ft_toupper_char(unsigned int i, char c)
{
    (void)i;
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}

int     main(void)
{
    char    *s = "Hello word!";
    char    *result;

    result = ft_strmapi(s, ft_toupper_char);
    if (result)
    {
        printf("Résultat : %s\n", result);
        free(result);
    }
    return (0);
}
*/
