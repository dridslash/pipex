/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaqqad <mnaqqad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 16:42:31 by mnaqqad           #+#    #+#             */
/*   Updated: 2021/12/16 09:43:01 by mnaqqad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	**env_path;
	char	*checkp;

	i = 0;
	env_path = ft_split(envp[6], ':');
	env_path[0] = ft_strtrim(env_path[0], "PATH=");
	while (env_path[i])
	{
		env_path[i] = ft_strjoin(env_path[i], "/");
		i++;
	}
	i = 0;
	while (env_path[i])
	{
		checkp = ft_strjoin(env_path[i], cmd);
		if (access(checkp, F_OK) == 0)
			return (checkp);
		free(checkp);
		i++;
	}
	return (NULL);
}
