/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pibon_operations_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 13:20:18 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:57:09 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		FINDS PIBON IN STACK A OR B
*/

int		pibon_index(t_env *env, char stack)
{
	int		i;

	i = 0;
	if (stack == 'a')
	{
		i = env->top_a;
		while (i < env->argnb - 1 && env->a[i] != env->pibon_a)
			i++;
		if (i == env->argnb - 1 && env->a[i] == env->pibon_a)
			return (i);
	}
	if (stack == 'b')
	{
		i = env->top_b;
		while (i < env->argnb - 1 && env->b[i] != env->pibons_b[0])
			i++;
		if (i == env->argnb - 1 && env->b[i] == env->pibons_b[0])
			return (i);
	}
	return (i);
}

/*
***		FINDING THE PIVOT OF B WHEN PUSHING FROM A TO B
*/

int		pivot(t_env *env, char stackletter, int first, int last)
{
	int		*sorted;
	int		ret;
	int		**stack;

	stack = stackletter == 'a' ? &env->a : &env->b;
	if (last <= first && stackletter == 'b' && env->sz_pib_b > 0)
	{
		remove_pibon(env);
		return (pivot(env, 'b', env->top_b, pibon_index(env, 'b') - 1));
	}
	sorted = ft_init_int(last - first + 1);
	sorted = copy_inttab(*stack, sorted, first, last);
	sorted = bubble_sort(sorted, last - first + 1);
	ret = sorted[(last - first) / 2];
	free(sorted);
	return (ret);
}

/*
***		UPDATE PIBON OF A
*/

int		pibon_a(t_env *env)
{
	int		i;

	i = env->argnb - 1;
	while (i > env->top_a)
	{
		if (env->a[i] != env->sorted[i])
			break ;
		else
			i--;
		if (i == env->top_a && env->a[i] == env->sorted[i])
			return (env->a[env->top_a]);
	}
	return (i != env->argnb - 1 ? env->a[i + 1] : 0);
}

/*
***		FIND INDEX OF INT
*/

int		index_int(int *tab, int start, int end, int needle)
{
	int		i;

	i = start;
	while (i <= end)
	{
		if (tab[i] == needle)
			return (i);
		i++;
	}
	return (-1);
}
