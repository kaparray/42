/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 21:46:02 by hpowlows          #+#    #+#             */
/*   Updated: 2018/11/20 16:58:53 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int f;

	f = 1;
	if (nb < 0 || nb > 12)
		f = 0;
	else if (nb > 1)
		while (nb > 1)
			f *= nb--;
	else if (nb == 1 || nb == 0)
		f = 1;
	return (f);
}
