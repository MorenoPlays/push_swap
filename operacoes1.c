/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:40:24 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 20:20:41 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_liste **stack)
{
	t_liste	*head;
	t_liste	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize2(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		exit(-1);
	tmp_val = head->valor;
	tmp_index = head->index;
	head->valor = next->valor;
	head->index = next->index;
	next->valor = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	sa(t_liste **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_liste **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sb", 1);
	return (0);
}

int	ss(t_liste **a, t_liste **b)
{	
	if ((ft_lstsize2(*a) < 2) || (ft_lstsize2(*b) < 2))
		return (-1);
	swap(a);
	swap(b);
	ft_putendl_fd("ss", 1);
	return (0);
}

int	push(t_liste **stack_to, t_liste **stack_from)
{
	t_liste	*tmp;
	t_liste	*head_to;
	t_liste	*head_from;

	if (ft_lstsize2(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}
