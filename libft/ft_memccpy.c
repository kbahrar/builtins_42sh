/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:53:45 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/27 15:17:41 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	ch;
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	ch = (unsigned char)c;
	i = 0;
	str = (unsigned char*)dst;
	str1 = (unsigned char*)src;
	while (i < n)
	{
		if (str1[i] == ch)
		{
			str[i] = str1[i];
			return ((void*)&str[i + 1]);
		}
		else
		{
			str[i] = str1[i];
			i++;
		}
	}
	return (0);
}
