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
			break ;
		posicao++;
		aux = aux->proximo;
	}
	if (posicao == 1)
		ra(&*a);
}

int	reverse_number(char **str)
{
	int	i;
	int	j;
	int	v;

	v = 1;
	i = 1;
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
	if (!str[1][0] || str[1][0] == ' ')
		return (0);
	while (str[i] != (void *)0)
	{
		a = 0;
		while (str[i][a] != '\0')
		{
			if (!((str[i][a] <= '9' && str[i][a] >= '0') || (str[i][a] == '-')))
				return (0);
			else if ((str[i][a] <= '9' && str[i][a] >= '0')
				&& (str[i][a + 1] == '-' || str[i][a + 1] == '+'))
				return (0);
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

	a = 0;
	v = 1;
	if (!str)
		return (0);
	while (str[a] != '\0')
	{
		if (!((str[a] <= '9' && str[a] >= '0')
				|| ((str[a] == '-') || (str[a] == ' '))))
			v = 0;
		a++;
	}
	return (v);
}
