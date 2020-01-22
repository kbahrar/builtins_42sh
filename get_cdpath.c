/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cdpath.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:04:54 by kbahrar           #+#    #+#             */
/*   Updated: 2020/01/22 18:19:30 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	free_tab(char **tab)
{
	int		i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			free(tab[i++]);
		free(tab);
	}
}

char		*get_cdpath(char *pwd, char *path)
{
	char	**paths;
	int		i;
	char	*tmp;

	i = 0;
	paths = ft_strsplit(pwd, ':');
	while (paths[i])
	{
		tmp = ft_pathjoin(paths[i], path);
		ft_putendl(tmp);
		if (!access(tmp, X_OK))
		{
			free_tab(paths);
			return (tmp);
		}
		free(tmp);
		i++;
	}
	return (NULL);
}
