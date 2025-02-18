/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:48:50 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/14 17:12:57 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d \n", ft_isalnum('D'));
	printf("%d \n", ft_isalnum('d'));
	printf("%d \n", ft_isalnum('5'));
	printf("%d \n", ft_isalnum(';'));
}
*/
