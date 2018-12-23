/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheacker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 17:15:15 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/23 17:31:41 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_piece_check(char *str, int h, int nl, int d)
{
	int i;

	i = 0;
	while (str[i] == 0x7e || str[i] == 0x2e || str[i] == 0x0a)
	{
		(str[i] == 0x7e) ? h++ : h;
		(str[i] == 0x2e) ? d++ : d;
		(str[i] == 0x0a) ? nl++ : nl;
		if (i + 1 == 21)
			if (str[i] != 0x0a)
				return (0);
		i++;
	}
	return (((h % 4 == 0) && ((nl + 1) % 5 == 0) && (d % 12 == 0)
		&& (i + 1) % 21 == 0) ? 1 : 0);
}

int		ft_island_check()
{

}
