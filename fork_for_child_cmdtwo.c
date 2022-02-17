/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_for_child_cmdtwo.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:03:25 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/17 12:37:26 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_for_child_cmdtwo(int *fd, char **argv, char **envp, int pid2)
{
	int		fl;
	char	**ag;

	if (pid2 == 0)
	{
		fl = open(argv[count_argc(argv) - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fl < 0)
			exit(1);
		dup2(fd[0], 0);
		dup2(fl, 1);
		close(fl);
		close(fd[1]);
		close(fd[0]);
		ag = get_params(3, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
			perror("error");
			exit(1);
		}
		exit(0);
	}
}
