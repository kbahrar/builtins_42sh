/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:22:39 by kbahrar           #+#    #+#             */
/*   Updated: 2019/03/29 15:02:10 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_sizenbb(unsigned int n)
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

void			ft_putnbr_fd(int n, int fd)
{
	unsigned int nbb;
	unsigned int nb;
	unsigned int mod;
	unsigned int p;

	if (n < 0)
	{
		n = n * -1;
		ft_putchar_fd('-', fd);
	}
	nbb = n;
	nb = ft_sizenbb(nbb);
	p = 1;
	while (nb-- > 0)
		p = p * 10;
	while (p >= 10)
	{
		nb = nbb / p;
		mod = nbb % p;
		nbb = mod;
		p = p / 10;
		ft_putchar_fd(nb + '0', fd);
	}
	ft_putchar_fd(nbb + '0', fd);
}
