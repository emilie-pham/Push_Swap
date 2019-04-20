/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:31:08 by epham             #+#    #+#             */
/*   Updated: 2019/04/20 13:27:33 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
***		ft_putchar('\n');
***		ft_printint(env->a, env->argnb);
***		ft_putchar('\n');
***		ft_printint(env->b, env->argnb);
***		ft_putstr("\n\n");
*/

void	visual(t_env *env)
{
	int i;
	int j;

	i = -1;
	ft_putendl(" ____________________ ____________________ ");
	ft_putendl("|                    |                    |");
	ft_putendl("|         a          |         b          |");
	ft_putendl("|____________________|____________________|");
	ft_putendl("|                    |                    |");
	while (++i < env->argnb)
	{
		j = 11 - nblen(env->a[i]);
		ft_putstr("|         ");
		ft_putnbr(env->a[i]);
		while (j--)
			ft_putchar(' ');
		ft_putstr("|         ");
		ft_putnbr(env->b[i]);
		j = 11 - nblen(env->b[i]);
		while (j--)
			ft_putchar(' ');
		ft_putendl("|");
	}
	ft_putendl("|____________________|____________________|");
}

void	swap_operations(t_env *env, char *instruction)
{
	int swap;

	env->top_a = env->argnb - env->a_nb;
	env->top_b = env->argnb - env->b_nb;
	swap = 0;
	if (ft_strcmp(instruction, "sa") == 0)
	{
		swap = env->a[env->top_a];
		env->a[env->top_a] = env->a[env->top_a + 1];
		env->a[env->top_a + 1] = swap;
	}
	else if (ft_strcmp(instruction, "sb") == 0)
	{
		swap = env->b[env->top_b];
		env->b[env->top_b] = env->b[env->top_b + 1];
		env->b[env->top_b + 1] = swap;
	}
	else if (ft_strcmp(instruction, "ss") == 0)
	{
		swap_operations(env, "sa\n");
		swap_operations(env, "sb\n");
	}
}

void	push_operations(t_env *env, char *instruction)
{
	env->top_a = env->argnb - env->a_nb;
	env->top_b = env->argnb - env->b_nb;
	if (ft_strcmp(instruction, "pa") == 0 && (env->b_nb > 0))
	{
		env->a[env->top_a - 1] = env->b[env->top_b];
		env->b[env->top_b] = 0;
		env->b_nb--;
		env->a_nb++;
	}
	else if (ft_strcmp(instruction, "pb") == 0 && (env->a_nb > 0))
	{
		env->b[env->top_b - 1] = env->a[env->top_a];
		env->a[env->top_a] = 0;
		env->a_nb--;
		env->b_nb++;
	}
}

void	rotate_operations(t_env *env, char *instruction)
{
	int first;

	env->top_a = env->argnb - env->a_nb;
	env->top_b = env->argnb - env->b_nb;
	if (ft_strcmp(instruction, "ra") == 0 && env->a_nb > 0)
	{
		first = env->a[env->top_a];
		while (++(env->top_a) < env->argnb)
			env->a[env->top_a - 1] = env->a[env->top_a];
		env->a[env->argnb - 1] = first;
	}
	else if (ft_strcmp(instruction, "rb") == 0 && env->b_nb > 0)
	{
		first = env->b[env->top_b];
		while (++(env->top_b) < env->argnb)
			env->b[env->top_b - 1] = env->b[env->top_b];
		env->b[env->argnb - 1] = first;
	}
	else if (ft_strcmp(instruction, "rr") == 0)
	{
		rotate_operations(env, "ra\n");
		rotate_operations(env, "rb\n");
	}
}

void	reverse_operations(t_env *env, char *instruction)
{
	int i;
	int last;

	env->top_a = env->argnb - env->a_nb;
	env->top_b = env->argnb - env->b_nb;
	i = env->argnb - 1;
	if (ft_strcmp(instruction, "rra") == 0 && env->a_nb > 0)
	{
		last = env->a[env->argnb - 1];
		while (--i + 1 > env->top_a)
			env->a[i + 1] = env->a[i];
		env->a[env->top_a] = last;
	}
	else if (ft_strcmp(instruction, "rrb") == 0 && env->b_nb > 0)
	{
		last = env->b[env->argnb - 1];
		while (--i + 1 > env->top_b)
			env->b[i + 1] = env->b[i];
		env->b[env->top_b] = last;
	}
	else if (ft_strcmp(instruction, "rrr") == 0)
	{
		reverse_operations(env, "rra\n");
		reverse_operations(env, "rrb\n");
	}
}
