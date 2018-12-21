/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/21 17:20:56 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av) {

	int		fd;
	char 	*arr;

	if (ac == 2)
	{
		arr = ft_strnew(1);
		g_ttr = malloc(sizeof(int) * 4);
		g_lstttr.arr = malloc(sizeof(int) * 1);
		fd = open(av[1], O_RDONLY);

		//temporary code !!! be careful !!!
		arr = reader(fd);

		int a = start_validation(arr);
		//int a = start_validation(arr);
		if (a == 0x0)
		{
			ft_putendl("error");
			return (1);
		}
		else
		{
			
			printf("true");
			//printf("%d	%d	%d	%d", g_lstttr.arr[0], g_lstttr.arr[1], g_lstttr.arr[2], g_lstttr.arr[3]);
		}
		ft_putstr((const char *)ft_filler(g_lstttr.arr, g_lstttr.len));
	}
	else
	{
		ft_putendl("usage");
		return (1);
	}
	return (0);
}
