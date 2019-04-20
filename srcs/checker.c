/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:07:56 by epham             #+#    #+#             */
/*   Updated: 2019/04/20 13:27:43 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		CHECK THAT INT TABLE IS SORTED
*/

int		check_order(t_env *env)
{
	int i;
	int j;

	i = 0;
	if (env->argnb > env->a_nb)
	{
		ft_putendl("KO");
		return (-1);
	}
	while (env->a[i] && i < env->argnb)
	{
		j = i + 1;
		while (env->a[j] && j < env->argnb)
		{
			if (env->a[i] > env->a[j])
			{
				ft_putendl("KO");
				return (-1);
			}
			j++;
		}
		i++;
	}
	ft_putendl("OK");
	return (0);
}

/*
***		GET INSTRUCTIONS
*/

int		get_instructions(t_env *env)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) == 1)
	{
		i = 1;
		if (ft_strcmp(line, "sa") == 0 || ft_strcmp(line, "sb") == 0
			|| ft_strcmp(line, "ss") == 0)
			swap_operations(env, line);
		else if (ft_strcmp(line, "pa") == 0 || ft_strcmp(line, "pb") == 0)
			push_operations(env, line);
		else if (ft_strcmp(line, "ra") == 0 || ft_strcmp(line, "rb") == 0
			|| ft_strcmp(line, "rr") == 0)
			rotate_operations(env, line);
		else if (ft_strcmp(line, "rra") == 0 || ft_strcmp(line, "rrb") == 0
			|| ft_strcmp(line, "rrr") == 0)
			reverse_operations(env, line);
		else
			i = 0;
		ft_strdel(&line);
		visual(env);
		if (i == 0)
			return (-1);
	}
	return (i == 1 ? 0 : -1);
}

int		main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 1;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (ac > 1)
	{
		if (parser(ac, av, env) == -1)
			return (error(env));
		if (get_instructions(env) == -1)
			return (error(env));
		check_order(env);
	}
	free(env);
	return (0);
}
