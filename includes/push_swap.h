/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:31:39 by epham             #+#    #+#             */
/*   Updated: 2019/04/19 16:56:10 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct	s_env
{
	int			argnb;
	int			*a;
	int			*b;
	int			a_nb;
	int			b_nb;
	int			top_a;
	int			top_b;
}				t_env;

/*
***		PARSING
*/

int		*get_argtable(int argnb, char **av);
int		parser(int ac, char **av, t_env *env);

/*
***		ERROR CHECKER
*/

int 	error(t_env *env);
int		nblen(int n);
int		count_argnb(char *av);
int		check_atoi(char *nb);
int		check_double(int *argtab, int argnb);

/*
***		OPERATIONS
*/

void	swap_operations(t_env *env, char *instruction);
void	push_operations(t_env *env, char *instruction);
void	rotate_operations(t_env *env, char *instruction);
void	reverse_operations(t_env *env, char *instruction);

/*
***		VISUAL
*/

void	visual(t_env *env);

#endif