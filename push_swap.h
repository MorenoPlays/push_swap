/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eda-mata <eda-mata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:53:57 by eda-mata          #+#    #+#             */
/*   Updated: 2024/06/14 11:10:09 by eda-mata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <limits.h>
# include "libft/libft.h"

typedef struct lista
{
	struct lista	*proximo;
	int				valor;
	int				mod;
	int				index;
}					t_pilha;

long int	ft_atoi_long(const char *str);
void		inserir_inicio(t_pilha **lista, int valor, int mod);
int			inserir_no_fim(t_pilha **lista, int valor);
void		sa(t_pilha **a);
void		sb(t_pilha **b);
void		ss(t_pilha **a, t_pilha **b);
void		pa(t_pilha **a, t_pilha **b);
void		pb(t_pilha **a, t_pilha **b);
void		ra(t_pilha **a);
void		rb(t_pilha **b);
void		rr(t_pilha **a, t_pilha **b);
void		rra(t_pilha **a);
void		rrb(t_pilha **b);
void		rra1(t_pilha **a);
void		rrb1(t_pilha **b);
void		rrr(t_pilha **a, t_pilha **b);
void		vrra(int min_valor, t_pilha **a);
int			menor_valor(t_pilha *head);
int			maior_valor(t_pilha *head);
int			verificador(char **str, int i);
int			verificador2(char *str, int a);
void		vra(int maior_valor, t_pilha **a);
void		push_swap(t_pilha **a, t_pilha **b, int index);
void		insercao(t_pilha *a, t_pilha *b, char **argv);
void		insercao2(t_pilha *a, t_pilha *b, char **argv);
int			number_replace(char *str, int v);
int			quatia(t_pilha **a);
void		ordenar_ab(t_pilha **a, t_pilha **b);
int			ordenado(t_pilha **a);
void		vrrr(int menor_de_a, int maior_de_b, t_pilha **a, t_pilha **b);
void		ft_remove_list(t_pilha **a);
void		radix(t_pilha **stack_a, t_pilha **stack_b);
int			*push(t_pilha **a);
void		indexar(t_pilha **a);
int			ordenar_a(t_pilha **a, t_pilha **b, int index, int posicao);
int			ordenar_b(t_pilha **a, t_pilha **b, int index, int posicao);
void		ft_remove_matriz(char **a);
#endif
