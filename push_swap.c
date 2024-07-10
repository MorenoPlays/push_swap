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

int	ordenado(t_pilha **a)
{
	t_pilha		*aux;

	aux = *a;
	while (aux)
	{
		if (aux->proximo)
		{
			if (aux->valor < aux->proximo->valor)
			{
				aux = aux->proximo;
			}
			else
			{
				return (0);
			}
		}
		else
			aux = aux->proximo;
	}
	return (1);
}

int	ordenar_a(t_pilha **a, t_pilha **b, int index, int posicao)
{
	t_pilha		*aux;

	aux = *a;
	while (aux && aux->proximo)
	{
		if ((aux->valor > aux->proximo->valor) && posicao == 1)
		{
			ordenar_ab(&*a, &*b);
			sa(&*a);
			aux = *a;
		}
		else if ((aux->valor > aux->proximo->valor) && posicao != 1)
		{
			pb(&*a, &*b);
			aux = *a;
			posicao = 1;
			index++;
		}
		else
		{
			aux = aux->proximo;
			posicao++;
		}
	}
	return (index);
}

int	ordenar_b(t_pilha **a, t_pilha **b, int index, int posicao)
{
	t_pilha		*aux;

	aux = *b;
	while (aux && aux->proximo)
	{
		if (aux->valor < aux->proximo->valor && posicao == 1)
		{
			ordenar_ab(&*a, &*b);
			sb(&*b);
			aux = *b;
		}
		else if (aux->valor > aux->proximo->valor)
		{
			pa(&*a, &*b);
			aux = *b;
			posicao = 1;
			index++;
		}
		else
		{
			aux = aux->proximo;
			posicao++;
		}
	}
	return (index);
}

void	push_swap(t_pilha **a, t_pilha **b, int index)
{
	while (ordenado(&*a) == 0)
	{
		ordenar_ab(&*a, &*b);
		index -= ordenar_a(&*a, &*b, 0, 1);
		index += ordenar_b(&*a, &*b, 0, 1);
	}
	pa(&*a, &*b);
	sa(&*a);
	if (ordenado(&*a) == 0)
		push_swap(&*a, &*b, index);
}

int	main(int argc, char *argv[])
{
	t_pilha		*a;
	t_pilha		*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc > 2 && verificador(argv, 1) == 1 && argv[1][0])
		insercao(a, b, argv);
	else if (argc == 2 && verificador2(argv[1], 0) == 1
		&& number_replace(argv[1], 1) == 1 && argv[1][0])
		insercao2(a, b, ft_split(argv[1], ' '));
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
