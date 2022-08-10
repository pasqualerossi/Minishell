/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prossi <prossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:58:39 by prossi            #+#    #+#             */
/*   Updated: 2022/08/10 16:40:48 by prossi           ###   ########.fr       */
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

// cd

int 	cd_error(char *arg);
void 	set_pwd(void);
int 	cd (char **args, int args_count);

// echo

int		echo(char **args, int argc, int fd);

// env

int		env(int fd);

// exit

int		exit_error(char *arg);
bool	ft_is_numeric(char	*str);
int		bash_exit(char **args, int arg);

// export

int		export_error(char *argv);
void	print_export(int fd[2]);
void	sort_it(int fd[2], int out);
int		sort_export(int out);
int		export_command(char **args, int argc, int fd);

// pwd

int		pwd(int args_count);

// unset

int		unset_error(char *argv);
void	unset_one(char *arg);
int		is_string_and_number(char *string);
int		unset(char **args);

// builtins

int		is_builtin(t_pipe *command, int fd);
char	*ft_getenv(char *key);
int		ft_execvp(char *cmd, char **args);
int		return_error(char *string, int ret);

// putenv

int		ft_putenv(char const *string);

// libft

int		ft_atoi(const char *str);
int		ft_isalnum(int i);
int		ft_isalpha(int i);
int		ft_isdigit(int i);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *str, char c);
char	*ft_strchr(const char *s, int i);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
int		ft_strncmp(const char *s1, char *s2, size_t n);
char	*ft_strndup(const char *src, size_t n);

#endif