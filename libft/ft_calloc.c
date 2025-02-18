/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 20:05:41 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/19 10:31:21 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
/*
int main(void)
{
	size_t count = 5;
	size_t size = sizeof(int);
	unsigned char *arr;
	size_t	i;

	i = 0;
	arr = (unsigned char *)ft_calloc(count, size);
	if (!arr)
		return 1;
	while (i < count * size)
	{
		printf("arr[%zu] = %d\n", i, arr[i]);
		i++;
	}
	free(arr);
	return 0;
}
*/
