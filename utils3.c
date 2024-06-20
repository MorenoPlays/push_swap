/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 18:55:33 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/20 19:22:21 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insercao(t_pilha *a, t_pilha *b, char **argv)
{
	int	i;
	int	valor;
	int	index;

	index = 0;
	i = 1;
	while (argv[i] != (void *)0)
	{
		valor = ft_atoi(argv[i]);
		index += inserir_no_fim(&a, valor);
		i++;
	}
	push_swap(&a, &b, index);
}

int	insercao2(t_pilha **a, t_pilha **b, char **argv, int *vi)
{
	int	valor;
	int	index;
	int	i;

	i = *vi;
	index = 0;
	if (argv[1][i + 1] != ' ')
	{
		valor = 0;
		while (argv[1][i] >= '0' && argv[1][i] <= '9'
				&& argv[1][i] != ' ')
		{
			valor = valor * 10 + (argv[1][i] - '0');
			i++;
		}
		index += inserir_no_fim(&*a, valor);
	}
	else
	{
		valor = argv[1][i] - '0';
		index += inserir_no_fim(&*a, valor);
	}
	*vi = i;
	return (index);
}
