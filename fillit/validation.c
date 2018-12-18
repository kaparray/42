/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/18 21:38:17 by hpowlows         ###   ########.fr       */
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
	else if (t1 == 3 && t2 == 1 && t3 == 3)
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

	t3 = g_ttr.arr[3] - g_ttr.arr[2];
	t2 = g_ttr.arr[2] - g_ttr.arr[1];
	t1 = g_ttr.arr[1] - g_ttr.arr[0];
	if (equ_tetramino_1(t1, t2, t3, i))
		return (1);
	else if (equ_tetramino_2(t1, t2, t3, i))
		return (1);
	else
		return (0x0);
	return (1);
}

int is_tetramino()
{
	int i;

	i = 0;
	while (1 > i) // TODO malloc memmory for len and update this value
	{
		if (type_of_tetramino(i) == 0x0)
		{
			return (0);
		}

		i++;
	}
	return (1);
}

int checker(char *ttr)
{
	int i;
	int cnt;

	i = 0;
	cnt = -1;
	while (ttr[i])
	{
		if (ttr[i] == TR)
			g_ttr.arr[++cnt] = i;
		i++;
	}
	return (is_tetramino());
}

int valid(char *ttr)
{
	int i;
	int len;
	int cnt;

	i = -1;
	len = 0;
	cnt = 0;
	while (ttr[++i])
	{
		if (ttr[i] == TR)
			cnt++;
		else if (ttr[i] == '.')
			len++;
		else
			return (0);
	}
	if (cnt == 4 && len == 12)
		return (checker(ttr));
	return (0);
}

int separator(char *ttr, int normal)
{
	char *tempo;
	char *ttr2;

	tempo = ttr2;
	while (*ttr)
	{
		if (*ttr != '\n')
		{
			*tempo = *ttr;
			tempo++;
		}
		ttr++;
	}
	*tempo = '\0';
	return (valid(ttr2));
}

int start_validation(char *ttr)
{
	int normal;
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	normal = 0;
	while (ft_strlen(ttr) > cnt)
	{

		if (ttr[cnt] == '#' || ttr[cnt] == '.')
			normal++;
		else if (ttr[cnt] == '\n')
			i++;
		else
			return (0x0);
		cnt++;
	}
	if (normal > 16)
	{
		if (i - (normal / 4) != 1)
			return (0x0);
	}
	else if (normal == 16 && i != 4)
		return (0x0);

	return (separator(ttr, normal));
}
