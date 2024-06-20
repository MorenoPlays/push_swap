/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:05:29 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 10:00:46 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_pilha **a)
{
	int			num;
	t_pilha		*aux;
	t_pilha		*anterior;

	aux = *a;
	anterior = NULL;
	if (aux->proximo)
	{
		while (aux->proximo)
		{
			anterior = aux;
			aux = aux->proximo;
		}
		num = aux->valor;
		inserir_inicio(&*a, num);
		anterior->proximo = NULL;
		write(1, "rra\n", 4);
	}
}

void	rrb(t_pilha **b)
{
	t_pilha		*aux;
	int			num;

	aux = *b;
	if (aux)
	{
		while (aux->proximo->proximo)
		{
			aux = aux->proximo;
		}
		num = aux->proximo->valor;
		inserir_inicio(&*b, num);
		aux->proximo = NULL;
		write(1, "rrb\n", 3);
	}
}

void	rrr(t_pilha **a, t_pilha **b)
{
	rra(&*a);
	rrb(&*b);
}
