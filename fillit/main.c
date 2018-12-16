/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/16 17:53:49 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

// int main(void)
// {
//	t_ttr t;
//	g_lstttr lstt;




// 	return (0);
// }



int main(void) {

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
		//free(&line);
	}

	if (valid(arr) != 0x0) {
		printf("true");
		printf("%d", g_lstttr.arr[0]);
	}
	else
		printf("false");
	return (0);
}
