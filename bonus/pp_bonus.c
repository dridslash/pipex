/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pp_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 10:35:41 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/09 09:32:09 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand/pipex.h"

void ft_dup_close(int *pipes, int size,int in_file, int out_file)
{
	int i =0;
	dup2(in_file,0);
	dup2(out_file,1);
	while(i < size)
	{
		close(pipes[i]);
		i++;
	}
}

int main(int argc,char **argv, char **envp)
{
	int nb_pr = argc - 3;
	int *pipes = malloc(sizeof(int) * (nb_pr -  1) * 2);
	int *pids = malloc(sizeof(int) * nb_pr);
	int read_file = open(argv[1],O_RDONLY);
	int output_file = open(argv[argc - 1],O_CREAT | O_TRUNC | O_RDWR,0777);
	int k = 2;
	int i =0;
	int w =0;
	int l = 0;
	char **ag;
	while (w < (nb_pr - 1) * 2)
	{
		pipe(&pipes[w]);
		w+=2;
	}
	while(i < nb_pr)
	{
		pids[i] = fork();
		if(pids[i] == 0)
		{
			if(i == 0)
			{
				ft_dup_close(pipes,(nb_pr - 1)* 2,read_file,pipes[l + 1]);
			}
			else if(i + 1 == nb_pr)
			{
				ft_dup_close(pipes,(nb_pr - 1)* 2,pipes[l - 2],output_file);
			}
			else
			{
				ft_dup_close(pipes,(nb_pr - 1)* 2,pipes[l - 2],pipes[l + 1]);
			}
			ag = get_params(k, argv);
			if ((execve(get_path(ag[0], envp), ag, NULL) == -1))
			{
			perror("error procees");
			exit(1);
			}
		exit(0);
		}
		i++;
		k++;
		l +=2;
	}
	l = 0;
	while(l < (nb_pr - 1) * 2)
	{
		close(pipes[l]);
		l++;
	}
	while(wait(NULL) != -1);
	return (0);
}