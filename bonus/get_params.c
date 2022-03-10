/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:08:53 by mnaqqad           #+#    #+#             */
/*   Updated: 2022/03/07 18:12:36 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "../mand/pipex.h"

char	**get_params(int index, char **argv)
{
	char	**arg ;

	arg = ft_split(argv[index], ' ');
	return (arg);
}
