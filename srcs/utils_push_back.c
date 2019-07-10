/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:34:11 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:59:57 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		PUSH TO A WHILE THE STACK IN B IS IN ORDER
*/

void	push_back_in_order(t_env *env)
{
	while (env->b_nb && env->b[env->top_b] == env->sorted[env->top_a - 1])
	{
		if (env->sz_pib_b > 0 && env->b[env->top_b] == env->pibons_b[0])
			remove_pibon(env);
		operation(env, "pa\n");
		push_operations(env, "pa\n");
		env->pibon_a = env->a[env->top_a];
	}
}

/*
***		GET CURRENT PIBON VALUE (BETWEEN TWO PIVOT VALUES)
*/

int		calculate_the_pibon_stack_b(t_env *env)
{
	int		current_pibon;

	if (env->sz_pib_b < 2)
	{
		current_pibon = pivot(env, 'b', env->top_b, env->argnb - 1);
		add_pibon(env, current_pibon);
	}
	else
	{
		current_pibon = pivot(env, 'b', env->top_b, pibon_index(env, 'b') - 1);
		if (current_pibon < env->pibons_b[0])
		{
			current_pibon = env->pibons_b[0];
			remove_pibon(env);
		}
	}
	return (current_pibon);
}

/*
***		PUSH OR ROTATE FROM B TO A
*/

void	b_to_a(t_env *env, int current_pibon, int *count_rotate)
{
	if (env->b[env->top_b] >= current_pibon)
	{
		operation(env, "pa\n");
		push_operations(env, "pa\n");
		if (env->a[env->top_a] == current_pibon)
		{
			operation(env, "ra\n");
			rotate_operations(env, "ra\n");
			env->pushed_pibon = 1;
		}
		if (env->a[env->top_a] > env->a[env->top_a + 1])
		{
			operation(env, "sa\n");
			swap_operations(env, "sa\n");
		}
		env->pibon_a = pibon_a(env);
	}
	else if (env->b_nb > 1)
	{
		operation(env, "rb\n");
		rotate_operations(env, "rb\n");
		(*count_rotate)++;
	}
}

/*
***		ROTATE OR REVERSE ROTATE
*/

void	rotate_or_reverse(t_env *env, int count_rotate)
{
	if (count_rotate > env->b_nb / 2)
	{
		operation(env, "rb\n");
		rotate_operations(env, "rb\n");
	}
	else
	{
		while (count_rotate)
		{
			operation(env, "rrb\n");
			reverse_operations(env, "rrb\n");
			count_rotate--;
		}
	}
}

/*
***		SORT FROM B TO A
*/

void	sort_b_to_a(t_env *env, int current_pibon)
{
	int		count_rotate;

	count_rotate = 0;
	while (env->b[env->top_b] != env->pibons_b[0] && env->b_nb > 0)
		b_to_a(env, current_pibon, &count_rotate);
	rotate_or_reverse(env, count_rotate);
	if (env->pushed_pibon == 1)
	{
		operation(env, "rra\n");
		reverse_operations(env, "rra\n");
		if (check_order_stack(env) != 0)
		{
			operation(env, "pb\n");
			push_operations(env, "pb\n");
			add_pibon(env, current_pibon);
		}
		if (env->a[env->top_a] > env->a[env->top_a + 1])
		{
			operation(env, "sa\n");
			swap_operations(env, "sa\n");
		}
		env->pibon_a = pibon_a(env);
	}
}
