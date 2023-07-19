/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youlhafi <youlhafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 08:49:26 by youlhafi          #+#    #+#             */
/*   Updated: 2023/07/11 11:41:45 by youlhafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset_export(t_pip *p, char *cmd)
{
	char	*env;
	int		i;
	int		j;
	int		k;
	char	**res;
	
	j = 0;
	i = 0;
	env = NULL;
	if (!p->export)
		return ;
	while (cmd[j] && cmd[j] != '=')
		j++;
	while (p->export[i])
		i++;
	res = malloc(sizeof (char *) * i);
	if (i == 1)
	{
		res = NULL;
		free(p->export);
		p->export = res;
		return ;
	}
	i = 0;
	k = 0;
	while (p->export[i])
	{
		if (ft_strncmp(p->export[i], cmd, j) != 0)
			res[k++] = ft_strdup(p->export[i]);
		i++;
	}
	res[k] = NULL;
	free_double(p->export);
	p->export = res;
}

void	ft_unset_help(t_pip *p, char *cmd)
{
	char	*env;
	int		i;
	int		j;
	int		k;
	char	**res;
	
	j = 0;
	i = 0;
	env = NULL;
	if (if_valid_name_export(cmd))
	{
		if (!p->envp)
			return ;
		if (!if_exist(p, cmd))
			return ;
		while (cmd[j] && cmd[j] != '=')
			j++;
		while (p->envp[i])
			i++;
		res = malloc(sizeof (char *) * i);
		i = 0;
		k = 0;
		while (p->envp[i])
		{
			if (ft_strncmp(p->envp[i], cmd, j) != 0)
				res[k++] = ft_strdup(p->envp[i]);
			i++;
		}
		res[k] = NULL;
		free_double(p->envp);
		p->envp = res;
	}
	else
		ft_error("not a valid identifier", 1, cmd, "unset");
}

void	ft_unset(t_pip *p, t_cmd *cmds)
{
	int	i;
	
	i = 1;
	if (cmds->args[1])
	{
		while (cmds->args[i])
		{
			if (if_exist_export(p, cmds->args[i]))
				ft_unset_export(p, cmds->args[i]);
			ft_unset_help(p, cmds->args[i]);
			i++;
		}
	}
}
