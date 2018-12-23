/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:40:08 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 18:47:27 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_map_gnrtion(char *map, char **pieces, int a, size_t size)
{
	while (1)
	{
		a = -1;
		while (++a < (size + 1))
			map[a] = (a % (size + 1) == size) ? 0x0a : 0x2e;
		map[a] = 0x0;
		if (!ft_solver(map, pieces, -1))
		{
			size++;
			map = ft_strnew(size * (size + 1));
		}
		else
		{
			ft_putstr(map);
			exit(0);
		}
	}
}
