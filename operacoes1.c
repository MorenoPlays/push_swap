/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:40:24 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 20:20:41 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_pilha **a)
{
	t_pilha		*aux;
	int			num;

	aux = *a;
	if (aux && aux->proximo)
	{
		if (aux->valor > aux->proximo->valor)
		{
			num = aux->valor;
			aux->valor = aux->proximo->valor;
			aux->proximo->valor = num;
			write(1, "sa\n", 3);
		}
	}
}

void	sb(t_pilha **b)
{
	t_pilha		*aux;
	int			num;

	aux = *b;
	if (aux && aux->proximo)
	{
		num = aux->valor;
		aux->valor = aux->proximo->valor;
		aux->proximo->valor = num;
		write(1, "sb\n", 3);
	}
}

void	ss(t_pilha **a, t_pilha **b)
{
	t_pilha		*aux;
	int			num;

	aux = *a;
	if (aux && aux->proximo)
	{
		if (aux->valor > aux->proximo->valor)
		{
			num = aux->valor;
			aux->valor = aux->proximo->valor;
			aux->proximo->valor = num;
		}
	}
	aux = *b;
	if (aux && aux->proximo)
	{
		num = aux->valor;
		aux->valor = aux->proximo->valor;
		aux->proximo->valor = num;
	}
	write(1, "ss\n", 3);
}

void	pb(t_pilha **a, t_pilha **b)
{
	t_pilha		*aux;
	t_pilha		*anterior;
	int			num;

	aux = *a;
	if (aux && aux->proximo)
	{
		num = aux->valor;
		anterior = aux;
		inserir_inicio(&*b, num);
		aux = aux->proximo;
		(*a) = aux;
		free(anterior);
		write(1, "pb\n", 3);
	}
}

void	pa(t_pilha **a, t_pilha **b)
{
	t_pilha		*aux;
	t_pilha		*anterior;
	int			num;

	aux = *b;
	if (aux)
	{
		num = aux->valor;
		anterior = aux;
		inserir_inicio(&*a, num);
		aux = aux->proximo;
		(*b) = aux;
		free(anterior);
		write(1, "pa\n", 3);
	}
}
