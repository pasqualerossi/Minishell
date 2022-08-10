/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:31 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 12:51:42 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int	unset_error(char *argv)
{
	ft_putstr_fd("3lash: unset: '", 2);
	ft_putstr_fd(argv, 2);
	ft_putstr_fd("' :not a valid identifier\n", 2);
	return (1);
}

void	unset_one(char *arg)
{
	int		length;
	char	**pointer;
	int		i;

	length = ft_strlen(arg);
	i = 0;
	while (g_env[i])
	{
		if (!ft_strncmp(g_env[i], arg, length) && g_env[i][length] == '=')
		{
			pointer = &g_env[i];
			while (*pointer)
			{
				pointer[0] = pointer[1];
				pointer++;
			}
		}
		i++;
	}
}

int	is_string_and_number(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (!ft_isalnum(string[i]) && string[i] != '_')
			return (1);
		i++;
	}
	return (0);
}

int	unset(char **args)
{
	int	i;
	int	out;

	i = 0;
	out = 0;
	while (args[i] != NULL)
	{
		if (!ft_isalpha(args[i][0]) && args[i][0] != '_')
			out = unset_error(args[i]);
		else if (is_string_and_number(args[i]))
			out = unset_error(args[i]);
		else
			unset_one(args[i]);
		i++;
	}
	return (out);
}