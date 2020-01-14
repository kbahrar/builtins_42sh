/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/31 17:21:13 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/09 21:37:43 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		j;

	if (needle[0] == '\0')
		return ((char*)haystack);
	while (len && *haystack)
	{
		if (*needle == *haystack)
		{
			j = 0;
			while (*(needle + j) == *(haystack + j) && *(haystack + j)
					&& *(needle + j) && j < (int)len)
				j++;
			if (*(needle + j) == '\0')
				return ((char *)haystack);
		}
		haystack++;
		len--;
	}
	return (NULL);
}
