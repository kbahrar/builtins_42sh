/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 20:44:25 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/11 19:07:19 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size(unsigned int nbr)
{
	int t;

	t = 1;
	while (nbr >= 10)
	{
		nbr = nbr / 10;
		t++;
	}
	return (t);
}

static void	ft_rev(char *t)
{
	char	temp;
	int		i;
	int		j;
	int		s;

	i = 0;
	j = 0;
	while (t[i] != '\0')
		i++;
	s = i;
	while (j < (s / 2))
	{
		temp = t[i - 1];
		t[i - 1] = t[j];
		t[j] = temp;
		i--;
		j++;
	}
}

static int	ft_negpos(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

static int	ft_negposs(int n)
{
	if (n < 0)
		return (1);
	else
		return (0);
}

char		*ft_itoa(int n)
{
	char				*tab;
	unsigned int		s;
	unsigned int		i;
	unsigned int		l;
	unsigned int		nn;

	i = ft_negposs(n) + 1;
	l = ft_negposs(n);
	n = ft_negpos(n);
	nn = n;
	s = ft_size(nn);
	if (!(tab = (char*)malloc(sizeof(char) * (s + i))))
		return (0);
	i = -1;
	while (++i < s)
	{
		tab[i] = (nn % 10) + '0';
		nn = nn / 10;
	}
	if (l == 1)
		tab[i++] = '-';
	tab[i] = '\0';
	ft_rev(tab);
	return (tab);
}
