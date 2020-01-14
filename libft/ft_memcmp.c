/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 21:51:58 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/11 17:03:40 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	*str1;

	i = 0;
	str = (unsigned char*)s1;
	str1 = (unsigned char*)s2;
	while (i < n)
	{
		if (str1[i] != str[i])
		{
			return (str[i] - str1[i]);
		}
		i++;
	}
	return (0);
}
