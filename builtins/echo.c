/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:55:50 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 11:55:21 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

int	echo(char **args, int argc, int fd)
{
	int	i;

	i = 0;
	if (argc == 0)
	{
		write('\n', fd);
		return (0);
	}
	while (args[i] && !ft_strcmp(args[i], "-n"))
		i++;
	while (i < argc - 1)
	{
		write(args[i++], fd);
		write(" ", fd);
	}
	if (i != argc)
		write(args[i], fd);
	if (ft_strcmp(args[0], "-n"))
		write("\n", fd);
	return (0);
}