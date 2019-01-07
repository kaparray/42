/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_fn1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:23:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/01/06 18:08:45 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		is_placeable(t_map *map, t_piece *piece, int i, int j)
{
	int index;

	index = 0;
	while (index < 4)
	{
		if (map->tab[i + piece->conf[index].i]
				[j + piece->conf[index].j] != 0)
			return (0);
		index++;
	}
	return (1);
}

void	add_piece(t_map *map, t_piece *piece, int i, int j)
{
	int index;
	int pc_index;

	pc_index = piece->letter - 0x41 + 1;
	index = 0;
	while (index < 4)
	{
		map->tab[i + piece->conf[index].i][j + piece->conf[index].j] = pc_index;
		index++;
	}
}

int		find_position(t_map *map, t_piece *piece)
{
	while (piece->i_start + piece->i_max < map->size)
	{
		while (piece->j_start + piece->j_max < map->size)
		{
			if (!map->tab[piece->i_start][piece->j_start])
				if (is_placeable(map, piece, piece->i_start, piece->j_start))
				{
					add_piece(map, piece, piece->i_start, piece->j_start);
					piece->j_start++;
					return (1);
				}
			piece->j_start++;
		}
		piece->j_start = piece->j_min * -1;
		piece->i_start++;
	}
	return (0);
}

void	clean(t_map *map, t_piece *piece)
{
	int	k;

	map->tab[piece->i_start][piece->j_start - 1] = 0;
	k = 1;
	while (k < 4)
	{
		map->tab[piece->i_start + piece->conf[k].i]
			[piece->j_start + piece->conf[k].j - 1] = 0;
		k++;
	}
}
