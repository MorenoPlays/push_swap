/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 04:49:12 by eda-mata          #+#    #+#             */
/*   Updated: 2024/07/19 04:49:17 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_liste	*get_next_min(t_liste **stack)
{
	t_liste	*head;
	t_liste	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->valor < min->valor))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	ft_lstadd_front2(t_liste **stack, t_liste *new)
{
	new->next = *stack;
	*stack = new;
}

t_liste	*ft_lstlast2(t_liste *head)
{
	t_liste	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

void	ft_lstadd_back2(t_liste **stack, t_liste *new)
{
	t_liste	*n;

	if (*stack)
	{
		n = ft_lstlast2(*stack);
		n->next = new;
		new->next = NULL;
	}
	else
	{
		*stack = new;
		(*stack)->next = NULL;
	}
}

void	index_stack(t_liste **stack)
{
	t_liste	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
