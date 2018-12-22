/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpowlows <hpowlows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/22 23:58:03 by hpowlows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"



int		equ_tetramino_1(int t1, int t2, int t3, int i)
{
    if (t1 == 3 && t2 == 1 && t3 == 1)
        g_lstttr.arr[i] = T1;
    else if (t1 == 1 && t2 == 1 && t3 == 3)
        g_lstttr.arr[i] = T2;
    else if (t1 == 3 && t2 == 1 && t3 == 4)
        g_lstttr.arr[i] = T3;
    else if (t1 == 4 && t2 == 1 && t3 == 3)
        g_lstttr.arr[i] = T4;
    else if (t1 == 4 && t2 == 4 && t3 == 4)
        g_lstttr.arr[i] = T5;
    else if (t1 == 1 && t2 == 1 && t3 == 1)
        g_lstttr.arr[i] = T6;
    else if (t1 == 1 && t2 == 3 && t3 == 1)
        g_lstttr.arr[i] = T7;
    else if (t1 == 1 && t2 == 2 && t3 == 1)
        g_lstttr.arr[i] = T8;
    else if (t1 == 1 && t2 == 4 && t3 == 1)
        g_lstttr.arr[i] = T9;
    else if (t1 == 4 && t2 == 1 && t3 == 4)
        g_lstttr.arr[i] = T10;
    else
        return (0);
    return (1);
}

int		equ_tetramino_2(int t1, int t2, int t3, int i)
{
    if (t1 == 3 && t2 == 1 && t3 == 3)
        g_lstttr.arr[i] = T11;
    else if (t1 == 4 && t2 == 4 && t3 == 1)
        g_lstttr.arr[i] = T12;
    else if (t1 == 2 && t2 == 1 && t3 == 1)
        g_lstttr.arr[i] = T13;
    else if (t1 == 4 && t2 == 3 && t3 == 1)
        g_lstttr.arr[i] = T14;
    else if (t1 == 4 && t2 == 4 && t3 == 1)
        g_lstttr.arr[i] = T15;
    else if (t1 == 1 && t2 == 1 && t3 == 2)
        g_lstttr.arr[i] = T16;
    else if (t1 == 1 && t2 == 1 && t3 == 4)
        g_lstttr.arr[i] = T17;
    else if (t1 == 1 && t2 == 4 && t3 == 4)
        g_lstttr.arr[i] = T18;
    else if (t1 == 1 && t2 == 3 && t3 == 4)
        g_lstttr.arr[i] = T19;
    else
        return (0);
    return (1);
}

char	*separator(char *ttr)
{
    char	*tempo;
    char	*ttr2;

    ttr2 = ft_strnew(1);
    tempo = ttr2;
    while (*ttr)
    {
        if (*ttr != '\n')
        {
            *tempo = *ttr;
            tempo++;
        }
        ttr++;
    }
    *tempo = '\0';
    return (ttr2);
}

int		find_xyz(char *s, int k)
{
    int i;
    int j;

    i = 1;
    j = -1;
    if (s == NULL)
        return (1);
    while (s[i])
    {
        if (s[i] == '#')
            g_ttr[++j] = i;
        i++;
    }
    if (equ_tetramino_1(g_ttr[1] - g_ttr[0], g_ttr[2] - g_ttr[1], g_ttr[3] - g_ttr[2], k) == 1)
        return (1);
    if (equ_tetramino_2(g_ttr[1] - g_ttr[0], g_ttr[2] - g_ttr[1], g_ttr[3] - g_ttr[2], k) == 1)
        return (1);
    return (0);
}

int		valid_figure(char *s)
{
    int i;
    char *tmp;
    int k;

    k = 0;
    s = separator(s);
    i = 0;
    while (s[i])
    {
        tmp = ft_strsub(s, i, 16);
        if (!find_xyz(tmp, k))
            return (0);
        i += 16;
        k++;
    }
    return (1);
}



int		test_4(char *s)
{
    int len;

    len = (int)ft_strlen(s);
    if ((s[len - 1] == '\n' && s[len - 2] == '.') || (s[len - 2] == '#' && s[len - 1] == '\n'))
        return (1);
    else
        return (0);
}

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
    while (s[i - 1])
    {
        a = ft_strsub(s, i, 20);
        if (test_3(a) == 0 || test_2(a) == 0)
            return (0);
        i += 21;
    }
    if (test_4(s) == 0)
        return (0);
    return (1);
}

int		validation(char *s)
{
    if (test_1(s) == 0)
        return (0);
    if (valid_figure(s) == 0)
        return (0);
    return (1);
}

