/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 20:12:39 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/10 18:51:37 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *heystack, const char *needle)
{
	int j;

	if (ft_strlen(needle) == 0)
		return ((char *)heystack);
	while (*heystack)
	{
		j = 0;
		if (*heystack == needle[j])
		{
			while (needle[j] && needle[j] == *(heystack + j))
				j++;
			if (needle[j] == '\0')
				return ((char *)heystack);
		}
		heystack++;
	}
	return (NULL);
}
