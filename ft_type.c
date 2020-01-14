/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 18:56:58 by kbahrar           #+#    #+#             */
/*   Updated: 2019/12/29 15:39:53 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static int	ft_type_t(char *str, int ret)
{
	extern char	**environ;

	if (if_builtin(str))
		ft_putstr("builtin\n");
	else
	{
		str = access_file(environ, str);
		if ((ft_strchr(str, '/')) && !access(str, F_OK))
			ft_putstr("file\n");
		else
			return (ret);
	}
	return (0);
}

static int	ft_type_p(char *str, int opt, int a, int ret)
{
	extern char	**environ;

	if (opt == 1 && a == -1)
		if (if_builtin(str))
			return (0);
	str = access_file(environ, str);
	if ((ft_strchr(str, '/')) && !access(str, F_OK))
		ft_putendl(str);
	else
		return (ret);
	return (0);
}

static int	ft_type_a(char *str, int ret)
{
	extern char	**environ;
	char		*cpy;

	cpy = ft_strdup(str);
	if (if_builtin(str))
	{
		ft_putstr(str);
		ft_putendl(" is a shell builtin");
	}
	str = access_file(environ, str);
	if (ft_strchr(str, '/') && !access(str, F_OK))
	{
		ft_putstr(cpy);
		ft_putstr(" is ");
		ft_putendl(str);
	}
	else if (!if_builtin(str))
	{
		free(cpy);
		return (ret);
	}
	free(cpy);
	return (0);
}

static int	ft_type_n(char *str, int ret)
{
	extern char	**environ;
	char		*cpy;

	if (if_builtin(str))
		ft_putstr_plus(str, " is a shell builtin\n");
	else
	{
		cpy = ft_strdup(str);
		str = access_file(environ, str);
		if ((ft_strchr(str, '/')) && !access(str, F_OK))
		{
			ft_putstr_plus(cpy, " is ");
			ft_putendl(str);
			free(cpy);
		}
		else
		{
			ft_putstr_fd("42sh: type: ", 2);
			ft_putstr_fd(str, 2);
			ft_putendl_fd(": not found", 2);
			return (ret);
		}
	}
	return (0);
}

int			ft_type(char **args)
{
	int		i;
	int		opt[5];
	int		ret;

	i = 1;
	ret = 1;
	if (!args[i])
		return (0);
	if (ft_type_options(opt, &i, args) != 0)
		return (2);
	while (args[i])
	{
		if (opt[3] == 1)
			ret = ft_type_t(args[i], ret);
		else if (opt[2] == 1 || opt[4] == 1)
			ret = ft_type_p(args[i], opt[2], opt[0], ret);
		else if (opt[0] == 1)
			ret = ft_type_a(args[i], ret);
		else
			ret = ft_type_n(args[i], ret);
		i++;
	}
	return (ret);
}
