/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:07:56 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:44:13 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		GET INSTRUCTIONS
*/

int		get_instructions(t_env *env)
{
	char	*line;
	int		i;
	int		out_gnl;

	i = 0;
	while (i != -1 && (out_gnl = get_next_line(0, &line)) == 1)
	{
		i++;
		if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
			|| ft_strcmp(line, "ss\n") == 0)
			swap_operations(env, line);
		else if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0)
			push_operations(env, line);
		else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
			|| ft_strcmp(line, "rr\n") == 0)
			rotate_operations(env, line);
		else if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
			|| ft_strcmp(line, "rrr\n") == 0)
			reverse_operations(env, line);
		else
			i = -1;
		ft_strdel(&line);
	}
	return (i != -1 && out_gnl != -1 ? 0 : -1);
}

int		main(int ac, char **av)
{
	t_env	*env;
	int		tmp;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (-1);
	if (ac > 1)
	{
		tmp = parser(ac, av, env);
		if (tmp == -1 || tmp == -2)
			return (error(env, tmp));
		visual(env);
		if (get_instructions(env) == -1)
			return (error(env, -3));
		check_order_stack(env) == 0 && env->argnb == env->a_nb
		? ft_putendl("OK") : ft_putendl("KO");
		ft_free(env);
	}
	free(env);
	return (0);
}
