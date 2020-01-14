/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbahrar <kbahrar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/27 18:35:20 by kbahrar           #+#    #+#             */
/*   Updated: 2020/01/12 19:44:12 by kbahrar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H
# include "libft/libft.h"
# include <sys/stat.h>

int			ft_echo(char **args);
int			ft_type(char **args);
int			ft_type_options(int *opt, int *place, char **args);
char		*access_file(char **env, char *file);
int			if_builtin(char *str);
int			ft_cd_options(int *opt, int *place, char **args);
int			ft_cd(char **args);
char		*mod_path(char *path, char **env);
char		*mod_point(char *path, char **env);
char		*get_all_path(char *path, char **env);
#endif
