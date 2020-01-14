/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 20:51:45 by kbahrar           #+#    #+#             */
/*   Updated: 2019/04/05 23:28:27 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	int	j;
	int	i;

	j = ft_isdigit(c);
	i = ft_isalpha(c);
	if (i + j >= 1)
		return (1);
	return (0);
}