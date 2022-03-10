/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 09:35:11 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/08 10:26:46 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand/pipex.h"

int main(int argc,char **argv, char **envp)
{
	int pipes[2][2];
	int pid1 = 0;
	int pid2 = 0;
	int pid3 = 0;
	int i =0;
	while(i < 2)
	{
		pipe(pipes[i]);
		i++;
	}
	pid1 = fork();
	if(pid1 == 0)
	{
		char **ag;
		int read_file = open(argv[1],O_RDONLY);
		dup2(read_file,0);
		dup2(pipes[0][1],1);
		close(pipes[0][0]);
		close(pipes[1][0]);
		close(pipes[1][1]);
		close(pipes[0][1]);
		close(read_file);
		ag = get_params(2, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
			perror("error");
			exit(1);
		}
		exit(0);
	}
	pid2 = fork();
	if(pid2 == 0)
	{
		char **ag;
		dup2(pipes[0][0],0);
		dup2(pipes[1][1],1);
		close(pipes[0][1]);
		close(pipes[1][0]);
		close(pipes[1][1]);
		close(pipes[0][0]);
		ag = get_params(3, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
			perror("error");
			exit(1);
		}
		exit(0);
	}
	pid3 = fork();
	if(pid3 == 0)
	{
		char **ag;
		int output_file = open("file2",O_CREAT | O_TRUNC | O_RDWR,0777);
		dup2(pipes[1][0],0);
		dup2(output_file,1);
		close(pipes[0][0]);
		close(pipes[1][0]);
		close(pipes[1][1]);
		close(pipes[0][1]);
		close(output_file);
		ag = get_params(4, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
			perror("error");
			exit(1);
		}
		exit(0);
	}
	close(pipes[0][0]);
	close(pipes[0][1]);
	close(pipes[1][0]);
	close(pipes[1][1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
}