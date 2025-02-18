/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:16:59 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/17 11:05:11 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	int				i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
int	main(void)
{
	printf("%d", ft_strlen("Hello"));
}
*/
