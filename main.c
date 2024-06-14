/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:31 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 19:12:30 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void printList_a(pilha* head) {
    pilha* temp = head;
    while (temp != NULL) {
        printf("a:%d ->", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}
void printList_b(pilha* head) {
    pilha* temp = head;
    while (temp != NULL) {
        printf("b:%d -> ", temp->valor);
        temp = temp->proximo;
    }
    printf("NULL\n");
}

void	sorte(pilha **a, pilha **b, int index)
{
	pilha *aux;
	pilha *aux1;
	int	posicao;
	int	posicao1;
	int menor;

	aux=*a;
	aux1=*b;
	posicao=1;
	posicao1=1;
	menor=menor_valor(aux);
	while(aux)
	{
		if(aux->proximo)
		{
			if(aux->valor > aux->proximo->valor && posicao==1)
			{
				sa(&*a);
				aux=*a;
			}
			else if(aux->valor > aux->proximo->valor && posicao!=1)
			{
				pa(&*a,&*b);
				aux=*a;
				aux1=*b;
				index--;
				posicao=1;
			}
			else
			{
					aux=aux->proximo;
					posicao++;
			}
			
			
		}
		else
		{
			aux=aux->proximo;
		}
		
		if(aux1)
		{
			if(aux1->proximo)
			{
				if(aux1->valor < aux1->proximo->valor && posicao1==1)
				{
					sb(&*b);
					aux1=*b;
				}
				else if(aux1->valor > aux1->proximo->valor)
				{
					pb(&*a,&*b);
					aux=*a;
					aux1=*b;
					posicao1=1;
					posicao=1;
				}
				else
				{
					aux1=aux1->proximo;
					posicao1++;
				}
			}
		}
	}
	pb(&*a,&*b);
	sa(&*a);

}

void	push_swap(pilha **a, pilha **b, int index)
{
	sorte(&*a,&*b,index);
}

int main(int argc, char *argv[])
{
	pilha	*a;
	pilha	*b;
	int index;
	index=0;
	if(argc > 1)
	{
		int	i;
		int	valor;

		i = 1;
		a = NULL;
		b = NULL;
		while(argv[i] != (void *)0)
		{	valor = atoi(argv[i]);
			index+=inserir_no_fim(&a, valor);
			i++;
		}
	}
	push_swap(&a,&b,index);
	printList_a(a);
	printList_b(b);
	return (0);
}