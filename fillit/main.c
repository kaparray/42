/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/18 17:01:38 by hpowlows         ###   ########.fr       */
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

		if (start_validation(arr) != 0x0) {
			printf("true");								// This is temprary output
			printf("%d", g_lstttr.arr[0]);				// This is temprary output
		}
		else
			printf("false");							// This is temprary output
	}
	else
	{
		ft_putendl("usage");
		return (1);
	}

	return (0);
}
