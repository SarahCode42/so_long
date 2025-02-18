/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:16:32 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 14:22:27 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_putchr(char c)
{
	return (write(1, &c, 1));
}

ssize_t	ft_putstr(const char *s)
{
	ssize_t	len;

	if (!s)
		return (ft_putstr("(null)"));
	len = 0;
	while (s[len])
	{
		ft_putchr(s[len]);
		len++;
	}
	return (len);
}

ssize_t	ft_putnbr(long nbr)
{
	unsigned long	nb;
	ssize_t			len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchr('-');
		nb = (unsigned long)(-nbr);
	}
	else
		nb = (unsigned long) nbr;
	if (nb > 9)
		len += ft_putnbr(nb / 10);
	len += ft_putchr((nb % 10) + '0');
	return (len);
}

ssize_t	ft_putnbr_base16(unsigned long nbr, int choice)
{
	ssize_t	len;

	len = 0;
	if (nbr >= 16)
		len += ft_putnbr_base16(nbr / 16, choice);
	if (choice == 1)
		len += ft_putchr("0123456789ABCDEF"[nbr % 16]);
	else
		len += ft_putchr("0123456789abcdef"[nbr % 16]);
	return (len);
}

ssize_t	ft_putpointer(void *pointer)
{
	ssize_t	len;

	if (!pointer)
		return (ft_putstr("(nil)"));
	len = ft_putstr("0x");
	return (len + ft_putnbr_base16((unsigned long) pointer, 0));
}
