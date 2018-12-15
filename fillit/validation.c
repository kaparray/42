/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/15 21:55:43 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		validation(char *ttr)
{
	int		i;
	int		len;
	int		cnt;

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

int		checker(int *ttr)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = -1;
	while (ttr[i])
	{
		if (ttr[i] == TR)
			g_ttr.arr[cnt++] = i;
	}
	return (isTetramino());
}

int		typeOfTetramino()
{
	int t1;
	int t2;
	int t3;

	t3 = g_ttr.arr[3] - g_ttr.arr[2];
	t2 = g_ttr.arr[2] - g_ttr.arr[1];
	t1 = g_ttr.arr[1] - g_ttr.arr[0];
	if (t1 == 3 && t2 == 1 && t3 == 1)  // is ttr
		;
	else
		return (0);
}

