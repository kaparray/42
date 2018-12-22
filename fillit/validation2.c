/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:49:24 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/22 23:58:07 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int		equ_tetramino_1(int t1, int t2, int t3, int i)
// {
// 	if (t1 == 3 && t2 == 1 && t3 == 1)
// 		g_lstttr.arr[i] = T1;
// 	else if (t1 == 1 && t2 == 1 && t3 == 3)
// 		g_lstttr.arr[i] = T2;
// 	else if (t1 == 3 && t2 == 1 && t3 == 4)
// 		g_lstttr.arr[i] = T3;
// 	else if (t1 == 4 && t2 == 1 && t3 == 3)
// 		g_lstttr.arr[i] = T4;
// 	else if (t1 == 4 && t2 == 4 && t3 == 4)
// 		g_lstttr.arr[i] = T5;
// 	else if (t1 == 1 && t2 == 1 && t3 == 1)
// 		g_lstttr.arr[i] = T6;
// 	else if (t1 == 1 && t2 == 3 && t3 == 1)
// 		g_lstttr.arr[i] = T7;
// 	else if (t1 == 1 && t2 == 2 && t3 == 1)
// 		g_lstttr.arr[i] = T8;
// 	else if (t1 == 1 && t2 == 4 && t3 == 1)
// 		g_lstttr.arr[i] = T9;
// 	else if (t1 == 4 && t2 == 1 && t3 == 4)
// 		g_lstttr.arr[i] = T10;
// 	else
// 		return (0);
// 	return (1);
// }

// int		equ_tetramino_2(int t1, int t2, int t3, int i)
// {
// 	if (t1 == 3 && t2 == 1 && t3 == 3)
// 		g_lstttr.arr[i] = T11;
// 	else if (t1 == 4 && t2 == 4 && t3 == 1)
// 		g_lstttr.arr[i] = T12;
// 	else if (t1 == 2 && t2 == 1 && t3 == 1)
// 		g_lstttr.arr[i] = T13;
// 	else if (t1 == 4 && t2 == 3 && t3 == 1)
// 		g_lstttr.arr[i] = T14;
// 	else if (t1 == 4 && t2 == 4 && t3 == 1)
// 		g_lstttr.arr[i] = T15;
// 	else if (t1 == 1 && t2 == 1 && t3 == 2)
// 		g_lstttr.arr[i] = T16;
// 	else if (t1 == 1 && t2 == 1 && t3 == 4)
// 		g_lstttr.arr[i] = T17;
// 	else if (t1 == 1 && t2 == 4 && t3 == 4)
// 		g_lstttr.arr[i] = T18;
// 	else if (t1 == 1 && t2 == 3 && t3 == 4)
// 		g_lstttr.arr[i] = T19;
// 	else
// 		return (0);
// 	return (1);
// }

// char	*separator(char *ttr)
// {
// 	char	*tempo;
// 	char	*ttr2;

// 	ttr2 = ft_strnew(1);
// 	tempo = ttr2;
// 	while (*ttr)
// 	{
// 		if (*ttr != '\n')
// 		{
// 			*tempo = *ttr;
// 			tempo++;
// 		}
// 		ttr++;
// 	}
// 	*tempo = '\0';
// 	return (ttr2);
// }

// int		find_xyz(char *s, int k)
// {
// 	int i;
// 	int j;

// 	i = 0;
// 	j = -1;
// 	while (s[i])
// 	{
// 		if (s[i] == '#')
// 			g_ttr[++j] = i;
// 		i++;
// 	}
// 	if (!equ_tetramino_1(g_ttr[1] - g_ttr[0], g_ttr[2] - g_ttr[1], g_ttr[3] - g_ttr[2], k)\
// 		|| !equ_tetramino_1(g_ttr[1] - g_ttr[0], g_ttr[2] - g_ttr[1], g_ttr[3] - g_ttr[2], k))
// 		return (0);
// 	return (1);
// }

// int		valid_figure(char *s)
// {
// 	int i;
// 	char *tmp;
// 	int k;

// 	k = 0;
// 	s = separator(s);
// 	i = 0;
// 	while (s[i])
// 	{
// 		tmp = ft_strsub(s, i, 16);
// 		if (!find_xyz(tmp, k))
// 			return (0);
// 		i += 16;
// 		k++;
// 	}
// 	return (1);
// }
