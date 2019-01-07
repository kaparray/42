/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:23:48 by hpowlows          #+#    #+#             */
/*   Updated: 2019/01/06 18:08:53 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int ac, char **av)
{
	int		fd;
	t_piece	**pieces;
	int		cnt;

	cnt = 0;
	if (ac == 2)
	{
		pieces = (t_piece**)malloc(sizeof(t_piece*) * 0x1a);
		fd = open(*(av + 1), 0x0000);
		if (check_file(fd, pieces, &cnt, 0))
		{
			*(pieces + cnt) = 0;
			close(fd);
			if (check_newline(av[1], cnt))
				generate(pieces, cnt);
			else
				ft_putstr("error\n");
		}
		else
			ft_putstr("error\n");
	}
	else
		write(1, "usage\n", 6);
	return (0);
}
