/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:39:07 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/20 11:33:53 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	inserir_inicio(t_pilha **lista, int valor, int mod)
{
	t_pilha		*novo;

	novo = malloc(sizeof(t_pilha));
	if (novo)
	{
		novo->valor = valor;
		novo->mod = mod;
		novo->proximo = *lista;
		*lista = novo;
	}
}

int	inserir_no_fim(t_pilha **lista, int valor)
{
	int			index;
	t_pilha		*novo;
	t_pilha		*aux;

	index = 0;
	novo = malloc(sizeof(t_pilha));
	if (novo)
	{
		novo->valor = valor;
		novo->proximo = NULL;
		if (*lista == NULL)
			*lista = novo;
		else
		{
			aux = *lista;
			while (aux->proximo != NULL)
				aux = aux->proximo;
			aux->proximo = novo;
		}
		index++;
	}
	else
		free(novo);
	return (index);
}

int	menor_valor(t_pilha *head)
{
	int			min;
	t_pilha		*temp;

	min = INT_MAX;
	temp = head;
	while (temp != NULL)
	{
		if (temp->valor < min)
		{
			min = temp->valor;
		}
		temp = temp->proximo;
	}
	return (min);
}

int	maior_valor(t_pilha *head)
{
	int			max;
	t_pilha		*temp;

	max = INT_MIN;
	temp = head;
	while (temp != NULL)
	{
		if (temp->valor > max)
		{
			max = temp->valor;
		}
		temp = temp->proximo;
	}
	return (max);
}

void	vrra(int min_valor, t_pilha **a)
{
	t_pilha		*aux;
	int			valor;

	valor = 0;
	aux = *a;
	while (aux)
	{
		valor = aux->valor;
		aux = aux->proximo;
	}
	if (valor == min_valor)
	{
		rra(&*a);
	}
}
