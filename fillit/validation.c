/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/21 22:47:43 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"


int		test_3(char *s)
{
	int i;
	int hash;
	int point;
	int endline;

	i = 0;
	hash = 0;
	point = 0;
	endline = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#')
			hash++;
		if (s[i] == '.')
			point++;
		if (s[i] == '\n')
			endline++;
		if (s[i] != '#' && s[i] != '.' && s[i] != '\n')
			return (0);
		i++;
	}
	if (hash != 4 || point != 12 || endline != 4)
		return (0);
	return (1);
}

int		test_2(char *s)
{
	int i;
	int j;
	int add_5;

	i = 0;
	j = 0;
	add_5 = 4;
	while (s[i] != '\0')
	{
		if (s[i] == '.' || s[i] == '#')
			j++;
		if (j > 4)
			return (0);
		if (s[i] == '\n' && i == add_5)
		{
			j = 0;
			add_5 += 5;
		}
		i++;
	}
	return (1);
}

int		test_1(char *s)
{
	int i;
	char *a;

	i = 0;
	if (s[i] != '.' && s[i] != '#')
		return (0);
	while (s[i])
	{
		a = ft_strsub(s, i, 20);
		if (test_3(a) == 0 && test_2(a) == 0)
			return (0);
		i += 21;
	}
	printf("%d       %d      %d\n", s[i - 2], s[i - 1], s[i]);
	if (s[i] == '\0' && s[i - 1] == '\n' && (s[i - 2] == '#' || s[i - 2] == '.'))
		return (1);
	else
		return (0);
	return (1);
}
