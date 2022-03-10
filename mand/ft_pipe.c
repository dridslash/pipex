/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:00:44 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/07 12:01:08 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		printf("fd %d\n",fd[0]);
		write(1, "error occured during pipe\n", 27);
		exit(1);
	}
}