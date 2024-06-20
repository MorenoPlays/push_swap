/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 07:00:30 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 08:20:14 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	vra(int maior_valor, t_pilha **a)
{
	t_pilha		*aux;
	int			posicao;

	aux = *a;
	posicao = 1;
	while (aux != NULL)
	{
		if (aux->valor == maior_valor)
		{
			break ;
		}
		posicao++;
		aux = aux->proximo;
	}
	if (posicao == 1)
	{
		ra(&*a);
	}	
}

int	reverse_number(char **str)
{
	int	i;
	int	j;
	int	v;

	v = 1;
	i = 0;
	while (str[i] != (void *)0)
	{
		j = i + 1;
		while (str[j] != (void *)0)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
				v = 0;
			j++;
		}
		i++;
	}
	return (v);
}

int	verificador(char **str, int i)
{
	int		a;
	int		v;

	a = 0;
	v = 1;
	while (str[i] != (void *)0)
	{
		a = 0;
		while (str[i][a] != '\0')
		{
			if (!((str[i][a] <= '9' && str[i][a] >= '0') || (str[i][a] == '-')))
				v = 0;
			a++;
		}
		i++;
	}
	i = 1;
	v = reverse_number(str);
	return (v);
}

int	verificador2(char *str, int a)
{
	int	v;
	int	j;

	a = 0;
	v = 1;
	while (str[a] != '\0')
	{
		if (!((str[a] <= '9' && str[a] >= '0')
				|| ((str[a] == '-') || (str[a] == ' '))))
			v = 0;
		a++;
	}
	a = 0;
	while (str[a] != '\0')
	{
		j = a + 1;
		while (str[j] != '\0')
		{
			if (str[a] == str[j] && str[j] != ' ')
				v = 0;
			j++;
		}
		a++;
	}
	return (v);
}

void	parametro1(t_pilha *a, t_pilha *b, char **argv)
{
	int	valor;
	int	i;
	int	index;
	int	*vi;

	i = 0;
	index = 0;
	while (argv[1][i] != '\0')
	{
		if (argv[1][i] != ' ')
		{
			vi = &i;
			index += insercao2(&a, &b, argv, vi);
		}
		if (argv[1][i] != '\0')
			i++;
	}
	push_swap(&a, &b, index);
}
