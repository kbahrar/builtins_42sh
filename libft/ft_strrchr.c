/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 17:30:06 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/27 15:23:19 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	charsize1(char *s, int c)
{
	int		i;
	int		temp;

	i = 0;
	temp = 0;
	while (s[i])
	{
		if (s[i] == c)
			temp++;
		i++;
	}
	return (temp);
}

char		*ft_strrchr(const char *s, int c)
{
	int		i;
	int		temp;
	char	*str;

	i = 0;
	str = (char*)s;
	temp = charsize1(str, c);
	if (c == '\0')
		return (str + ft_strlen(str));
	while (str[i])
	{
		if (str[i] == c)
		{
			if (temp == 1)
				return (str + i + 1);
			else
				temp--;
		}
		i++;
	}
	return (str);
}
