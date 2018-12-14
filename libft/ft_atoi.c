/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 19:17:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/11/30 19:40:56 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	long long int		num;
	char				neg;

	num = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	neg = str[0];
	str += (neg == '-' || neg == '+') ? 1 : 0;
	while (*str >= '0' && *str <= '9')
		if ((unsigned long long)\
				(num = num * 10 + (*str++ - 48)) >= 0x7fffffffffffffff)
			return (-1 + (neg == '-'));
	return ((int)((neg == '-') ? -num : num));
}
