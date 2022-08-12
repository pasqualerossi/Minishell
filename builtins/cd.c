/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:42 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 11:55:16 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int cd_error(char *arg)
{
	write("bash: cd: ", 2);
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
	ft_putenv(toadd); //ft_putenv
	free(toadd);
}

int cd (char **args, int args_count)
{
	char	*home;

	if (args_count == 0)
	{
		home = ft_getenv("HOME"); //ft_getenv
		if (!home || !(*home))
		{
			write("bash: cd: HOME not set\n", 2);
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
		write("cd: too many arguments\n", 2);
		return (1);
	}
	set_pwd();
	return (0);
}