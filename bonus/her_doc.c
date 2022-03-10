/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 14:24:22 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/10 10:28:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand/pipex.h"
#include "get_next_line.h"

int main(int argc , char **argv,char **envp)
{
	int pid1 = 0;
	int pid2 = 0;
	int fd[2];
	int ch_p[2];
	pipe(fd);
	pipe(ch_p);
	int i =0;
		write(1,"her_doc>",8);
		char **ag;
	char *str = get_next_line(0);
	char *limiter = ft_strjoin_non_free(argv[2],"\n");
	while(str == NULL || ft_strcmp(str,limiter))
	{
		if(str != NULL)
		{
		write(ch_p[1],str,ft_strlen(str));
		write(1,"her_doc>",8);
		}
		free(str);
		str = get_next_line(0);
	}
	free(limiter);
	close(ch_p[1]);
	pid1 = fork();
	if(pid1 == 0)
	{
	dup2(ch_p[0],0);
	close(fd[0]);
	dup2(fd[1],1);
	close(fd[1]);
	close(ch_p[1]);
	ag = get_params(3, argv);
	if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
		{
		perror("error procees");
		exit(1);
		}
	exit(0);
	}
	pid2 = fork();
	if(pid2 == 0)
	{
		char **ag;
		int out_file = open(argv[argc - 1],O_APPEND | O_CREAT | O_RDWR,0777);
		dup2(fd[0],0);
		dup2(out_file,1);
		close(fd[0]);
		close(fd[1]);
		close(ch_p[0]);
		close(ch_p[1]);
		ag = get_params(4, argv);
		if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
			{
			perror("error procees");
			exit(1);
			}
		exit(0);
	}
	close(fd[0]);
	close(fd[1]);
	close(ch_p[0]);
	close(ch_p[1]);
	waitpid(pid1,NULL,0);
	waitpid(pid2,NULL,0);
}