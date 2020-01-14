/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:44:10 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/05 21:27:11 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*tab;
	int		size;

	size = 0;
	while (s1[size])
		size++;
	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
	{
		perror("malloc: ");
		exit(EXIT_FAILURE);
	}
	size = 0;
	while (s1[size])
	{
		tab[size] = s1[size];
		size++;
	}
	tab[size] = '\0';
	return (tab);
}
