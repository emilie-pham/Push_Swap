/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:47:23 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:59:15 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***     SORT LAST 2 OF STACK A
*/

void	sort2_a(t_env *env)
{
	int		top;

	top = env->top_a;
	if (env->a[top] < env->a[top + 1])
	{
		operation(env, "sa\n");
		swap_operations(env, "sa\n");
	}
}

/*
***		SORT LAST 3 OF STACK A
*/

void	sort3_a(t_env *env)
{
	while (!(env->a[env->top_a] < env->a[env->top_a + 1]
		&& env->a[env->top_a + 1] < env->a[env->top_a + 2]))
	{
		if (env->a[env->top_a] < env->a[env->top_a + 1])
		{
			operation(env, "rra\n");
			reverse_operations(env, "rra\n");
		}
		else if (env->a[env->top_a] > env->a[env->top_a + 1]
		&& env->a[env->top_a] > env->a[env->top_a + 2])
		{
			operation(env, "ra\n");
			rotate_operations(env, "ra\n");
		}
		else
		{
			operation(env, "sa\n");
			swap_operations(env, "sa\n");
		}
	}
}

/*
***		SORT LESS THAN 4 OF STACK A
*/

void	less_than_four_numbers_at_stack_a(t_env *env)
{
	if (env->a_nb == 3)
		sort3_a(env);
	if (env->a_nb == 2)
		sort2_a(env);
}
