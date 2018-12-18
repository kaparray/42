/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/18 21:37:34 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av) {

	int		fd;
	char 	*arr;
	char	*line;


	if (ac == 2)
	{
		arr = ft_strnew(1);
		g_ttr.arr = malloc(sizeof(int) * 4);
		g_lstttr.arr = malloc(sizeof(int) * 1);
		fd = open(av[1], O_RDONLY);

		//temporary code !!! be careful !!!
		reader(fd, arr);

		int a = start_validation(arr);
		int a = start_validation(arr);
		if (a == 0x0)
		{
			ft_putendl("error");
			return (1);
		}
		else
		{
			printf("true");
			printf("%d", g_lstttr.arr[0]);
		}
	}
	else
	{
		ft_putendl("usage");
		return (1);
	}

	return (0);
}
