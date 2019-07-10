/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:31:39 by epham             #+#    #+#             */
/*   Updated: 2019/07/08 12:08:36 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <unistd.h>

typedef struct	s_env
{
	int			argnb;
	int			min;
	int			max;
	int			*a;
	int			*b;
	int			a_nb;
	int			b_nb;
	int			top_a;
	int			top_b;
	int			pibon_a;
	int			*pibons_b;
	int			current_pibon_b;
	int			pushed_pibon;
	int			sz_pib_b;
	int			*sorted;
	int			debug;
	char		*operations;
}				t_env;

/*
***				ALGORITHMS
*/

int				is_few_numbers(t_env *env);
void			sort_few_numbers(t_env *env);
int				is_almost_sorted(t_env *env);
void			sort_almost_sorted(t_env *env);

/*
***				CHECK_ERROR
*/

int				nblen(int n);
int				ft_lennb(char *nb);
int				check_atoi(char *nb);
int				check_double(int *argtab, int argnb);
int				error(t_env *env, int tmp);

/*
***				OPERATIONS
*/

void			swap_operations(t_env *env, char *instruction);
void			push_operations(t_env *env, char *instruction);
void			rotate_operations(t_env *env, char *instruction);
void			reverse_operations(t_env *env, char *instruction);

/*
***				OPTIMIZATION
*/

void			operation(t_env *env, char *operation);
void			optimize(t_env *env);

/*
***				PARSER
*/

int				*bubble_sort(int *stack, int stacklen);
int				count_argnb(char *av);
int				*get_argtable(int argnb, char **av, int i, int j);
void			initialize(t_env *env);
int				parser(int ac, char **av, t_env *env);

/*
***				PIBON OPERATIONS A
*/

int				pibon_index(t_env *env, char stack);
int				pivot(t_env *env, char stackletter, int first, int last);
int				pibon_a(t_env *env);
int				index_int(int *tab, int start, int end, int needle);

/*
***				PIBON OPERATIONS B
*/

int				checkmore(int *tab, int first, int last, int pibon);
void			add_pibon(t_env *env, int pibon);
void			remove_pibon(t_env *env);
void			rotate_pibon(t_env *env);

/*
***				PUSH BACK AND PUSH TO
*/

int				push_back(t_env *env);

int				push_to(t_env *env);

/*
***				SORT A AND B
*/

void			sort2_a(t_env *env);
void			sort3_a(t_env *env);
void			less_than_four_numbers_at_stack_a(t_env *env);

void			sort2_b(t_env *env);
void			sort3_b(t_env *env);
void			less_than_four_numbers_at_stack_b(t_env *env);

/*
***				SORT RANDOM
*/

void			last_check(t_env *env);
void			sort_from_a_to_b_first_push(t_env *env, int pibon);
void			sort_first_push(t_env *env, int pibon);
void			sort_random(t_env *env);

/*
*** 			UTILS
*/

int				top(t_env *env, char stack);
int				*copy_inttab(int *stack, int *copy, int start, int finish);
int				check_order_stack(t_env *env);
void			check_top_both_stacks(t_env *env);
void			ft_free(t_env *env);

/*
***				UTILS PUSH BACK
*/

void			push_back_in_order(t_env *env);
int				calculate_the_pibon_stack_b(t_env *env);
void			b_to_a(t_env *env, int current_pibon, int *count_rotate);
void			rotate_or_reverse(t_env *env, int count_rotate);
void			sort_b_to_a(t_env *env, int current_pibon);

/*
***				UTILS PUSH TO
*/
int				checkless(int *tab, int top, int tab_len, int pibon);
void			less_or_equal_than_pibon(t_env *env, int pibon);
void			a_to_b(t_env *env);
int				sort_a_to_b(t_env *env, int pibon, int count_rotations);
void			rotate_pibon_min(t_env *env, int pibon, int count);

/*
***				VISUAL
*/

void			visual(t_env *env);
int				debug(t_env *env, char **av, int ac);

#endif
