/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pibon_operations_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:36:38 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:57:34 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		checkmore(int *tab, int first, int last, int pibon)
{
	int		i;

	i = first;
	while (i < last)
	{
		if (tab[i] > pibon)
			return (i);
		i++;
	}
	return (-1);
}

/*
***		ADD AN INT AT THE BEGINNING OF TAB
*/

void	add_pibon(t_env *env, int pibon)
{
	int		i;
	int		*out;

	i = 1;
	if (checkmore(env->b, env->top_b, env->argnb - 1, pibon) != -1)
		return ;
	if (!(out = ft_init_int(env->sz_pib_b + 1)))
		return ;
	out[0] = pibon;
	while (i < env->sz_pib_b + 1)
	{
		out[i] = env->pibons_b[i - 1];
		i++;
	}
	free(env->pibons_b);
	env->pibons_b = out;
	env->sz_pib_b += 1;
}

/*
***		REMOVES AN INT FROM THE BEGINNING OF TAB
*/

void	remove_pibon(t_env *env)
{
	int		*out;

	out = ft_init_int(env->sz_pib_b - 1);
	out = copy_inttab(env->pibons_b, out, 1, env->sz_pib_b - 1);
	free(env->pibons_b);
	env->pibons_b = out;
	if (env->sz_pib_b > 0)
		env->sz_pib_b -= 1;
}

/*
***		ROTATE THE PIBON IN STACK B AND ADD IT TO THE LIST OF PIBONS
*/

void	rotate_pibon(t_env *env)
{
	if (env->pushed_pibon == 1 && env->b[env->argnb - 1] != env->min)
	{
		operation(env, "rrb\n");
		reverse_operations(env, "rrb\n");
		add_pibon(env, env->b[env->top_b]);
	}
}
