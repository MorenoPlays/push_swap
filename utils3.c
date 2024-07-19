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

void	insercao(t_liste *a, t_liste *b, char **argv)
{
	int			i;
	int			index;
	long int	valor;

	index = 0;
	i = 1;
	while (argv[i] != (void *)0)
	{
		valor = ft_atoi_long(argv[i]);
		if (valor > INT_MAX || valor < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			ft_remove_list(&a);
			ft_remove_list(&b);
			exit(1);
		}
		index += inserir_no_fim(&a, valor);
		i++;
	}
	index_stack(&a);
	if (ordenado(&a) == 0)
		push_swap(&a, &b, index);
	ft_remove_list(&a);
	ft_remove_list(&b);
}

void	insercao2(t_liste *a, t_liste *b, char **argv)
{
	int			i;
	int			index;
	long int	valor;

	index = 0;
	i = 0;
	while (argv[i] != (void *)0)
	{
		valor = ft_atoi_long(argv[i]);
		if (valor > INT_MAX || valor < INT_MIN)
		{
			ft_putstr_fd("Error\n", 2);
			ft_remove_list(&a);
			ft_remove_list(&b);
			exit(1);
		}
		index += inserir_no_fim(&a, valor);
		i++;
	}
	index_stack(&a);
	push_swap(&a, &b, index);
	ft_remove_list(&a);
	ft_remove_list(&b);
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

int	quatia(t_liste **a)
{
	int			num;
	t_liste		*aux;

	aux = *a;
	num = 0;
	if (aux)
	{
		while (aux)
		{
			num++;
			aux = aux->next;
		}
	}
	return (num);
}

void	ordenar_ab(t_liste **a, t_liste **b)
{
	t_liste		*aux;
	int			i;
	int			j;

	aux = *a;
	i = 0;
	j = 0;
	if (aux && aux->next)
	{
		if ((aux->valor > aux->next->valor))
			i = 1;
	}
	aux = *b;
	if (aux && aux->next)
	{
		if (aux->valor < aux->next->valor)
			j = 1;
	}
	if (j == 1 && i == 1)
		ss(&*a, &*b);
	vra(maior_valor(*a), &*a);
	vrrr(menor_valor(*a), maior_valor(*b), &*a, &*b);
	vrra(menor_valor(*a), &*a);
}
