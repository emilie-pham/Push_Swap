/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 17:09:07 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:58:01 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		PUSHBACK
*/

int		push_back(t_env *env)
{
	env->current_pibon_b = 0;
	env->pushed_pibon = 0;
	if (env->b_nb == 0 && check_order_stack(env) == 0 && env->top_a == 0)
		return (0);
	if (env->b_nb < 4 && env->b_nb > 0)
		less_than_four_numbers_at_stack_b(env);
	push_back_in_order(env);
	if (env->b_nb)
	{
		env->current_pibon_b = calculate_the_pibon_stack_b(env);
		sort_b_to_a(env, env->current_pibon_b);
		if (env->b_nb < 4 && env->b_nb > 0)
		{
			less_than_four_numbers_at_stack_b(env);
			if (check_order_stack(env) == 0)
			{
				env->pibon_a = pibon_a(env);
				return (0);
			}
		}
	}
	if (env->a_nb)
		env->pibon_a = pibon_a(env);
	return (push_to(env));
}
