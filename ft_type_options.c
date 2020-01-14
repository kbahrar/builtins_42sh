/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 20:48:02 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/30 17:02:41 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int			if_builtin(char *str)
{
	if (!ft_strcmp(str, "exit"))
		return (1);
	else if (!ft_strcmp(str, "type"))
		return (1);
	else if (!ft_strcmp(str, "cd"))
		return (1);
	else if (!ft_strcmp(str, "echo"))
		return (1);
	else if (!ft_strcmp(str, "set"))
		return (1);
	else if (!ft_strcmp(str, "unset"))
		return (1);
	else if (!ft_strcmp(str, "test"))
		return (1);
	else if (!ft_strcmp(str, "alias"))
		return (1);
	else
		return (0);
}

static void	init_options(int *opt, char c)
{
	int		i;

	i = 0;
	i = 0;
	if (c != 'a')
		while (i < 5)
			opt[i++] = -1;
}

static int	get_options(int *opt, char *str)
{
	int		i;

	i = 0;
	while (str[++i])
	{
		init_options(opt, str[i]);
		if (str[i] == 'a')
			opt[0] = 1;
		else if (str[i] == 'f')
			opt[1] = 1;
		else if (str[i] == 'p')
			opt[2] = 1;
		else if (str[i] == 't')
			opt[3] = 1;
		else if (str[i] == 'P')
			opt[4] = 1;
		else
		{
			ft_putstr_fd("42sh: type: -", 2);
			ft_putchar_fd(str[i], 2);
			ft_putendl_fd(": invalid option\ntype: usage:[-afptP][name]", 2);
			return (-1);
		}
	}
	return (0);
}

int			ft_type_options(int *opt, int *place, char **args)
{
	int		i;
	int		flag;

	init_options(opt, 'p');
	i = 1;
	flag = 0;
	while (args[i])
	{
		if (args[i][0] == '-' && args[i][1] == '-' && !args[i][2])
		{
			*place = i + 1;
			break ;
		}
		if (args[i][0] == '-' && args[i][1])
			flag = get_options(opt, args[i]);
		else
			break ;
		if (flag == -1)
			return (2);
		i++;
		*place = i;
	}
	return (0);
}
