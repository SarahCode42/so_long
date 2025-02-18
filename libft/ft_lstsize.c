/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:59:43 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/21 18:37:14 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
}
/*
int	main(void)
{
	t_list *lst = ft_lstnew((void *)(long)42);  

	printf("Taille de la liste: %d\n", ft_lstsize(lst));
	free(lst);
	return 0;
}
*/
