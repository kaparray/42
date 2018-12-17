/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/17 21:20:55 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		add_new_line(char *line)
{
	if (ft_strequ(line, ""))
	{
		line = "\n";
	}
}


int		main(void) {

   	int     fd;
    char 	*arr;
   	char	*line;

	arr = ft_strnew(1);
	g_ttr.arr = malloc(sizeof(int) * 4);
	g_lstttr.arr = malloc(sizeof(int) * 1);
    fd = open("val", O_RDONLY);

	while (get_next_line(fd, &line) > 0)
	{

		arr = ft_strjoin(arr, line);
		free(line);
	}

	if (valid(arr) != 0x0) {
		printf("true");
		printf("%d", g_lstttr.arr[0]);
	}
	else
		printf("false");
	return (0);
}

