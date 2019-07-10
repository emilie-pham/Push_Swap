/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:31:08 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:56:13 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		SWAP OPERATIONS
*/

void	swap_operations(t_env *env, char *instruction)
{
	int swap;

	if (ft_strcmp(instruction, "sa\n") == 0 && env->a_nb > 1)
	{
		swap = env->a[top(env, 'a')];
		env->a[top(env, 'a')] = env->a[top(env, 'a') + 1];
		env->a[top(env, 'a') + 1] = swap;
	}
	else if (ft_strcmp(instruction, "sb\n") == 0 && env->b_nb > 1)
	{
		swap = env->b[top(env, 'b')];
		env->b[top(env, 'b')] = env->b[top(env, 'b') + 1];
		env->b[top(env, 'b') + 1] = swap;
	}
	else if (ft_strcmp(instruction, "ss\n") == 0)
	{
		swap_operations(env, "sa\n");
		swap_operations(env, "sb\n");
	}
	visual(env);
}

/*
***		PUSH OPERATIONS
*/

void	push_operations(t_env *env, char *instruction)
{
	if (ft_strcmp(instruction, "pa\n") == 0 && (env->b_nb > 0))
	{
		env->a[top(env, 'a') - 1] = env->b[top(env, 'b')];
		env->b[top(env, 'b')] = 0;
		env->b_nb--;
		env->a_nb++;
	}
	else if (ft_strcmp(instruction, "pb\n") == 0 && (env->a_nb > 0))
	{
		env->b[top(env, 'b') - 1] = env->a[top(env, 'a')];
		env->a[top(env, 'a')] = 0;
		env->a_nb--;
		env->b_nb++;
	}
	env->top_a = top(env, 'a');
	env->top_b = top(env, 'b');
	visual(env);
}

/*
***		ROTATE OPERATIONS
*/

void	rotate_operations(t_env *env, char *instruction)
{
	int		first;
	int		topnb;

	if (ft_strcmp(instruction, "ra\n") == 0 && env->a_nb > 0)
	{
		topnb = top(env, 'a');
		first = env->a[topnb];
		while (++(topnb) < env->argnb)
			env->a[topnb - 1] = env->a[topnb];
		env->a[env->argnb - 1] = first;
	}
	else if (ft_strcmp(instruction, "rb\n") == 0 && env->b_nb > 0)
	{
		topnb = top(env, 'b');
		first = env->b[topnb];
		while (++(topnb) < env->argnb)
			env->b[topnb - 1] = env->b[topnb];
		env->b[env->argnb - 1] = first;
	}
	else if (ft_strcmp(instruction, "rr\n") == 0)
	{
		rotate_operations(env, "ra\n");
		rotate_operations(env, "rb\n");
	}
	visual(env);
}

/*
***		REVERSE OPERATIONS
*/

void	reverse_operations(t_env *env, char *instruction)
{
	int i;
	int last;

	i = env->argnb - 1;
	if (ft_strcmp(instruction, "rra\n") == 0 && env->a_nb > 0)
	{
		last = env->a[env->argnb - 1];
		while (--i + 1 > top(env, 'a'))
			env->a[i + 1] = env->a[i];
		env->a[top(env, 'a')] = last;
	}
	else if (ft_strcmp(instruction, "rrb\n") == 0 && env->b_nb > 0)
	{
		last = env->b[env->argnb - 1];
		while (--i + 1 > top(env, 'b'))
			env->b[i + 1] = env->b[i];
		env->b[top(env, 'b')] = last;
	}
	else if (ft_strcmp(instruction, "rrr\n") == 0)
	{
		reverse_operations(env, "rra\n");
		reverse_operations(env, "rrb\n");
	}
	visual(env);
}
