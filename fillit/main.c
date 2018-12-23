/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 17:38:59 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av) {
	char *arr;
	char **pieces;
	char *map;
	size_t size;

	size = 0;
	if (ac == 2)
	{
		arr = ft_reader(av[1], 0);
		pieces = ft_seporatr(arr, 'A');
	}
	else
	{
		ft_putstr("usage");
	}

}
