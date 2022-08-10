/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:05 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 12:34:45 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int	exit_error(char *arg)
{
	ft_putstr_fd("bash: exit: ", 2);
	ft_putstr_fd(arg, 2);
	ft_putstr_fd(": numeric argument required\n", 2);
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
			ft_putstr_fd("bash: exit: too many arguments\n", 2);
			return (2);
		}
	}
	return (0);
}