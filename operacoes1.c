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
#include <stdlib.h>
#include <stdio.h>

void sa(pilha **a)
{
	pilha *aux;
	int	num;
	aux = *a;
	if(aux && aux->proximo)
	{
		if (aux->valor > aux->proximo->valor)
		{
			num = aux->valor;
			aux->valor=aux->proximo->valor;
			aux->proximo->valor=num;
		}
	}
	
}

void sb(pilha **b)
{
	pilha *aux;
	int	num;
	aux = *b;
	if(aux && aux->proximo)
	{
		num = aux->valor;
		aux->valor=aux->proximo->valor;
		aux->proximo->valor=num;
	}
	
}

void ss(pilha *a, pilha *b)
{
    sa(&a);
    sb(&b);
}

void	pa(pilha **a, pilha **b)
{
	pilha *aux;
	int	num;
	aux = *a;
	if(aux && aux->proximo)
	{
		num = aux->valor;
		inserir_inicio(&*b, num);
		aux = aux->proximo;
		(*a) = aux;
	}
	
	
}

void	pb(pilha **a, pilha **b)
{
	pilha *aux;
	int	num;
	aux = *b;
	if(aux)
	{
		num = aux->valor;
		inserir_inicio(&*a, num);
		aux = aux->proximo;
		(*b) = aux;
	}
	
	
}
