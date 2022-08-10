/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:55:15 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 16:26:48 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int	is_builtin(t_pipe *command, int fd)
{
	if (!ft_strcmp(command->cmd, "echo"))
		return (echo(command->args + 1, command->argc - 1, fd));
	else if (!ft_strcmp(command->cmd, "cd"))
		return (cd(command->args + 1, command->argc - 1));
	else if (!ft_strcmp(command->cmd, "env"))
		return (env(fd));
	else if (!ft_strcmp(command->cmd, "unset"))
		return (unset(command->args + 1));
	else if (!ft_strcmp(command->cmd, "pwd"))
		return (pwd(command->argc - 1));
	else if (!ft_strcmp(command->cmd, "exit"))
		return (bash_exit(command->args + 1, command->argc - 1));
	else if (!ft_strcmp(command->cmd, "export"))
		return (export(command->args + 1, command->argc - 1, fd));
	else
		return (127);
}

char	*ft_getenv(char *key)
{
	int		i;
	int		keylen;
	char	*ret;

	i = 0;
	keylen = ft_strlen (key);
	while (g_env[i] != NULL)
	{
		if (!ft_strncmp (g_env[i], key, keylen) && g_env[i][keylen] == '=')
		{
			ret = ft_strchr(g_env[i], '=');
			if (ret)
				return (ret + 1);
			else
				return (NULL);
		}
		i++;
	}
	return (NULL);
}

int	ft_execvp(char *cmd, char **args)
{
	char		**all_paths;
	char		*str;
	char		*path;
	char		*tmp;
	int			i;

	if (ft_strchr(cmd, '/'))
		return (execve(cmd, args, g_env));
	str = ft_getenv("PATH");
	if (!str)
		return (execve(cmd, args, g_env));
	all_paths = ft_split(str, ':');
	i = 0;
	while (all_paths[i])
	{
		tmp = ft_strjoin("/", cmd);
		path = ft_strjoin(all_paths[i], tmp);
		free(tmp);
		free(all_paths[i]);
		execve(path, args, g_env + 2);
		free(path);
		i++;
	}
	free(all_paths);
	return (-1);
}

int	return_error(char *string, int ret)
{
	ft_putendl_fd(string, 2);
	return (ret);
}