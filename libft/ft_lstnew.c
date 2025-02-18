/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:24:09 by jbensimo          #+#    #+#             */
/*   Updated: 2024/11/20 20:53:52 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elem;

	new_elem = malloc(sizeof(t_list));
	if (!new_elem)
		return (NULL);
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
/*
int	main(void)
{
	t_list	*new_elem1 = ft_lstnew("Hello word!");
	t_list 	*new_elem2 = ft_lstnew("Bonjour monde!");

	new_elem1->next = new_elem2;
	
	printf("%s\n", (char *)new_elem1->content);
	printf("%s\n", (char *)new_elem2->content);
	return (0);
}
*/
