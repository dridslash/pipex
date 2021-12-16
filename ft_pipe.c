/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:00:44 by mnaqqad           #+#    #+#             */
/*   Updated: 2021/12/15 12:17:37 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_pipe(int *fd)
{
	if (pipe(fd) == -1)
	{
		write(1, "error occured during pipe\n", 27);
		exit(1);
	}
}
