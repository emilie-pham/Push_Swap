/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:47:23 by epham             #+#    #+#             */
/*   Updated: 2019/04/20 13:20:43 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
			free(inttab);
			return (-1);
		}
		argnb++;
		i++;
	}
	if (argnb == 0)
	{
		free(inttab);
		return (-1);
	}
	free(inttab);
	return (argnb);
}

/*
***		GET LIST OF ARGUMENTS IN INT TABLE
*/

int		*get_argtable(int argnb, char **av)
{
	int		*a;
	char	**atab;
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	a = ft_init_int(argnb);
	while (av[i] && a)
	{
		k = 0;
		if (av[i])
			atab = ft_strsplit(av[i], ' ');
		while (atab[k])
		{
			a[j] = ft_atoi(atab[k]);
			k++;
			j++;
		}
		i++;
	}
	ft_tabdel(atab);
	return (a);
}

/*
***		PARSER
*/

int		parser(int ac, char **av, t_env *env)
{
	int		i;

	i = 1;
	env->argnb = 0;
	env->a_nb = 0;
	env->b_nb = 0;
	while (i < ac)
	{
		env->argnb = count_argnb(av[i]) != -1
		? env->argnb + count_argnb(av[i]) : -1;
		if (env->argnb == -1)
			return (-1);
		i++;
	}
	env->a = get_argtable(env->argnb, av);
	if (check_double(env->a, env->argnb) == -1)
	{
		free(env->a);
		return (-1);
	}
	if (env->a)
	{
		env->b = ft_init_int(env->argnb);
		visual(env);
	}
	env->a_nb = env->argnb != -1 ? env->argnb : env->a_nb;
	return (0);
}
