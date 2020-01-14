/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 15:40:53 by kbahrar           #+#    #+#             */
/*   Updated: 2019/03/28 16:20:04 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long		ft_sizenb(long long n)
{
	unsigned int i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

void					ft_putnbr(long long n)
{
	long long nbb;
	long long nb;
	long long mod;
	long long p;

	if (n < 0)
	{
		n = n * -1;
		ft_putchar('-');
	}
	nbb = n;
	nb = ft_sizenb(nbb);
	p = 1;
	while (nb-- > 0)
		p = p * 10;
	while (p >= 10)
	{
		nb = nbb / p;
		mod = nbb % p;
		nbb = mod;
		p = p / 10;
		ft_putchar(nb + '0');
	}
	ft_putchar(nbb + '0');
}
