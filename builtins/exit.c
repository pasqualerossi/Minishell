/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:05 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 11:55:29 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	exit_error(char *arg)
{
	write("bash: exit: ", 2);
	write(arg, 2);
	write(": numeric argument required\n", 2);
	return (2);
}

bool	ft_is_numeric(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (false);
	return (true);
}

int	bash_exit(char **args, int arg)
{
	ft_putendl_fd("exit", 2);
	if (arg == 0)
		exit(0);
	if (arg >= 1)
	{
		if (!ft_is_numeric(args[0]))
			exit(exit_error(args[0]));
		else if (arg == 1)
			exit(ft_atoi(args[0]));
		else
		{
			write("bash: exit: too many arguments\n", 2);
			return (2);
		}
	}
	return (0);
}