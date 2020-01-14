/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 19:28:48 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/25 21:49:57 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	how_many(char const *s, char c)
{
	int		i;
	int		temp;

	temp = 0;
	i = 0;
	while (s[i] == c)
		i++;
	if (s[i])
		temp = 1;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				i++;
			if (s[i] == '\0')
				return (temp);
			temp++;
		}
		i++;
	}
	return (temp);
}

static int	size_mallocc(char const *s, char c, int i)
{
	int	temp;

	temp = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i])
	{
		temp++;
		i++;
	}
	return (temp);
}

char		**ta3mir(char **str, char const *s, char c, int i)
{
	int		j;
	int		temp;

	j = 0;
	temp = -1;
	while (s[i])
	{
		str[j][++temp] = s[i];
		i++;
		if (s[i] == c || s[i] == '\0')
		{
			while (s[i] == c)
				i++;
			str[j][++temp] = '\0';
			temp = -1;
			j++;
			if (s[i] != '\0')
				str[j] = (char*)ft_memalloc(size_mallocc(s, c, i) + 1);
		}
	}
	str[j] = NULL;
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = (char**)malloc((how_many(s, c) + 1) * sizeof(str))))
		return (NULL);
	while (s[i] == c)
		i++;
	str[j] = (char*)ft_memalloc(size_mallocc(s, c, i) + 1);
	str = ta3mir(str, s, c, i);
	return (str);
}
