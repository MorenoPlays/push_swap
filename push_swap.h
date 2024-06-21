/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:53:57 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 11:10:09 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

typedef struct lista
{
	struct lista	*proximo;
	int				valor;
}					t_pilha;

void	inserir_inicio(t_pilha **lista, int valor);
int		inserir_no_fim(t_pilha **lista, int valor);
void	sa(t_pilha **a);
void	sb(t_pilha **b);
void	ss(t_pilha *a, t_pilha *b);
void	pa(t_pilha **a, t_pilha **b);
void	pb(t_pilha **a, t_pilha **b);
void	ra(t_pilha **a);
void	rb(t_pilha **b);
void	rr(t_pilha **a, t_pilha **b);
void	rra(t_pilha **a);
void	rrb(t_pilha **b);
void	rrr(t_pilha **a, t_pilha **b);
void	vrra(int min_valor, int index, t_pilha **a);
int		menor_valor(t_pilha *head);
int		maior_valor(t_pilha *head);
int		verificador(char **str, int i);
int		verificador2(char *str, int a);
void	parametro1(t_pilha *a, t_pilha *b, char **argv);
void	vra(int maior_valor, t_pilha **a);
void	push_swap(t_pilha **a, t_pilha **b, int index);
void	insercao(t_pilha *a, t_pilha *b, char **argv);
int		insercao2(t_pilha **a, char **argv, int *vi);
int		number_replace(char *str, int v);
int		quatia(t_pilha **a);
#endif
