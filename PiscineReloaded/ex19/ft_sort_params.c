/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:07:50 by hpowlows          #+#    #+#             */
/*   Updated: 2018/11/20 18:10:31 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int		ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char*)s1 - *(const unsigned char*)s2);
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	char*tmp;

	i = 0;
	while (i < (argc))
	{
		j = i + 1;
		while (j < (argc))
		{
			(ft_strcmp(argv[i], argv[j]) > 0) && (tmp = argv[i])
				&& (argv[i] = argv[j])
				&& (argv[j] = tmp);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < argc)
	{
		ft_print(argv[i]);
		i++;
	}
	return (0);
}
