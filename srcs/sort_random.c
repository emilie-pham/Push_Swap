/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_random.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:13:47 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 14:26:02 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		CHECK WHEN STACK A HAS 2 NUMBERS LEFT
*/

void	last_check(t_env *env)
{
	if (env->a_nb == 2)
	{
		env->pibons_b[0] = env->a[env->argnb - 1] >= env->a[env->argnb - 2]
		? env->a[env->argnb - 2] : env->a[env->argnb - 1];
		if (env->a[env->argnb - 1] > env->a[env->argnb - 2])
		{
			operation(env, "pb\n");
			push_operations(env, "pb\n");
		}
		else
		{
			operation(env, "ra\npb\n");
			rotate_operations(env, "ra\n");
			push_operations(env, "pb\n");
		}
	}
}

/*
***		PUSH OR ROTATE FROM A TO B
*/

void	sort_from_a_to_b_first_push(t_env *env, int pibon)
{
	if (env->a[top(env, 'a')] == env->min)
	{
		operation(env, "pb\nrb\n");
		push_operations(env, "pb\n");
		rotate_operations(env, "rb\n");
	}
	else if (env->a[top(env, 'a')] < pibon)
	{
		operation(env, "pb\n");
		push_operations(env, "pb\n");
	}
	else if (env->a[top(env, 'a')] == pibon)
	{
		operation(env, "pb\nrb\n");
		push_operations(env, "pb\n");
		rotate_operations(env, "rb\n");
		env->pushed_pibon = 1;
	}
	else
	{
		operation(env, "ra\n");
		rotate_operations(env, "ra\n");
	}
}

/*
***		SORT WHILE FIRST PUSHING FROM A TO B
*/

void	sort_first_push(t_env *env, int pibon)
{
	while (checkless(env->a, top(env, 'a'), env->argnb, pibon) != -1)
		sort_from_a_to_b_first_push(env, pibon);
	if (env->pushed_pibon == 1)
	{
		operation(env, "rrb\n");
		reverse_operations(env, "rrb\n");
	}
	if (env->b[env->argnb - 1] == pibon)
	{
		operation(env, "rrb\nsb\nrb\n");
		reverse_operations(env, "rrb\n");
		swap_operations(env, "sb\n");
		rotate_operations(env, "rb\n");
	}
	add_pibon(env, pibon);
}

/*
***		FIRST PUSH FROM A TO B
*/

void	sort_random(t_env *env)
{
	int		pibon;

	while (env->a_nb > 1 && check_order_stack(env) == -1)
	{
		env->pushed_pibon = 0;
		pibon = pivot(env, 'a', top(env, 'a'), env->argnb - 1);
		sort_first_push(env, pibon);
		last_check(env);
	}
	while (env->sz_pib_b > 0 && env->pibons_b[0] >= env->a[env->top_a])
		remove_pibon(env);
	env->pibon_a = env->a[top(env, 'a')];
	while (!(check_order_stack(env) == 0 && env->a_nb == env->argnb))
		push_back(env);
}
