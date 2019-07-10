/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push_to.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 10:28:53 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 12:00:10 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		CHECK THAT THERE ARE STILL NUMBERS < PIVOT IN STACK A
*/

int		checkless(int *tab, int top, int tab_len, int pibon)
{
	int		i;

	i = top;
	while (i < tab_len)
	{
		if (tab[i] <= pibon)
			return (i);
		i++;
	}
	return (-1);
}

/*
***		PUSH OR ROTATE FROM A TO B
*/

void	less_or_equal_than_pibon(t_env *env, int pibon)
{
	operation(env, "pb\n");
	push_operations(env, "pb\n");
	if (env->b[env->top_b] == env->min)
	{
		operation(env, "rb\n");
		rotate_operations(env, "rb\n");
	}
	else if (env->b[env->top_b] == pibon)
	{
		operation(env, "rb\n");
		rotate_operations(env, "rb\n");
		env->pushed_pibon = 1;
	}
	if (env->b[env->top_b] < env->b[env->top_b + 1])
	{
		operation(env, "sb\n");
		swap_operations(env, "sb\n");
	}
}

/*
***		PUSH FROM A TO B
*/

void	a_to_b(t_env *env)
{
	int		pibon;
	int		count_rotations;

	pibon = pivot(env, 'a', top(env, 'a'), pibon_index(env, 'a'));
	while ((pibon_index(env, 'a') - env->top_a > 1)
		&& check_order_stack(env) == -1)
	{
		env->pushed_pibon = 0;
		count_rotations = sort_a_to_b(env, pibon, 0);
		rotate_pibon_min(env, pibon, count_rotations);
		if (env->a_nb && pibon_index(env, 'a') - top(env, 'a') > 1)
		{
			operation(env, "pb\n");
			push_operations(env, "pb\n");
			add_pibon(env, pibon);
		}
	}
	if (env->a_nb)
		env->pibon_a = pibon_a(env);
}

/*
***		SORT FROM A TO B
*/

int		sort_a_to_b(t_env *env, int pibon, int count_rotations)
{
	env->pibon_a = pibon_a(env);
	while (env->a_nb && env->a[env->top_a] != env->pibon_a)
	{
		if (env->top_a != 0 && env->a[env->top_a] <= pibon
		&& pibon != env->sorted[pibon_index(env, 'a') - 1])
			less_or_equal_than_pibon(env, pibon);
		else
		{
			operation(env, "ra\n");
			rotate_operations(env, "ra\n");
			count_rotations += 1;
		}
	}
	rotate_pibon(env);
	if (env->a_nb)
		env->pibon_a = pibon_a(env);
	check_top_both_stacks(env);
	return (count_rotations);
}

/*
***		REVERSE ROTATE IN A STACK AND IN STACK B ONLY PIBON
*/

void	rotate_pibon_min(t_env *env, int pibon, int rotations)
{
	int		index_max;

	rotate_pibon(env);
	if (env->b[env->argnb - 1] != pibon && env->b[env->argnb - 1] != env->min)
	{
		operation(env, "rrb\nsb\nrb\n");
		reverse_operations(env, "rrb\n");
		swap_operations(env, "sb\n");
		rotate_operations(env, "rb\n");
		add_pibon(env, env->b[env->top_b]);
	}
	env->pushed_pibon = 0;
	index_max = index_int(env->a, env->top_a, env->argnb - 1, env->max) + 1;
	pibon = pivot(env, 'a', index_max, env->argnb - 1);
	while (rotations--)
	{
		operation(env, "rra\n");
		reverse_operations(env, "rra\n");
		if (env->a[env->top_a] <= pibon)
			less_or_equal_than_pibon(env, pibon);
		check_top_both_stacks(env);
		if (env->b[env->argnb - 1] == pibon)
			rotate_pibon(env);
	}
}
