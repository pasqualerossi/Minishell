/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:17 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 11:55:33 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	export_error(char *argv)
{
	write("bash: export: '", 2);
	write(argv, 2);
	write("' :not a valid identifier\n", 2);
	return (1);
}

void	print_export(int fd[2])
{
	int	i;
	int	j;

	i = 0;
	dup2(fd[1], 1);
	while (g_env[i])
	{
		if (g_env[i][0] == '?' || g_env[i][0] == '-')
		{
			i++;
			continue ;
		}
		j = 0;
		printf("declare -x ");
		while (g_env[i][j] != '=' && g_env[i][j])
			printf("%c", g_env[i][j++]);
		printf("=\"%s\"\n", ft_strchr(g_env[i], '=') + 1);
		i++;
	}
	close(fd[0]);
	close(fd[1]);
	exit(0);
}

void	sort_it(int fd[2], int out)
{
	char	**args;

	args = ft_split("sort ", ' ');
	dup2(fd[0], 0);
	dup2(out, 1);
	close(fd[0]);
	close(fd[1]);
	ft_execvp("sort", args); //ft_execvp
}

int	sort_export(int out)
{
	int		fd[2];
	int		pid;
	int		id;

	if (pipe(fd) == -1)
		return (return_error("FATAL ERROR", 1));
	pid = fork();
	if (pid < 0)
		return (return_error("FATAL ERROR", 1));
	if (pid == 0)
		print_export(fd);
	else
	{
		waitpid(pid, NULL, 0);
		id = fork();
		if (id < 0)
			return (return_error("FATAL ERROR", 1));
		if (id == 0)
			sort_it(fd, out);
		close(fd[0]);
		close(fd[1]);
		waitpid(id, NULL, 0);
	}
	return (0);
}

int	export_comand(char **args, int argc, int fd)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	if (argc == 0)
		return (sort_export(fd));
	else
	{
		while (args[i] != NULL)
		{
			if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
				out = export_error(args[i]);
			else if (str_alnum(args[i]))
				out = export_error(args[i]);
			else if (ft_strchr(args[i], '='))
				ft_putenv(args[i]); //ft_putenv
			i++;
		}
	}
	return (out);
}