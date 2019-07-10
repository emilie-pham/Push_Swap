/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:47:23 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:59:29 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		SORT LAST 2 OF STACK B AND PUSHBACK
*/

void	sort2_b(t_env *env)
{
	int		top;

	top = env->top_b;
	if (env->b[top] < env->b[top + 1])
	{
		operation(env, "sb\n");
		swap_operations(env, "sb\n");
	}
	operation(env, "pa\npa\n");
	push_operations(env, "pa\n");
	push_operations(env, "pa\n");
}

/*
***		SORT LAST 3 OF STACK B AND PUSHBACK
*/

void	sort3_b(t_env *env)
{
	while (!(env->b[env->top_b] > env->b[env->top_b + 1]
		&& env->b[env->top_b + 1] > env->b[env->top_b + 2]))
	{
		if (env->b[env->top_b] < env->b[env->top_b + 1])
		{
			operation(env, "rb\n");
			rotate_operations(env, "rb\n");
		}
		else if (env->b[env->top_b] > env->b[env->top_b + 2])
		{
			operation(env, "sb\n");
			swap_operations(env, "sb\n");
		}
		else
		{
			operation(env, "rrb\n");
			reverse_operations(env, "rrb\n");
		}
	}
	operation(env, "pa\npa\npa\n");
	push_operations(env, "pa\n");
	push_operations(env, "pa\n");
	push_operations(env, "pa\n");
}

/*
***		SORT LESS THAN 4 OF STACK B AND PUSH BACK
*/

void	less_than_four_numbers_at_stack_b(t_env *env)
{
	if (env->b_nb == 3)
		sort3_b(env);
	if (env->b_nb == 2)
		sort2_b(env);
	else
	{
		operation(env, "pa\n");
		push_operations(env, "pa\n");
	}
}
