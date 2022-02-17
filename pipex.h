/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 18:01:09 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/17 12:35:51 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>

char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	*get_path(char *cmd, char **envp);
void	ft_pipe(int *fd);
void	fork_for_child_cmdone(int *fd, char **argv, char **envp, int pid1);
void	fork_for_child_cmdtwo(int *fd, char **argv, char **envp, int pid2);
void	check_error_fork(int pid);
int		count_argc(char **argv);
char	**get_params(int index, char **argv);
char	*ft_strnstr(const char *big, const char *little, size_t len);
#endif