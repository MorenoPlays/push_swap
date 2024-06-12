/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:00:30 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 08:20:14 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void vra(int maior_valor,pilha **a)
{
	pilha *aux;
	int posicao;
	aux=*a;
	
	
	posicao=1;
	while (aux != NULL) {
        if (aux->valor == maior_valor) {
			break ;
        }
        posicao++;
		aux = aux->proximo;
    }
	if(posicao == 1)
    {
        ra(&*a);
    }
		
}