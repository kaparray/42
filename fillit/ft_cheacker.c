/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:15:15 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 20:41:17 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_island_check(char *str, char c, int i, int d)
{
	while (str[++i])
		if (str[i] == 0x23 || str[i] == c)
		{
			str[i] = c;
			(str[i - 1] && (str[i - 1] == 0x23 || str[i - 1] == c)) ? d++ : d;
			(str[i + 1] && (str[i + 1] == 0x23 || str[i + 1] == c)) ? d++ : d;
			(str[i - 5] && (str[i - 5] == 0x23 || str[i - 5] == c)) ? d++ : d;
			(str[i + 5] && (str[i + 5] == 0x23 || str[i + 5] == c)) ? d++ : d;
		}
	return (d == 6 || d == 8 ? 1 : 0);
}

int		ft_piece_check(char *str, int hex, int nl, int d)
{
	int	i;

	i = 0;
	while (str[i] == 0x23 || str[i] == 0x2e || str[i] == 0x0a)
	{
		(str[i] == 0x23) ? hex++ : hex;
		(str[i] == 0x2e) ? d++ : d;
		(str[i] == 0x0a) ? nl++ : nl;
		if (i + 1 == 21)
			if (str[i] != '\n')
				return (0);
		i++;
	}
	return (((hex % 4 == 0) && ((nl + 1) % 5 == 0) && (d % 12 == 0) &&
				((i + 1) % 21 == 0)) ? 1 : 0);
}
