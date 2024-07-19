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
	struct lista	*next;
	int				valor;
	int				index;
}					t_liste;

long int	ft_atoi_long(const char *str);
void		inserir_inicio(t_liste **lista, int valor);
int			inserir_no_fim(t_liste **lista, int valor);
int			sa(t_liste **a);
int			sb(t_liste **b);
int			ss(t_liste **a, t_liste **b);
int			pa(t_liste **a, t_liste **b);
int			pb(t_liste **a, t_liste **b);
int			ra(t_liste **a);
int			rb(t_liste **b);
int			rr(t_liste **a, t_liste **b);
int			rra(t_liste **a);
int			rrb(t_liste **b);
void		rra1(t_liste **a);
void		rrb1(t_liste **b);
int			rrr(t_liste **a, t_liste **b);
void		vrra(int min_valor, t_liste **a);
int			menor_valor(t_liste *head);
int			maior_valor(t_liste *head);
int			verificador(char **str, int i);
int			verificador2(char *str, int a);
void		vra(int maior_valor, t_liste **a);
void		push_swap(t_liste **a, t_liste **b, int index);
void		insercao(t_liste *a, t_liste *b, char **argv);
void		insercao2(t_liste *a, t_liste *b, char **argv);
int			number_replace(char *str, int v);
int			quatia(t_liste **a);
void		ordenar_ab(t_liste **a, t_liste **b);
int			ordenado(t_liste**a);
void		vrrr(int menor_de_a, int maior_de_b, t_liste **a, t_liste **b);
void		ft_remove_list(t_liste **a);
void		radix(t_liste **stack_a, t_liste **stack_b);
int			*push1(t_liste **a);
void		indexar(t_liste **a);
int			ordenar_a(t_liste **a, t_liste **b, int index, int posicao);
int			ordenar_b(t_liste **a, t_liste **b, int index, int posicao);
void		ft_remove_matriz(char **a);
void		index_stack(t_liste **stack);
int			ft_lstsize2(t_liste *lst);
void		ft_lstadd_front2(t_liste **stack, t_liste *new);
t_liste		*ft_lstlast2(t_liste *head);
void		ft_lstadd_back2(t_liste **stack, t_liste *new);
int			reverserotate(t_liste **stack);
int			rotate(t_liste **stack);
int			push(t_liste **stack_to, t_liste **stack_from);
int			swap(t_liste **stack);
#endif
