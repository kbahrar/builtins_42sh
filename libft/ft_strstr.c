/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 19:49:04 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/09 19:57:54 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	if (needle[0] == '\0')
		return ((char *)haystack);
	while (*haystack)
	{
		if (*haystack == *needle)
		{
			i = 0;
			while (*(haystack + i) == *(needle + i) && *(haystack + i)
			&& *(needle + i))
				i++;
			if (*(needle + i) == '\0')
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
