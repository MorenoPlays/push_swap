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

int	ordenado(t_liste **a)
{
	t_liste		*aux;

	aux = *a;
	while (aux)
	{
		if (aux->next)
		{
			if (aux->valor < aux->next->valor)
			{
				aux = aux->next;
			}
			else
			{
				return (0);
			}
		}
		else
			aux = aux->next;
	}
	return (1);
}

int	ordenar_a(t_liste **a, t_liste **b, int index, int posicao)
{
	t_liste		*aux;

	aux = *a;
	while (aux && aux->next)
	{
		if ((aux->valor > aux->next->valor) && posicao == 1)
		{
			sa(&*a);
			aux = *a;
		}
		else if ((aux->valor > aux->next->valor) && posicao != 1)
		{
			pb(&*a, &*b);
			ordenar_ab(&*a, &*b);
			aux = *a;
			posicao = 1;
			index++;
		}
		else
		{
			aux = aux->next;
			posicao++;
		}
	}
	return (index);
}

int	ordenar_b(t_liste **a, t_liste **b, int index, int posicao)
{
	t_liste		*aux;

	aux = *b;
	while (aux && aux->next)
	{
		if (aux->valor < aux->next->valor && posicao == 1)
		{
			sb(&*b);
			aux = *b;
		}
		else if (aux->valor > aux->next->valor)
		{
			pa(&*a, &*b);
			ordenar_ab(&*a, &*b);
			aux = *b;
			posicao = 1;
			index++;
		}
		else
		{
			aux = aux->next;
			posicao++;
		}
	}
	return (index);
}

void	push_swap(t_liste **a, t_liste **b, int index)
{
	if (quatia(&*a) < 6)
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
	else
		radix(&*a, &*b);
}

int	main(int argc, char *argv[])
{
	t_liste		*a;
	t_liste		*b;

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
		exit(1);
	}
	return (0);
}
