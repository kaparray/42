/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/22 22:10:32 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av) {

	int		fd;
	char 	*arr;

	if (ac == 2)
	{
		arr = ft_strnew(1);

		fd = open(av[1], O_RDONLY);

		//temporary code !!! be careful !!!
		arr = reader(fd);

		int a = validation(arr);
		//printf("%d	%d	%d	%d %d  %d", g_lstttr.arr[0], g_lstttr.arr[1], g_lstttr.arr[2], g_lstttr.arr[3], g_lstttr.arr[4], g_lstttr.arr[4]);

		if (a == 0)
		{
			ft_putendl("error");
			return (1);
		}
		else
		{
			printf("\ntrue");
			printf("%d	%d	%d	%d %d  %d", g_lstttr.arr[0], g_lstttr.arr[1], g_lstttr.arr[2], g_lstttr.arr[3], g_lstttr.arr[4], g_lstttr.arr[4]);

		}
	}
	else
	{
		ft_putendl("usage");
		return (1);
	}
	return (0);
}
