/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dealer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 18:17:16 by jagarcia          #+#    #+#             */
/*   Updated: 2018/12/21 13:53:56 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		cosa(int **aux_tetrim, int *aux, int **min)
{
	*aux_tetrim = aux + 1;
	while (**aux_tetrim >= 0)
	{
		if (!(*min) && (**aux_tetrim > *aux))
			*min = (*aux_tetrim);
		else if ((**aux_tetrim > *aux) && (**aux_tetrim < **min))
			*min = (*aux_tetrim);
		(*aux_tetrim)++;
	}
}

void	ft_swap(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_pos_int(int *arr)
{
	int				min;
	unsigned int	i;

	while (*arr >= 0)
	{
		i = 1;
		while (arr[i] >= 0)
		{
			if (arr[i] < *arr)
			{
				min = arr[i];
				arr[i] = *arr;
				*arr = min;
			}
			i++;
		}
		arr++;
	}
}

static int		update_aux_tetrim(int **aux_tetrim,
		unsigned char *sqr, unsigned int side, int *tetrim)
{
	int		*aux;
	int		*min;

	aux = *aux_tetrim;
	min = NULL;
	while (!min)
	{
		cosa(aux_tetrim, aux, &min);
		if (!min && *(aux - 1) < 0)
			return (0);
		else if (!min)
		{
			if (!(ft_erase(sqr, side, *(aux - 1), tetrim)))
				aux--;
			else
				break ;
		}
	}
	*aux_tetrim = aux;
	if (min)
	{
		ft_swap(min, *aux_tetrim);
		ft_sort_pos_int(*aux_tetrim + 1);
	}
	return (1);
}

void			ft_dealer(unsigned char *sqr,
		unsigned int side, int *tetrim, int **aux_tetrim)
{
	if (!(ft_fill(sqr, side, tetrim[**aux_tetrim], **aux_tetrim)))
	{
		if (!(*((*aux_tetrim) - 1) < 0))
		{
			if (ft_erase(sqr, side, *(--(*aux_tetrim)), tetrim))
				(*aux_tetrim)++;
			else if (!update_aux_tetrim(aux_tetrim, sqr, side, tetrim))
				**aux_tetrim = -1;
		}
		else
			(*aux_tetrim)--;
	}
	else
		(*aux_tetrim)++;
}
