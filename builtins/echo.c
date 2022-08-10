/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:50 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 12:30:05 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int	echo(char **args, int argc, int fd)
{
	int	i;

	i = 0;
	if (argc == 0)
	{
		ft_putchar_fd('\n', fd);
		return (0);
	}
	while (args[i] && !ft_strcmp(args[i], "-n"))
		i++;
	while (i < argc - 1)
	{
		ft_putstr_fd(args[i++], fd);
		ft_putstr_fd(" ", fd);
	}
	if (i != argc)
		ft_putstr_fd(args[i], fd);
	if (ft_strcmp(args[0], "-n"))
		ft_putstr_fd("\n", fd);
	return (0);
}