/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_for_child_cmdone.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:02:06 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/02/17 12:37:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	fork_for_child_cmdone(int *fd, char **argv, char **envp, int pid1)
{
	int		fp;
	char	**ag;

	if (pid1 == 0)
	{
		fp = open(argv[1], O_RDONLY);
		if (fp < 0)
			exit(1);
		dup2(fp, 0);
		dup2(fd[1], 1);
		close(fp);
		close(fd[1]);
		close(fd[0]);
		ag = get_params(2, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
			perror("error");
			exit(1);
		}
		exit(0);
	}
}
