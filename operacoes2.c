/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:20 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 08:29:55 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_pilha **a)
{
	t_pilha		*aux;
	int			num;

	aux = *a;
	if (aux)
	{
		num = aux->valor;
		inserir_no_fim(&*a, num);
		aux = aux->proximo;
		(*a) = aux;
		write(1, "ra\n", 3);
	}
}

void	rb(t_pilha **b)
{
	t_pilha		*aux;
	int			num;

	aux = *b;
	if (aux)
	{
		num = aux->valor;
		inserir_no_fim(&*b, num);
		aux = aux->proximo;
		(*b) = aux;
		write(1, "rb\n", 3);
	}
}

void	rr(t_pilha **a, t_pilha **b)
{
	ra(&*a);
	rb(&*b);
}
