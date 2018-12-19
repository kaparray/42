/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmraz <mmraz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:35:00 by mmraz             #+#    #+#             */
/*   Updated: 2018/12/18 15:16:14 by mmraz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


/* Create map for the worst case ever */



int		check_posiibility(int i, char map[i][j])
{
	if (t = 1)
	{

	}

}

char	**create_map(ssize_t len)
{
	char	**map;
	ssize_t	i;
	ssize_t	j;

	i = 0;
	if (!(map = (char **)ft_memalloc(sizeof(char *) * (len))))
		return (NULL);
	while (i < len)
	{
		map[i] = ft_strnew(len);
		j = 0;
		while (j < len)
			map[i][j++] = '.';
		i++;
	}
	return (map);
}

char	**solve_case(t_lstttr ttr, ssize_t max_side)
{
	while()
}


/* Define map maximum possible size and create map */

char		**solve(t_lstttr ttr)
{
	ssize_t	max_side;
	char	**map;

	max_side = ttr.len * 4;
	if (!(map = create_map(max_side)))
		return (NULL);
	solve_case(ttr, max_side);
	return (0);
}