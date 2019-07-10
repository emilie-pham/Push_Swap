/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:47:23 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:56:52 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		SORTS STACK
*/

int		*bubble_sort(int *stack, int stacklen)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < stacklen)
	{
		j = i + 1;
		while (j < stacklen)
		{
			if (stack[i] > stack[j])
			{
				tmp = stack[i];
				stack[i] = stack[j];
				stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
	return (stack);
}

/*
***		COUNT HOW MANY NUMBERS WILL BE IN INTTABLE A
*/

int		count_argnb(char *av)
{
	char	**inttab;
	int		i;
	int		argnb;

	inttab = ft_strsplit(av, ' ');
	i = 0;
	argnb = 0;
	while (inttab[i])
	{
		if (check_atoi(inttab[i]) == -1)
		{
			ft_tabdel(inttab);
			return (-1);
		}
		argnb++;
		i++;
	}
	ft_tabdel(inttab);
	if (argnb == 0)
		return (-1);
	return (argnb);
}

/*
***		GET LIST OF ARGUMENTS IN INT TABLE
*/

int		*get_argtable(int argnb, char **av, int i, int j)
{
	int		*a;
	char	**atab;
	int		k;

	a = ft_init_int(argnb);
	while (av[i] && a)
	{
		k = 0;
		if (av[i])
		{
			if ((atab = ft_strsplit(av[i], ' ')) != NULL)
			{
				while (atab[k])
				{
					a[j] = ft_atoi(atab[k]);
					k++;
					j++;
				}
				i++;
				ft_tabdel(atab);
			}
		}
	}
	return (a);
}

/*
***		INITIALIZING THE STRUCTURE
*/

void	initialize(t_env *env)
{
	env->sorted = ft_init_int(env->argnb);
	env->sorted = copy_inttab(env->a, env->sorted, 0, env->argnb - 1);
	env->sorted = bubble_sort(env->sorted, env->argnb);
	env->min = env->sorted[0];
	env->max = env->sorted[env->argnb - 1];
	env->a_nb = env->argnb;
	env->b_nb = 0;
	if (env->a)
		env->pibon_a = env->a[env->argnb - 1];
	env->pibons_b = ft_init_int(1);
	env->sz_pib_b = 1;
	env->pibons_b[0] = env->min;
	env->pushed_pibon = 0;
	env->top_a = top(env, 'a');
	env->top_b = top(env, 'b');
	env->operations = ft_strnew(1);
}

/*
***		PARSER
*/

int		parser(int ac, char **av, t_env *env)
{
	int		i;
	int		count;

	env->argnb = 0;
	env->a_nb = 0;
	env->b_nb = 0;
	i = debug(env, av, ac);
	while (i < ac)
	{
		count = count_argnb(av[i]);
		env->argnb = count != -1 ? env->argnb + count : -1;
		if (env->argnb == -1)
			return (-2);
		i++;
	}
	i = debug(env, av, ac);
	env->a = get_argtable(env->argnb, av, i, 0);
	if (env->a)
		env->b = ft_init_int(env->argnb);
	if (check_double(env->a, env->argnb) == -1)
		return (-1);
	initialize(env);
	return (0);
}
