/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:21:36 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/05 11:21:56 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra1(t_pilha **a)
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
	}
}

void	rrb1(t_pilha **b)
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
	}
}

void	vrrr(int menor_de_a, int maior_de_b, t_pilha **a, t_pilha **b)
{
	t_pilha	*aux;
	int		va;
	int		vb;

	va = 0;
	vb = 0;
	aux = *a;
	if (!(*a) || !(*b))
		return ;
	while (aux->proximo)
		aux = aux->proximo;
	if (aux->valor == menor_de_a)
		va = 1;
	aux = *b;
	while (aux->proximo)
		aux = aux->proximo;
	if (aux->valor == maior_de_b)
		vb = 1;
	if (vb == 1 && va == 1)
		rrr(&*a, &*b);
}

void	ft_remove_list(t_pilha **a, t_pilha **b)
{
	t_pilha		*aux;

	aux = *a;
	while (aux)
	{
		*a = aux->proximo;
		free(aux);
		aux = *a;
	}
	aux = *b;
	while (aux)
	{
		*a = aux->proximo;
		free(aux);
		aux = *a;
	}
}
