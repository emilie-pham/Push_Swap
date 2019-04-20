/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:28:03 by epham             #+#    #+#             */
/*   Updated: 2019/04/20 13:22:00 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		nblen(int n)
{
	int count;

	count = 0;
	if (n < 0 || n == 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

/*
***		CHECK ATOI OUTPUT (limits of int, non digit, ...)
*/

int		check_atoi(char *nb)
{
	int n;

	n = ft_atoi(nb);
	if ((n == 0 && nb[0] != '0') || (nb[0] != '-' && n < 0))
		return (-1);
	if (ft_strlen(nb) != nblen(n))
	{
		if ((ft_strlen(nb) == nblen(n) + 1
			&& (nb[0] == '+' || nb[0] == '0'))
			|| (ft_strlen(nb) == nblen(n) + 2
			&& nb[0] == '+' && nb[1] == '0'))
			return (0);
		else
			return (-1);
	}
	return (0);
}

/*
***		CHECK LES DOUBLONS
*/

int		check_double(int *argtab, int argnb)
{
	int i;
	int j;

	i = 0;
	while (i < argnb)
	{
		j = 0;
		while (j < argnb)
		{
			if (argtab[i] == argtab[j] && i != j)
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}

int		error(t_env *env)
{
	if (env->a)
		free(env->a);
	if (env->b)
		free(env->b);
	free(env);
	write(2, "Error\n", 6);
	return (-1);
}
