/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:53:57 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 08:18:19 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
#include<stdlib.h>
#include<stdio.h>
typedef struct lista
{
	int	valor;
	struct lista	*proximo;
}	pilha;

void	inserir_inicio(pilha **lista, int valor);
int	inserir_no_fim(pilha **lista, int valor);
void	sa(pilha **a);
void	sb(pilha **b);
void	ss(pilha *a, pilha *b);
void	pa(pilha **a, pilha **b);
void	pb(pilha **a, pilha **b);
void	ra(pilha **a);
void	rb(pilha **b);
void	rr(pilha **a, pilha **b);
void	rra(pilha **a);
void	rrb(pilha **b);
void	rrr(pilha **a, pilha **b);
void	vrra(int min_valor,int index, pilha **a);
int	menor_valor(pilha *head);
int maior_valor(pilha *head);
void vra(int maior_valor, pilha **a);
# endif
