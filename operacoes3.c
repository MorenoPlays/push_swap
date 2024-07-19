/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:05:29 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/12 10:00:46 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rr(t_liste **a, t_liste **b)
{
	if ((ft_lstsize2(*a) < 2) || (ft_lstsize2(*b) < 2))
		return (-1);
	rotate(a);
	rotate(b);
	ft_putendl_fd("rr", 1);
	return (0);
}

int	reverserotate(t_liste **stack)
{
	t_liste	*head;
	t_liste	*tail;

	if (ft_lstsize2(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast2(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_liste **a)
{
	if (reverserotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_liste **b)
{
	if (reverserotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_liste **a, t_liste **b)
{
	if ((ft_lstsize2(*a) < 2) || (ft_lstsize2(*b) < 2))
		return (-1);
	reverserotate(a);
	reverserotate(b);
	ft_putendl_fd("rrr", 1);
	return (0);
}
