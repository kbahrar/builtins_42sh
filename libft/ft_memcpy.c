/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 14:22:25 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/27 15:16:38 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*str;
	unsigned char	*str1;
	size_t			i;

	i = 0;
	str = (unsigned char*)dst;
	str1 = (unsigned char*)src;
	while (i < n)
	{
		str[i] = str1[i];
		i++;
	}
	return (dst);
}
