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

static t_pilha	*get_next_min(t_pilha **stack)
{
	t_pilha	*head;
	t_pilha	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->valor < min->valor))
			{
				min = head;
				has_min = 1;
			}
			head = head->proximo;
		}
	}
	return (min);
}

void	indexar(t_pilha **stack)
{
	t_pilha	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

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
		inserir_inicio(&*a, num, num);
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
		inserir_inicio(&*b, num, num);
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
