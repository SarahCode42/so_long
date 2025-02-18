/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:42:03 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 14:38:21 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d \n", ft_isprint(' '));
    printf("%d \n", ft_isprint('a'));
    printf("%d \n", ft_isprint('\r'));
    printf("%d \n", ft_isprint(';'));
    printf("%d \n", ft_isprint('/'));
	return (0);
}
*/