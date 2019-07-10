/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:28:03 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:43:56 by epham            ###   ########.fr       */
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

int		ft_lennb(char *nb)
{
	int		out;
	int		i;

	i = 0;
	out = 0;
	if (nb[i] == '+' || nb[i] == '-')
		i++;
	while (nb[i] == '0')
		i++;
	while (nb[i])
	{
		i++;
		out++;
	}
	return (out);
}

int		check_atoi(char *nb)
{
	int			i;
	long long	n;
	int			nbr_len;

	i = 0;
	nbr_len = 0;
	if ((nb[i] == '+' || nb[i] == '-') && ft_isdigit(nb[i + 1]) == 1)
		i++;
	while (nb[i] == '0')
		i++;
	while (ft_isdigit(nb[i + nbr_len]) != 0)
		nbr_len++;
	if (ft_isdigit(nb[i + nbr_len]) == 0 && nb[i + nbr_len] != '\0')
		return (-1);
	n = ft_atol(nb);
	if (n < -2147483648 || n > 2147483647 || nbr_len > 10)
		return (-1);
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

/*
***		SORTIE D'ERREUR
*/

int		error(t_env *env, int tmp)
{
	if (tmp == -1)
	{
		free(env->a);
		free(env->b);
	}
	else if (tmp == -3)
		ft_free(env);
	free(env);
	write(2, "Error\n", 6);
	return (-1);
}
