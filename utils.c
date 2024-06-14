/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:07 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 20:46:52 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inserir_inicio(pilha **lista, int valor)
{
		pilha	*novo;
		novo = malloc(sizeof(pilha));
		if(novo)
		{
			novo->valor = valor;
			novo->proximo = *lista;
			*lista=novo;
		}
		
}

int	inserir_no_fim(pilha **lista, int valor)
{
		pilha	*novo;
		pilha	*aux;
		int	index;

		index=0;
		novo = malloc(sizeof(pilha));
		if(novo)
		{
			novo->valor = valor;
			novo->proximo = NULL;
			if(*lista == NULL)
				*lista=novo;
			else
			{
				aux = *lista;
				while (aux->proximo != NULL)
				{
					aux=aux->proximo;
				}
				aux->proximo=novo;
				
			}
			index++;
		}
		return(index);
}

int menor_valor(pilha *head)
{
	int min;

	min= INT_MAX;
    pilha *temp = head;
    while (temp != NULL) {
        if (temp->valor < min) {
            min = temp->valor;
        }
        temp = temp->proximo;
    }
    return min;
}

int maior_valor(pilha *head)
{
	int max;

	max= INT_MIN;
    pilha *temp = head;
    while (temp != NULL) {
        if (temp->valor > max) {
            max = temp->valor;
        }
        temp = temp->proximo;
    }
    return max;
}

void	vrra(int min_valor,int index, pilha **a)
{
	if(index > 2)
	{
		pilha *aux;
		int posicao;
		aux=*a;
	
	
		posicao=1;
		while (aux != NULL) {
        if (aux->valor == min_valor) {
			break ;
        }
        posicao++;
		aux = aux->proximo;
    	}
		if(posicao ==index)
			rra(&*a);
	}
}
