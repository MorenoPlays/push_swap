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
	if (aux && aux->proximo)
	{
		while (aux->proximo)
		{
			anterior = aux;
			aux = aux->proximo;
		}
		num = aux->valor;
		inserir_inicio(&*a, num);
		anterior->proximo = NULL;
		free(aux);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_pilha **b)
{
	int			num;
	t_pilha		*aux;
	t_pilha		*anterior;

	aux = *b;
	anterior = NULL;
	if (aux && aux->proximo)
	{
		while (aux->proximo)
		{
			anterior = aux;
			aux = aux->proximo;
		}
		num = aux->valor;
		inserir_inicio(&*b, num);
		anterior->proximo = NULL;
		free(aux);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_pilha **a, t_pilha **b)
{
	rra1(&*a);
	rrb1(&*b);
	write(1, "rrr\n", 4);
}
