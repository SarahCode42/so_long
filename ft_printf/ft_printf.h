/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbensimo <jbensimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:48:51 by jbensimo          #+#    #+#             */
/*   Updated: 2024/12/16 12:48:43 by jbensimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdint.h>

ssize_t	ft_putchr(char c);
ssize_t	ft_putstr(const char *s);
ssize_t	ft_putnbr(long nbr);
ssize_t	ft_putnbr_base16(unsigned long nbr, int choice);
ssize_t	ft_putpointer(void *pointer);
int		ft_printf(const char *str, ...);

#endif
