/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:47:15 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 14:23:44 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static ssize_t	type_manager(const char *c, va_list *ap)
{
	if (*c == 'c')
		return (ft_putchr(va_arg(*ap, int)));
	else if (*c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (*c == 'd' || *c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (*c == 'p')
		return (ft_putpointer(va_arg(*ap, void *)));
	else if (*c == 'u')
		return (ft_putnbr(va_arg(*ap, unsigned int)));
	else if (*c == 'x')
		return (ft_putnbr_base16(va_arg(*ap, unsigned int), 0));
	else if (*c == 'X')
		return (ft_putnbr_base16(va_arg(*ap, unsigned int), 1));
	else if (*c == '%')
		return (ft_putchr('%'));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	size_t	i;
	size_t	len_arg;
	va_list	ap;

	if (!str)
		return (-1);
	va_start(ap, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			len_arg = type_manager(str + ++i, &ap);
		else
			len_arg = write(1, &str[i], 1);
		if (len_arg >= 0)
			len += len_arg;
		else
			len = len_arg;
		i++;
	}
	va_end(ap);
	return (len);
}
/*
int	main(void)
{
	char	c = 'S';
	char	*str = "Bonjour";
	int		nbr = -123;
	void	*pt = &str;
	char 	*ptr = NULL;
	int		size_ft;
	int		size_printf;
	
	size_ft = ft_printf(0);
	size_printf = printf(0);
	size_ft = ft_printf("Le caractere est : %c\n", c);
	size_printf = printf("Le caractere est : %c\n", c);
	printf("Longueur ft  : %i\nLongueur printf : %i\n\n", size_ft, size_printf);
	ft_printf("La chaine est : %s\n", str);
	printf("La chaine est : %s\n", str);
	ft_printf("L'entier est : %d\n", nbr);
	printf("L'entier est : %d\n", nbr);
	ft_printf("L'adresse du pointeur est : %p\n", ptr);
	printf("L'adresse du pointeur est : %p\n", ptr);
	ft_printf("L'adresse du pointeur est : %p\n", pt);
	printf("L'adresse du pointeur est : %p\n", pt);
	ft_printf("L'entier est : %i\n", nbr);
	printf("L'entier est : %i\n", nbr);
	ft_printf("L'entier est : %u\n", nbr);
	printf("L'entier est : %u\n", nbr);
	ft_printf("L'entier est : %x\n", nbr);
	printf("L'entier est : %x\n", nbr);
	ft_printf("L'entier est : %X\n", nbr);
	printf("L'entier est : %X\n", nbr);
	ft_printf("L'entier est : %%\n");
	printf("L'entier est : %%\n");
	return (0);
}
*/