/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 15:58:15 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/09 21:43:36 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len;
	size_t	e;
	size_t	i;

	len = ft_strlen(dst);
	i = 0;
	e = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (dst[i] != '\0' && i < size)
		i++;
	while (src[e] != '\0' && i < size - 1)
		dst[i++] = src[e++];
	if (size >= len)
		dst[i] = '\0';
	if (size < len)
		return (ft_strlen(src) + size);
	else
		return (ft_strlen(src) + len);
}
