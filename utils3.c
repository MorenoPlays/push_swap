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

int	insercao2(t_pilha **a, char **argv, int *vi)
{
	int	valor;
	int	index;
	int	i;
	int	p;

	i = *vi;
	index = 0;
	if (argv[1][i + 1] != ' ')
	{
		valor = 0;
		if (argv[1][i++] == '-')
			p = -1;
		else
			p = 1;
		while (argv[1][i] >= '0' && argv[1][i] <= '9'
				&& argv[1][i] != ' ')
			valor = valor * 10 + (argv[1][i++] - '0');
		index += inserir_no_fim(&*a, (valor * p));
	}
	else
		index += inserir_no_fim(&*a, (argv[1][i] - '0'));
	*vi = i;
	return (index);
}

int	number_replace(char *str, int v)
{
	int	i;
	int	valor;
	int	anterior;
	int	j;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
	{
		valor = 0;
		while (str[i] != ' ' && str[i] != '\0')
			valor = valor * 10 + (str[i++] - '0');
		j = i + 1;
		anterior = valor;
		while (str[j] != '\0' && str[j - 1] != '\0')
		{
			valor = 0;
			while (str[j] != ' ' && str[j] != '\0')
				valor = valor * 10 + (str[j++] - '0');
			if (anterior == valor)
				v = 0;
			j++;
		}
	}
	return (v);
}

int	quatia(t_pilha **a)
{
	int			num;
	t_pilha		*aux;

	aux = *a;
	if (aux->proximo)
	{
		while (aux->proximo)
		{
			aux = aux->proximo;
			num++;
		}
	}
	return (num);
}
