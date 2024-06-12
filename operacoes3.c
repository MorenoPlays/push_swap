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

void	rra(pilha **a)
{
	pilha *aux;
	pilha *anterior=NULL;

	int	num;
	aux=*a;
	if(aux->proximo)
	{
		while(aux->proximo)
        {
			anterior=aux;
            aux=aux->proximo;
        }
        num = aux->valor;
		inserir_inicio(&*a, num);
        anterior->proximo=NULL;
	}
}

void	rrb(pilha **b)
{
	pilha *aux;
	int	num;
	aux=*b;
	if(aux)
	{
		while(aux->proximo->proximo)
        {
            aux=aux->proximo;
        }
        num = aux->proximo->valor;
		inserir_inicio(&*b, num);
        aux->proximo = NULL;
		
	}
}

void	rrr(pilha **a, pilha **b)
{
	rra(&*a);
	rrb(&*b);
}