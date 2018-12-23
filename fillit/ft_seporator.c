/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_seporator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:10:07 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 18:37:22 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_seporator(char *str, char c)
{
	char **dst;
	char *tmp;

	tmp = str;
	dst = (char **)malloc(sizeof(char *) * 27);
	while (*tmp != 0x0)
	{
		dst[g_piece] = ft_strnew(21);
		ft_strncpy(dst[g_piece], tmp, 21);
		if (!ft_piece_check(str, 0, 0, 0) ||
			ft_island_check(dst[g_piece], c, -1, 0))
		{
			ft_putstr("error\n");
			exit(0);
		}
		ft_island_check(dst[g_piece], c++, -1, 0);
		g_piece += 1;
		if (!tmp[20])
			break ;
		tmp += 21;
	}
	tmp[g_piece] = 0x0;
	return (dst);
}
