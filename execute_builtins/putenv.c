/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:42:34 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 16:42:39 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/builtins.h"

static size_t	calc_move(const char *string, size_t *size)
{
	size_t	nlen;
	size_t	r;
	char	*name;
	char	*eq;

	eq = ft_strchr(string, '=');
	name = ft_strndup(string, eq - string);
	nlen = ft_strlen(name);
	*size = 0;
	r = 0;
	while (g_env[r] != NULL)
	{
		if (!ft_strncmp (g_env[r], name, nlen) && g_env[r][nlen] == '=')
			break ;
		else
			(*size)++;
		r++;
	}
	free(name);
	return (r);
}

static void	create_new_env(size_t size)
{
	char		**new_env;

	new_env = (char **) malloc(sizeof(char *) * (size + 2));
	ft_memcpy((char *)new_env, (char *)g_env, size * sizeof(char *));
	free(g_env);
	new_env[size] = NULL;
	new_env[size + 1] = NULL;
	g_env = new_env;
}

int	ft_putenv(char const *string)
{
	char		**ep;
	size_t		size;
	size_t		move;
	char		*np;

	ep = g_env;
	move = calc_move(string, &size);
	ep += move;
	if (*ep == NULL)
	{
		create_new_env(size);
		ep = g_env + size;
	}
	else
		free(*ep);
	np = ft_strdup(string);
	*ep = np;
	return (0);
}
