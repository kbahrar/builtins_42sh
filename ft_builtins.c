/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:56:56 by kbahrar           #+#    #+#             */
/*   Updated: 2020/01/13 15:09:50 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	if_all_num(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	ft_exit(char **args)
{
	int		num;

	num = 0;
	if (!args[1])
		exit(0);
	if (args[1] && args[2])
	{
		ft_putendl_fd("42sh: exit: too many arguments", 2);
		return (1);
	}
	if (!if_all_num(args[1]))
	{
		ft_putstr_fd("42sh: ", 2);
		ft_putstr_fd(args[1], 2);
		ft_putendl_fd(": numeric argument required", 2);
		num = 255;
	}
	else
		num = ft_atoi(args[1]);
	exit(num);
}

int		main(int ac, char **av)
{
	// if (!ft_strcmp(av[0], "cd"))
	char *str[] = {"ls", "..", NULL};
	ft_cd(str);
		return (ft_cd(av));
	// else if (!ft_strcmp(av[0], "echo"))
		// return (ft_echo(av));
	// else if (!ft_strcmp(av[0], "type"))
	// 	return (ft_type(av));
	// else if (!ft_strcmp(av[0], "exit"))
		// return (ft_exit(av));
	// return (-1);
}
