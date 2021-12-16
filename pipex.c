/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 17:06:18 by mnaqqad           #+#    #+#             */
/*   Updated: 2021/12/15 14:04:16 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	pid1;
	int	pid2;
	int	fd[2];

	pid1 = 0;
	pid2 = 0;
	if (argc == 5)
	{
		ft_pipe(fd);
		pid1 = fork();
		check_error_fork(pid1);
		fork_for_child_cmdone(fd, argv, envp, pid1);
		pid2 = fork();
		check_error_fork(pid2);
		fork_for_child_cmdtwo(fd, argv, envp, pid2);
		close(fd[0]);
		close(fd[1]);
		waitpid(pid1, NULL, 0);
		waitpid(pid2, NULL, 0);
	}
	else
		write(1, "number of commands not valid \n", 31);
}
