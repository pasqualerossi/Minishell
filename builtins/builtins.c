/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 12:55:15 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 12:25:37 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
		return (export_command(command->args + 1, command->argc - 1, fd));
	else
		return (127);
}

int	return_error(char *string, int ret)
{
	ft_putendl_fd(string, 2);
	return (ret);
}