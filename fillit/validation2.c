/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:49:24 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/20 18:51:58 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		equ_tetramino_1(int t1, int t2, int t3, int i)
{
	if (t1 == 3 && t2 == 1 && t3 == 1)
		g_lstttr.arr[i] = T1;
	else if (t1 == 1 && t2 == 1 && t3 == 3)
		g_lstttr.arr[i] = T2;
	else if (t1 == 3 && t2 == 1 && t3 == 4)
		g_lstttr.arr[i] = T3;
	else if (t1 == 4 && t2 == 1 && t3 == 3)
		g_lstttr.arr[i] = T4;
	else if (t1 == 4 && t2 == 4 && t3 == 4)
		g_lstttr.arr[i] = T5;
	else if (t1 == 1 && t2 == 1 && t3 == 1)
		g_lstttr.arr[i] = T6;
	else if (t1 == 1 && t2 == 3 && t3 == 1)
		g_lstttr.arr[i] = T7;
	else if (t1 == 1 && t2 == 2 && t3 == 1)
		g_lstttr.arr[i] = T8;
	else if (t1 == 1 && t2 == 4 && t3 == 1)
		g_lstttr.arr[i] = T9;
	else if (t1 == 4 && t2 == 1 && t3 == 4)
		g_lstttr.arr[i] = T10;
	else
		return (0);
	return (1);
}

int		equ_tetramino_2(int t1, int t2, int t3, int i)
{
	if (t1 == 3 && t2 == 1 && t3 == 3)
		g_lstttr.arr[i] = T11;
	else if (t1 == 4 && t2 == 4 && t3 == 1)
		g_lstttr.arr[i] = T12;
	else if (t1 == 2 && t2 == 1 && t3 == 1)
		g_lstttr.arr[i] = T13;
	else if (t1 == 4 && t2 == 3 && t3 == 1)
		g_lstttr.arr[i] = T14;
	else if (t1 == 4 && t2 == 4 && t3 == 1)
		g_lstttr.arr[i] = T15;
	else if (t1 == 1 && t2 == 1 && t3 == 2)
		g_lstttr.arr[i] = T16;
	else if (t1 == 1 && t2 == 1 && t3 == 4)
		g_lstttr.arr[i] = T17;
	else if (t1 == 1 && t2 == 4 && t3 == 4)
		g_lstttr.arr[i] = T18;
	else if (t1 == 1 && t2 == 3 && t3 == 4)
		g_lstttr.arr[i] = T19;
	else
		return (0);
	return (1);
}

int		type_of_tetramino(int i)
{
	int t1;
	int t2;
	int t3;

	t3 = g_ttr[3] - g_ttr[2];
	t2 = g_ttr[2] - g_ttr[1];
	t1 = g_ttr[1] - g_ttr[0];
	if (equ_tetramino_1(t1, t2, t3, i))
		return (1);
	else if (equ_tetramino_2(t1, t2, t3, i))
		return (1);
	else
		return (0x0);
	return (1);
}

int		is_tetramino(int j)
{
	if (type_of_tetramino(j) == 0x0)
		return (0);
	return (1);
}

int		checker(char *ttr, int j)
{
	int i;
	int cnt;

	i = 0;
	cnt = -1;
	while (ttr[i])
	{
		if (ttr[i] == TR)
			g_ttr[++cnt] = i;
		i++;
	}
	return (is_tetramino(j));
}
