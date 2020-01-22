/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_help.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:42:26 by kbahrar           #+#    #+#             */
/*   Updated: 2020/01/17 14:48:46 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

char		*mod_path(char *path)
{
	int		i;
	char	*var;

	i = 0;
	if (!path)
		path = getenv("HOME");
	else
	{
		var = getenv("OLDPWD");
		if (var)
			path = var;
	}
	return (path);
}

static char	*remplace_point(char *pwd, char *path)
{
	int		len;
	char	*str;

	path++;
	len = ft_strlen(pwd) + ft_strlen(path);
	str = ft_strnew(len);
	str = ft_strcpy(str, pwd);
	str = ft_strcat(str, path);
	return (str);
}

static char	*replace_2point(char *pwd, char *path)
{
	char	*str;
	char	*last_pwd;
	int		len;
	int		i;

	path += 2;
	i = 0;
	last_pwd = ft_strrchr(pwd, '/');
	len = ft_strlen(pwd) + ft_strlen(path);
	str = ft_strnew(len);
	while (pwd[i])
	{
		if (!ft_strcmp(last_pwd, pwd + i + 1))
			break ;
		str[i] = pwd[i];
		i++;
	}
	if (!str[0])
		str[0] = '/';
	str = ft_strcat(str, path);
	return (str);
}

char		*mod_point(char *path)
{
	int		i;
	char	*pwd;

	i = 0;
	pwd = getenv("PWD");
	if (!pwd)
		return (path);
	if (path[0] == '.' && path[1] == '\0')
		return (pwd);
	if (path[0] == '.' && path[1] == '/')
		return (remplace_point(pwd, path));
	if (path[0] == '.' && path[1] == '.' && (path[2] == '\0' || path[2] == '/'))
		return (replace_2point(pwd, path));
	return (path);
}

char		*get_all_path(char *path)
{
	int		i;
	char	*pwd;
	char	*str;
	int		len;

	i = -1;
	pwd = getenv("PWD");
	if (pwd)
	{
		len = ft_strlen(path) + ft_strlen(pwd) + 1;
		str = ft_strnew(len);
		str = ft_strcpy(str, pwd);
		str = ft_strcat(str, "/");
		str = ft_strcat(str, path);
		return (str);
	}
	return (path);
}
