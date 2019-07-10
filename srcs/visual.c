/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:47:23 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 12:00:53 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		VISUAL ARGUMENT
*/

int		debug(t_env *env, char **av, int ac)
{
	if (ac > 2 && ft_strcmp(av[1], "-d") == 0)
	{
		env->debug = 1;
		return (2);
	}
	else
	{
		env->debug = 0;
		return (1);
	}
}

int		column_a(t_env *env, int index)
{
	int		i;
	int		j;

	i = index;
	j = 11 - nblen(env->a[i]);
	if (env->pibon_a == env->a[i] && i >= env->top_a)
		ft_putstr("|     * ");
	else
		ft_putstr("|       ");
	ft_putnbr(env->a[i]);
	while (j--)
		ft_putchar(' ');
	return (i);
}

int		is_pibon(int *pibons_b, int sz_pib_b, int nbr)
{
	int		i;

	i = 0;
	while (i < sz_pib_b)
	{
		if (pibons_b[i] == nbr)
			return (1);
		i++;
	}
	return (-1);
}

int		column_b(t_env *env, int index)
{
	int		i;
	int		j;

	i = index;
	j = 11 - nblen(env->b[i]);
	if (is_pibon(env->pibons_b, env->sz_pib_b, env->b[i]) == 1
			&& i >= env->top_b)
		ft_putstr("|     * ");
	else
		ft_putstr("|       ");
	ft_putnbr(env->b[i]);
	while (j--)
		ft_putchar(' ');
	ft_putendl("|");
	return (i);
}

void	visual(t_env *env)
{
	int i;

	i = -1;
	if (env->debug == 1)
	{
		ft_putendl(" __________________ __________________ ");
		ft_putendl("|                  |                  |");
		ft_putendl("|       a          |       b          |");
		ft_putendl("|__________________|__________________|");
		ft_putendl("|                  |                  |");
		while (++i < env->argnb)
		{
			i = column_a(env, i);
			i = column_b(env, i);
		}
		ft_putendl("|__________________|__________________|\n");
	}
}
