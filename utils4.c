/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:21:36 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/05 11:21:56 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra1(t_liste **a)
{
	int			num;
	t_liste		*aux;
	t_liste		*anterior;

	aux = *a;
	anterior = NULL;
	if (aux && aux->next)
	{
		while (aux->next)
		{
			anterior = aux;
			aux = aux->next;
		}
		num = aux->valor;
		inserir_inicio(&*a, num);
		anterior->next = NULL;
		free(aux);
	}
}

void	rrb1(t_liste **b)
{
	int			num;
	t_liste		*aux;
	t_liste		*anterior;

	aux = *b;
	anterior = NULL;
	if (aux && aux->next)
	{
		while (aux->next)
		{
			anterior = aux;
			aux = aux->next;
		}
		num = aux->valor;
		inserir_inicio(&*b, num);
		anterior->next = NULL;
		free(aux);
	}
}

void	vrrr(int menor_de_a, int maior_de_b, t_liste **a, t_liste **b)
{
	t_liste	*aux;
	int		va;
	int		vb;

	va = 0;
	vb = 0;
	aux = *a;
	if (!(*a) || !(*b))
		return ;
	while (aux->next)
		aux = aux->next;
	if (aux->valor == menor_de_a)
		va = 1;
	aux = *b;
	while (aux->next)
		aux = aux->next;
	if (aux->valor == maior_de_b)
		vb = 1;
	if (vb == 1 && va == 1)
		rrr(&*a, &*b);
}

void	ft_remove_list(t_liste **a)
{
	t_liste		*aux;

	aux = *a;
	while (aux)
	{
		*a = aux->next;
		free(aux);
		aux = *a;
	}
}

long int	ft_atoi_long(const char *str)
{
	int			i;
	int			np;
	long int	num;

	np = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ' || str[i] == '\t') || str[i] == '\f'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			np = -1;
	if (str[i] == '+' || str[i] == '-' || !(str[i] >= '0' && str[i] <= '9'))
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return ((long int)(np * num));
}
