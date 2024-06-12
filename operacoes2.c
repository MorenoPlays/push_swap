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

void	ra(pilha **a)
{
	pilha *aux;
	int	num;
	aux=*a;
	if(aux)
	{
		num=aux->valor;
		inserir_no_fim(&*a, num);
		aux=aux->proximo;
		(*a)=aux;
	}
}

void	rb(pilha **b)
{
	pilha *aux;
	int	num;
	aux=*b;
	if(aux)
	{
		num=aux->valor;
		inserir_no_fim(&*b, num);
		aux=aux->proximo;
		(*b)=aux;
	}
}

void	rr(pilha **a, pilha **b)
{
	ra(&*a);
	rb(&*b);
}