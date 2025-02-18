/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:32:36 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/20 09:07:08 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen_sign(int n)
{
	int	len;

	len = 1;
	if (n < 0)
		len++;
	while (n / 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	long	nb;
	char	*dst;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	len = ft_intlen_sign(nb);
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	dst[len] = '\0';
	if (nb < 0)
	{
		dst[0] = '-';
		nb = -nb;
	}
	while (len > 0 && (nb > 0 || len > 1))
	{
		dst[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (dst);
}
/*
int	main(void)
{
	int n = -12345;
	char *result = ft_itoa(n);

	if (result)
	{
		printf("Résultat : %s\n", result); // Affiche "-12345"
		free(result);
	}
	return 0;
}
*/
