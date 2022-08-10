/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:42 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 16:00:00 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int cd_error(char *arg)
{
	ft_putstr_fd("bash: cd: ", 2);
	perror(arg);
	return (1);
}

void set_pwd(void)
{
	char	*cwd;
	char	*toadd;

	cwd = getcwd(NULL, 4096);
	toadd = ft_strjoin("PWD=", cwd);
	free(cwd);
	ft_putenv(toadd);
	free(toadd);
}

int cd (char **args, int args_count)
{
	char	*home;

	if (args_count == 0)
	{
		home = ft_getenv("HOME");
		if (!home || !(*home))
		{
			ft_putstr_fd("bash: cd: HOME not set\n", 2);
			return (1);
		}
		if(chdir(home) == -1)
			return (cd_error(home));
	}
	else if (args_count == 1)
	{
		if (chdir(args[0]) = -1)
			return (cd_error(args[0]));
	}
	else
	{
		ft_putstr_fd("cd: too many arguments\n", 2);
		return (1);
	}
	set_pwd();
	return (0);
}