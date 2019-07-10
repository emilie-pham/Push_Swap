/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 11:45:06 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 11:55:25 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	operation(t_env *env, char *operation)
{
	char	*tmp;

	tmp = ft_strjoin(env->operations, operation);
	free(env->operations);
	env->operations = tmp;
}

void	delete(t_env *env, char *operations)
{
	char	*tmp;
	int		index;

	while (ft_strstr(env->operations, operations) != NULL)
	{
		index = ft_strstr(env->operations, operations) - env->operations;
		tmp = ft_strnew(ft_strlen(env->operations) - ft_strlen(operations));
		tmp = ft_strncpy(tmp, env->operations, (size_t)index);
		tmp = ft_strcat(tmp, env->operations + index + ft_strlen(operations));
		free(env->operations);
		env->operations = tmp;
	}
}

void	delete_operations(t_env *env)
{
	delete(env, "\npa\npb");
	delete(env, "\npb\npa");
	delete(env, "\nra\nrra");
	delete(env, "\nrb\nrrb");
	delete(env, "\nrra\nra");
	delete(env, "\nrrb\nrb");
	delete(env, "\nsa\nsa");
	delete(env, "\nsb\nsb");
}

void	replace(t_env *env, char *long_op, char *short_op)
{
	char	*tmp;
	int		index;

	while (ft_strstr(env->operations, long_op) != NULL)
	{
		index = ft_strstr(env->operations, long_op) - env->operations;
		tmp = ft_strnew(ft_strlen(env->operations) - ft_strlen(long_op)
			+ ft_strlen(short_op));
		tmp = ft_strncpy(tmp, env->operations, (size_t)index);
		tmp = ft_strcat(tmp, short_op);
		tmp = ft_strcat(tmp, env->operations + index + ft_strlen(long_op));
		free(env->operations);
		env->operations = tmp;
	}
}

void	optimize(t_env *env)
{
	while (ft_strstr(env->operations, "\npa\npb") != NULL
		|| ft_strstr(env->operations, "\npb\npa") != NULL
		|| ft_strstr(env->operations, "\nra\nrra") != NULL
		|| ft_strstr(env->operations, "\nrb\nrrb") != NULL
		|| ft_strstr(env->operations, "\nrra\nra") != NULL
		|| ft_strstr(env->operations, "\nrrb\nrb") != NULL
		|| ft_strstr(env->operations, "\nsa\nsa") != NULL
		|| ft_strstr(env->operations, "\nsb\nsb") != NULL)
		delete_operations(env);
	replace(env, "\nsa\nsb\n", "\nss\n");
	replace(env, "\nsb\nsa\n", "\nss\n");
	replace(env, "\nrra\nrrb\n", "\nrrr\n");
	replace(env, "\nrrb\nrra\n", "\nrrr\n");
	replace(env, "\nra\nrb\n", "\nrr\n");
	replace(env, "\nrb\nra\n", "\nrr\n");
}
