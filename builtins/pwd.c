/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:56:24 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 11:55:43 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"

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
			write("pwd: ", 2);
			write(strerror(error_temporary), 2);
			write("\n", 2);
		}
		else
		{
			printf("%s\n", cwd);
			free(cwd);
		}
	}
	else
		write("pwd: too many arguments\n", 2);
	return (0);
}