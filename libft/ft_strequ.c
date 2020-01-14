/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 17:03:26 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/05 14:25:43 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	int i;

	i = 0;
	if (s1 != NULL && s2 != NULL)
	{
		if (ft_strlen(s1) != ft_strlen(s2))
			return (0);
		else
		{
			while (s1[i])
			{
				if (s1[i] != s2[i])
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (0);
}
