/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaparray <kaparray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 21:15:37 by hpowlows          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/12/17 14:02:41 by kaparray         ###   ########.fr       */
=======
/*   Updated: 2018/12/16 17:53:49 by hpowlows         ###   ########.fr       */
>>>>>>> 6bd8e836abd64fb224bd48b1ba700f344a58df6e
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

