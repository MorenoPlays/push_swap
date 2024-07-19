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

void	inserir_inicio(t_liste **lista, int valor)
{
	t_liste		*novo;

	novo = malloc(sizeof(t_liste));
	if (novo)
	{
		novo->valor = valor;
		novo->index = -1;
		novo->next = *lista;
		*lista = novo;
	}
}

int	inserir_no_fim(t_liste **lista, int valor)
{
	int			index;
	t_liste		*novo;
	t_liste		*aux;

	index = 0;
	novo = malloc(sizeof(t_liste));
	if (novo)
	{
		novo->valor = valor;
		novo->index = -1;
		novo->next = NULL;
		if (*lista == NULL)
			*lista = novo;
		else
		{
			aux = *lista;
			while (aux->next != NULL)
				aux = aux->next;
			aux->next = novo;
		}
		index++;
	}
	else
		free(novo);
	return (index);
}

int	menor_valor(t_liste *head)
{
	int			min;
	t_liste		*temp;

	min = INT_MAX;
	temp = head;
	while (temp != NULL)
	{
		if (temp->valor < min)
		{
			min = temp->valor;
		}
		temp = temp->next;
	}
	return (min);
}

int	maior_valor(t_liste *head)
{
	int			max;
	t_liste		*temp;

	max = INT_MIN;
	temp = head;
	while (temp != NULL)
	{
		if (temp->valor > max)
		{
			max = temp->valor;
		}
		temp = temp->next;
	}
	return (max);
}

void	vrra(int min_valor, t_liste **a)
{
	t_liste		*aux;
	int			valor;

	valor = 0;
	aux = *a;
	while (aux)
	{
		valor = aux->valor;
		aux = aux->next;
	}
	if (valor == min_valor)
	{
		rra(&*a);
	}
}
