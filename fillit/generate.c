/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:23:48 by mmraz             #+#    #+#             */
/*   Updated: 2019/01/06 18:09:47 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		reset_start_position(t_piece *piece)
{
	piece->i_start = 0;
	piece->j_start = piece->j_min * -1;
}

int			set_size(int count)
{
	int i;

	i = 2;
	while (i * i < count * 4)
		i++;
	return (i);
}

static void	print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (!map->tab[i][j])
				ft_putchar(0x2e);
			else
				ft_putchar(0x41 + map->tab[i][j] - 1);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

static int	back(t_map *map, t_piece **pieces, int ndx)
{
	unsigned int	k;

	if (ndx < map->count)
	{
		k = 0;
		while (*(pieces + k))
		{
			if (!pieces[k]->used)
			{
				while (find_position(map, *(pieces + k)))
				{
					pieces[k]->used = 1;
					if (back(map, pieces, ndx + 1))
						return (1);
					clean(map, *(pieces + k));
					pieces[k]->used = 0;
				}
				reset_start_position(pieces[k]);
				return (0);
			}
			k++;
		}
	}
	return (1);
}

void		generate(t_piece **pieces, unsigned int cnt)
{
	unsigned int	size;
	t_map			*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->count = cnt;
	size = 0;
	map->tab = (int**)malloc(sizeof(int*) * cnt * 5);
	while (size < cnt * 5)
	{
		*(map->tab + size) = (int*)malloc(sizeof(int) * cnt * 4);
		ft_memset(map->tab[size], 0, sizeof(int) * cnt * 4);
		size++;
	}
	map->size = set_size(cnt);
	while (!back(map, pieces, 0))
		map->size++;
	print_map(map);
}
