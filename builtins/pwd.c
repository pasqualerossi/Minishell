/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:24 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 16:05:27 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

int	pwd(int args_count)
{
	char	*cwd;
	int		error_temporary;

	if (args_count == 0)
	{
		cwd = getcwd(NULL, 4096);
		if (cwd == NULL)
		{
			error_temporary = errno;
			ft_putstr_fd("pwd: ", 2);
			ft_putstr_fd(strerror(error_temporary), 2);
			ft_putstr_fd("\n", 2);
		}
		else
		{
			printf("%s\n", cwd);
			free(cwd);
		}
	}
	else
		ft_putstr_fd("pwd: too many arguments\n", 2);
	return (0);
}