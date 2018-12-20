/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/20 18:51:57 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		valid(char *ttr, int j)
{
	int i;
	int len;
	int cnt;

	if (ttr[0] == '\0')
		return (1);
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
		return (checker(ttr, j));
	return (0);
}

int		tetra_separator(char *ttr, int normal)
{
	int				i;
	int				cnt;
	unsigned int	cnt1;

	cnt = 0;
	cnt1 = 0;
	i = 0;
	while (normal / 4 * 4 > (int)cnt1)
	{
		if (valid(ft_strsub(ttr, cnt1, 16), i) == 1)
		{
			i++;
			cnt += 16;
			g_lstttr.len++;
		}
		cnt1 += 16;
	}
	if (cnt == normal / 4 * 4)
		return (1);
	return (0x0);
}

int		separator(char *ttr, int normal)
{
	char	*tempo;
	char	*ttr2;

	ttr2 = ft_strnew(1);
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
	return (tetra_separator(ttr2, normal));
}

int		loop_validation(int *cnt, int *nmrl, char *ttr, int i)
{
	if (ttr[i] == '#' || ttr[i] == '.')
		*nmrl += 1;
	if (i > 0 && *nmrl % 4 + cnt == 0 && ttr[*nmrl] != '\n')
		return (0x0);
	if (i % 4 == 0)
		*cnt += 1;
	if (*nmrl % 16 != 0 && ttr[i] == '\n' && ttr[i + 1] == '\n')
		return (0x0);
	if (ttr[i] == '\n' && ttr[i + 1] == '\n' && ttr[i + 2] == '\n')
		return (0x0);
	if (*nmrl % 16 == 0 && ttr[i] != '\n' && ttr[i + 1] != '\n')
		return (0x0);
	return (1);
}

int		start_validation(char *ttr)
{
	int nmrl;
	int i;
	int cnt;

	i = 0;
	cnt = 0;
	nmrl = 0;
	if (ttr[i] != '#' && ttr[i] != '.')
		return (0x0);
	while (ttr[i])
	{
		if (loop_validation(&cnt, &nmrl, ttr, i) == 0x0)
			return (0x0);
		i++;
	}
	if ((ttr[i - 2] != '.' && ttr[i - 2] != '#') && ttr[i - 1] == '\n')
		return (0x0);
	if (nmrl % 16 == 0)
		return (separator(ttr, nmrl));
	return (0x0);
}
