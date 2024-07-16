/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:09:29 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/15 12:29:19 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_int_tab(int *tab, int size)
{
	int	var1;
	int	var2;
	int	var3;

	var1 = 1;
	while (var1 < size)
	{
		var2 = 0;
		while (var2 < (size - 1))
		{
			if (tab[var2] > tab[var2 + 1])
			{
				var3 = tab[var2];
				tab[var2] = tab[var2 + 1];
				tab[var2 + 1] = var3;
			}
			var2++;
		}
		var1++;
	}
}

int	find(t_pilha **a, int valor)
{
	int		i;
	int		j;
	t_pilha	*aux;

	i = quatia(a) / 2;
	j = 0;
	aux = *a;
	while (aux)
	{
		if (aux->valor == valor)
			break ;
		j++;
		aux = aux->proximo;
	}
	if (j > i)
		return (1);
	return (0);
}

void	radix1(t_pilha **a, t_pilha **b, int valor)
{
	t_pilha		*aux;

	aux = *a;
	while (aux->valor != valor)
	{
		rra(&*a);
		aux = *a;
	}
	pb(&*a, &*b);
}

void	radix2(t_pilha **a, t_pilha **b, int valor)
{
	t_pilha	*aux;

	aux = *a;
	while (aux->valor != valor)
	{
		ra(&*a);
		aux = *a;
	}
	pb(&*a, &*b);
}

void	radix(t_pilha **a, t_pilha **b)
{
	int			*lista;
	int			i;

	lista = push(&*a);
	ft_sort_int_tab(lista, quatia(a));
	i = 0;
	while (lista[i] != '\0')
	{	
		if (lista[i] == (*a)->valor)
		{
			pb(&*a, &*b);
			i++;
		}
		else if (find(&*a, lista[i]) == 1)
			radix1(&*a, &*b, lista[i++]);
		else
			radix2(&*a, &*b, lista[i++]);
	}
	while ((*b))
		pa(&*a, &*b);
	free(lista);
}
