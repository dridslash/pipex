/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 12:02:16 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/07 15:14:50 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mand/pipex.h"


int main(void)
{
	int pid1 = 0;
	int pid2 = 0;
	int pid3 = 0;
	int fd[3][2];
	int i = 0;
	while(i < 3)
	{
		pipe(fd[i]);
		i++;
	}
	pid1 = fork();
	if(pid1 == 0)
	{
		close(fd[0][1]);
		close(fd[1][0]);
		close(fd[2][1]);
		close(fd[2][0]);
		int x;
		read(fd[0][0],&x,sizeof(int));
		printf("child reseveid %d\n",x);
		x+= 1;
		write(fd[1][1],&x,sizeof(int));
		printf("child wrote %d\n",x);
		close(fd[0][0]);
		close(fd[1][1]);
		exit(0);
	}
	pid2 = fork();
	if(pid2 == 0)
	{
		close(fd[0][1]);
		close(fd[0][0]);
		close(fd[1][1]);
		close(fd[2][0]);
		int x;
		read(fd[1][0],&x,sizeof(int));
		printf("child reseveid %d\n",x);
		x+= 1;
		write(fd[2][1],&x,sizeof(int));
		printf("child wrote %d\n",x);
		close(fd[1][0]);
		close(fd[2][1]);
		exit(0);
	}
	int x = 0;
	write(fd[0][1],&x,sizeof(int));
	close(fd[0][0]);
	close(fd[1][1]);
	close(fd[1][0]);
	close(fd[2][1]);
	close(fd[0][0]);
	read(fd[2][0],&x,sizeof(int));
	printf("result is %d\n",x);
	close(fd[0][1]);
	close(fd[2][0]);
}