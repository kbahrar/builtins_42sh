/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 16:30:44 by kbahrar           #+#    #+#             */
/*   Updated: 2020/01/13 15:05:56 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

static void	ft_2putstr(char *str, char *str2)
{
	ft_putstr_fd(str, 2);
	ft_putendl_fd(str2, 2);
}

static int	cderror(char *path)
{
	struct stat	buf;

	if (lstat(path, &buf) != -1)
	{
		if (!S_ISDIR(buf.st_mode) && !S_ISLNK(buf.st_mode))
		{
			ft_2putstr(path, ": Is not a Directory.");
			return (-1);
		}
	}
	if (access(path, F_OK) == 0)
	{
		if (access(path, X_OK) != 0)
		{
			ft_2putstr(path, ": Permission denied.");
			return (-1);
		}
		return (0);
	}
	else
		ft_2putstr(path, ": No such file or directory.");
	return (-1);
}

static int	ft_cd_p(char *path, char *pwd)
{
	if (!path)
	{
		ft_putendl_fd(": No such file or directory.", 2);
		return (1);
	}
	if (cderror(path) < 0)
		return (1);
	else
		chdir(path);
	getcwd(pwd, 4096);
	setenv("PWD", pwd, 1);
	return (0);
}

static int	ft_cd_l(char *path, char *pwd)
{
	if (!path)
	{
		ft_putendl_fd(": No such file or directory.", 2);
		return (1);
	}
	if (cderror(path) < 0)
		return (1);
	else
		chdir(path);
	pwd = ft_strcpy(pwd, path);
	setenv("PWD", pwd, 1);
	return (0);
}

int			ft_cd(char **args)
{
	extern char	**environ;
	int			opt[3];
	int			i;
	char		*pwd;
	char		*path;
	int			ret;

	i = 1;
	pwd = ft_strnew(4096);
	if (ft_cd_options(opt, &i, args) != 0)
		return (1);
	path = args[i];
	if (!args[i] || (args[i][0] == '-' && args[i][1] == '\0'))
		path = mod_path(path, environ);
	if (opt[0] == 1)
		ret = ft_cd_p(path, pwd);
	else
	{
		if (path[0] == '.')
			path = mod_point(path, environ);
		if (path[0] != '/')
			path = get_all_path(path, environ);
		ret = ft_cd_l(path, pwd);
	}
	ft_putendl(pwd);
	free(pwd);
	return (ret);
}
