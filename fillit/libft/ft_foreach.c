/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:11:00 by hpowlows          #+#    #+#             */
/*   Updated: 2018/11/29 20:04:44 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_foreach(int *tab, unsigned int length, void (*f)(int))
{
	if (tab == NULL || f == NULL)
		return ;
	while (length--)
		f(*tab++);
}
