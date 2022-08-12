/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:58:39 by prossi            #+#    #+#             */
/*   Updated: 2022/08/12 12:24:34 by prossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

// libraries

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <fcntl.h>  

// struct

typedef struct s_pipe
{
	t_list	*output_files;
	t_list	*input_files;
	char	*command;
	int		argc;
	char	**args;
}			t_pipe;

extern char	**g_env;

// builtins

int 	cd (char **args, int args_count);
int		echo(char **args, int argc, int fd);
int		env(int fd);
int		bash_exit(char **args, int arg);
int		pwd(int args_count);
int		unset(char **args);
int		export_comand(char **args, int argc, int fd);

int		is_builtin(t_pipe *command, int fd);
int		return_error(char *string, int ret);

// libft

int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strchr(const char *s, int i);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);

#endif