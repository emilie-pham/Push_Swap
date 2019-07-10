/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:38:29 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:43:39 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		is_few_numbers(t_env *env)
{
	if (env->argnb <= 3)
		return (1);
	return (-1);
}

void	sort_few_numbers(t_env *env)
{
	if (env->argnb == 3)
		sort3_a(env);
	if (env->argnb == 2)
		sort2_a(env);
}

int		is_almost_sorted(t_env *env)
{
	int		i;

	i = 0;
	while (env->a[i] < env->a[i + 1])
		i++;
	if (env->a[i] != env->max || env->a[i + 1] != env->min)
		return (-1);
	i++;
	while (i < env->argnb - 1 && env->a[i] < env->a[i + 1])
		i++;
	if (i == env->argnb - 1 && env->a[i] < env->a[0])
		return (1);
	return (-1);
}

void	sort_almost_sorted(t_env *env)
{
	int		i;

	i = 0;
	while (env->a[i] != env->max)
		i++;
	while (i >= env->argnb / 2 && check_order_stack(env))
	{
		operation(env, "rra\n");
		reverse_operations(env, "rra\n");
	}
	while (i < env->argnb / 2 && check_order_stack(env))
	{
		operation(env, "ra\n");
		rotate_operations(env, "ra\n");
	}
}
