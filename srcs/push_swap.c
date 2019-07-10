/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:38:29 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:58:18 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_env *env)
{
	if (check_order_stack(env) == 0 && env->top_a == 0)
		return ;
	else if (is_almost_sorted(env) == 1)
		sort_almost_sorted(env);
	else if (is_few_numbers(env) == 1)
		sort_few_numbers(env);
	else
		sort_random(env);
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
		push_swap(env);
		optimize(env);
		ft_putstr(env->operations);
		ft_free(env);
	}
	free(env);
	return (0);
}
