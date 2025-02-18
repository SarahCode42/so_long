/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:29:38 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 14:37:25 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
/*
int	main(void)
{
	printf("%d \n", ft_isascii(26));
	printf("%d \n", ft_isascii(126));
	printf("%d \n", ft_isascii(127));
	printf("%d \n", ft_isascii(0));
	printf("%d \n", ft_isascii(-3));
    printf("%d \n", ft_isascii(300));
	return (0);
}
*/
