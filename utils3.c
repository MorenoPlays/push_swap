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

void	index_stack(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

static int	get_max_bits(t_list **stack)
{
	t_list	*head;
	int		max;
	int		max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_lstsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}

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
	if (ordenado(&a) == 0)
	{
		push_swap(&a, &b, index);
	}
	ft_remove_list(&a, &b);
}

void	insercao2(t_pilha *a, t_pilha *b, char **argv)
{
	int	i;
	int	valor;
	int	index;

	index = 0;
	i = 0;
	while (argv[i] != (void *)0)
	{
		valor = ft_atoi(argv[i]);
		index += inserir_no_fim(&a, valor);
		i++;
	}
	push_swap(&a, &b, index);
	ft_remove_list(&a, &b);
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

int	quatia(t_pilha **a, t_pilha **b)
{
	int			num;
	t_pilha		*aux;
	//t_pilha		*aux1;
	aux = *a;
	num = 0;
	if (aux->proximo)
	{
		while (aux->proximo)
		{
			aux = aux->proximo;
			num++;
		}
	}
	if(num > 6 && ordenado(&*a) == 0)
	{
		radix_sort(&*a, &*b);
		/*while(ordenado(&*a)==0)
		{
			vra(maior_valor(*a), &*a);
			vrra(menor_valor(*a), &*a);
			if(!(*b))
				pb(&*a, &*b);
			if((*a)->valor > (*b)->valor)
				pb(&*a, &*b);
			else if ((*a)->valor > (*a)->proximo->valor)
				ra(&*a);
			else if ((*a)->valor < (*b)->valor)
			{
				pa(&*a, &*b);
				sa(&*a);
			}
			else
			{
				pb(&*a, &*b);
				vrb(menor_valor(*b), &*b);
				vrrb(maior_valor(*b), &*b);
			}
		}*/
	}
	aux = *b;
	while(aux)
	{
		printf("valor:%d\n" ,aux->valor);
		aux = aux->proximo;
	}
	return (num);
}

void	ordenar_ab(t_pilha **a, t_pilha **b)
{
	t_pilha		*aux;
	int			i;
	int			j;

	aux = *a;
	i = 0;
	j = 0;
	if (aux && aux->proximo)
	{
		if ((aux->valor > aux->proximo->valor))
			i = 1;
	}
	aux = *b;
	if (aux && aux->proximo)
	{
		if (aux->valor < aux->proximo->valor)
			j = 1;
	}
	if (j == 1 && i == 1)
		ss(&*a, &*b);
	vra(maior_valor(*a), &*a);
	vrb(menor_valor(*b), &*b);
	vrrr(menor_valor(*a), maior_valor(*b), &*a, &*b);
	vrra(menor_valor(*a), &*a);
	vrrb(maior_valor(*b), &*b);
}
