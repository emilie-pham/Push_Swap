/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:52:06 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 12:00:36 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		STACK TOP A OR B
*/

int		top(t_env *env, char stack)
{
	if (stack == 'a')
		return (env->argnb - env->a_nb);
	else if (stack == 'b')
		return (env->argnb - env->b_nb);
	return (0);
}

/*
***		COPY TAB OF INT
*/

int		*copy_inttab(int *stack, int *copy, int start, int finish)
{
	int i;

	i = 0;
	while (i < finish - start + 1)
	{
		copy[i] = stack[start + i];
		i++;
	}
	return (copy);
}

/*
***		CHECK ORDER OF STACK
*/

int		check_order_stack(t_env *env)
{
	int		i;

	i = env->top_a;
	while (i < env->argnb)
	{
		if (env->a[i] != env->sorted[i])
			return (-1);
		i++;
	}
	return (0);
}

/*
***		SWAP TOP OF STACKS A AND B
*/

void	check_top_both_stacks(t_env *env)
{
	if (env->a[env->top_a] > env->a[env->top_a + 1])
	{
		operation(env, "sa\n");
		swap_operations(env, "sa\n");
	}
	if (env->b[env->top_b] < env->b[env->top_b + 1])
	{
		operation(env, "sb\n");
		swap_operations(env, "sb\n");
	}
}

/*
***		FREE STRUCTURE
*/

void	ft_free(t_env *env)
{
	free(env->a);
	free(env->b);
	free(env->sorted);
	free(env->pibons_b);
	free(env->operations);
}
