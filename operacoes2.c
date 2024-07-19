/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:02:20 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 08:29:55 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_liste **a, t_liste **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (0);
}

int	pb(t_liste **a, t_liste **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (0);
}

int	rotate(t_liste **stack)
{
	t_liste	*head;
	t_liste	*tail;

	if (ft_lstsize2(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast2(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	ra(t_liste **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (0);
}

int	rb(t_liste **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (0);
}
