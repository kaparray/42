/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_generation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaparray <kaparray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 18:40:08 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/24 11:38:36 by kaparray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_pickup(char *map, int c, int i)
{
	while (map[++i])
		map[i] = (map[i] == c) ? 0x2e : map[i];
}

int		ft_drop_check(char *str, char letter, int x)
{
	int d;
	int	i;

	i = -1;
	d = 0;
	while (str[++i])
		if (str[i] == letter)
		{
			(str[i - 1] && (str[i - 1] == letter)) ? d++ : d;
			(str[i + 1] && (str[i + 1] == letter)) ? d++ : d;
			(str[i - x - 1] && (str[i - x - 1] == letter)) ? d++ : d;
			(str[i + x + 1] && (str[i + x + 1] == letter)) ? d++ : d;
		}
	return ((d == 6 || d == 8) ? 1 : 0);
}

int		ft_drop(char *str, char *new, int i)
{
	int		x;
	int		j;
	char	letter;

	j = 0;
	x = 0;
	while (str[x] != 0x0a && str[x])
		x++;
	letter = new[j];
	while (new[j])
	{
		if (!str[i] && x != 3)
			break ;
		(new[j] == 0x0a && x == 3) ? i-- : i;
		(new[j] == 0x0a && x != 4 && x != 3) ? i += (x - 4) : i;
		str[i] = (str[i] == 0x2e && new[j] > 64) ? new[j] : str[i];
		i++;
		j++;
	}
	return (ft_drop_check(str, letter, x) ? 1 : 0);
}

int		ft_solver(char *map, char **pieces, int i)
{
	if (!pieces[0])
		return (1);
	while (pieces[0] && pieces[0][0] < 64)
		pieces[0]++;
	while (map[++i])
	{
		if (ft_drop(map, *pieces, i) != 1 || (!ft_solver(map, &pieces[1], -1)))
			ft_pickup(&map[i], *pieces[0], -1);
		else
			return (1);
	}
	return (0);
}

void	ft_map_gnrtion(char *map, char **pieces, int x, int size)
{
	while (1)
	{
		x = -1;
		while (++x < (size * (size + 1)))
			map[x] = (x % (size + 1) == size) ? 0x0a : 0x2e;
		map[x] = 0x0a;
		if (!ft_solver(map, pieces, -1))
		{
			size++;
			map = ft_strnew(size * (size + 5));
		}
		else
		{
			ft_putstr(map);
			exit(0);
		}
	}
}
