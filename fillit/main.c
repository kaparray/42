/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/26 20:39:13 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	char	*arr;
	char	**pieces;
	char	*map;
	int		size;

	size = 0;
	if (ac == 2)
	{
		arr = ft_reader(av[1], 0);
		if (ft_strlen(arr) > 544)
		{
			ft_putstr("error\n");
			goto ETRACT;
		}
		pieces = ft_seperator(arr, 0x41);
		while (size * size < g_piece * 4)
			size += 1;
		map = ft_strnew(size * (size + 1));
		ft_map_gnrtion(map, pieces, -1, size);
		ft_putchar(0x0a);
	}
	else
		ft_putstr("usage\n");
		ETRACT:
	return (0);
}
