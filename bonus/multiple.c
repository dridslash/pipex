/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiple.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:04:57 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/08 10:25:00 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand/pipex.h"

#define pr_number 3

int main(void)
{
	int pipes[pr_number + 1][2];
	int pids[pr_number];
	int i =0;
	int k = 0;
	int w =0;
	while(k < pr_number + 1)
	{
		pipe(pipes[k]);
		k++;
	}
	while(i < pr_number)
	{
	pids[i] = fork();
	if(pids[i] == 0)
	{
		int j =0;
		while(j < pr_number + 1)
		{
			if(i != j)
			{
				close(pipes[j][0]);
			}
			if(i + 1 != j)
			{
				close(pipes[j][1]);
			}
			j++;
		}
		int x;
		read(pipes[i][0],&x,sizeof(int));
		printf("got %d \n",x);
		x++;
		printf("wrote %d \n",x);
		write(pipes[i + 1][1],&x,sizeof(int));
		return (0);
	}
	i++;
	}
	int j =0;
	while(j < pr_number + 1)
		{
			if(j != pr_number)
			{
				close(pipes[j][0]);
			}
			if(j != 0)
			{
				close(pipes[j][1]);
			}
			j++;
		}
	int x = 0;
	write(pipes[0][1],&x,sizeof(int));
	read(pipes[pr_number][0],&x,sizeof(int));
	printf("result is %d\n",x);
	close(pipes[0][1]);
	close(pipes[pr_number][0]);
	while(w < pr_number)
	{
		wait(NULL);
		w++;
	}
	return (0);
}