/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:59:31 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 20:51:12 by eda-mata         ###   ########.fr       */
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

int	ordenado(pilha **a){
	pilha *aux;
	aux=*a;
	while(aux)
	{
		if(aux->proximo)
		{
			if(aux->valor < aux->proximo->valor)
			{
				aux=aux->proximo;
			}
			else
			{
				return (0);
			}
		}
		else
			aux=aux->proximo;
		
	}
	return (1);
}

int	ordenar_a(pilha **a, pilha **b)
{
	pilha *aux;
	int	posicao;
	int index;
	
	aux=*a;
	posicao=1;
	index=0;
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
				posicao=1;
				index++;
			}
			else
			{
				aux=aux->proximo;
				posicao++;
			}
		}
		else
			aux=aux->proximo;
	}
	return (index);
}

int	ordenar_b(pilha **a, pilha **b)
{
	pilha *aux;
	int	posicao;
	int index;
	
	aux=*b;
	posicao=1;
	index=0;
	while(aux)
	{
		if(aux->proximo)
		{
			if(aux->valor < aux->proximo->valor && posicao==1)
			{
				sb(&*b);
				aux=*b;
			}
			else if(aux->valor > aux->proximo->valor)
			{
				pb(&*a,&*b);
				aux=*b;
				posicao=1;
				index++;
			}
			else
			{
				aux=aux->proximo;
				posicao++;
			}
		}
		else
			aux=aux->proximo;
	}
	return (index);
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
	while(ordenado(&*a)==0)
	{
		printList_a(*a);
		printList_b(*b);
	
		vrra(menor,index,&*a);
		index-=ordenar_a(&*a,&*b);
		index+=ordenar_b(&*a,&*b);
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
		push_swap(&a,&b,index);
		printList_a(a);
		printList_b(b);
	}
	else
	{
		printf("sem argumentos\n");
	}
	return (0);
}
