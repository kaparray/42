/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaparray <kaparray@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 16:11:52 by hpowlows          #+#    #+#             */
/*   Updated: 2018/12/19 02:03:51 by kaparray         ###   ########.fr       */
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
    else if (t1 == 3 && t2 == 1 && t3 == 3)
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

int		type_of_tetramino(int i)
{
    int t1;
    int t2;
    int t3;

    t3 = g_ttr.arr[3] - g_ttr.arr[2];
    t2 = g_ttr.arr[2] - g_ttr.arr[1];
    t1 = g_ttr.arr[1] - g_ttr.arr[0];
    if (equ_tetramino_1(t1, t2, t3, i))
        return (1);
    else if (equ_tetramino_2(t1, t2, t3, i))
        return (1);
    else
        return (0x0);
    return (1);
}

int		is_tetramino(int j)
{

    if (type_of_tetramino(j) == 0x0)
    {
        return (0);
    }
    return (1);
}

int		checker(char *ttr, int j)
{
    int		i;
    int		cnt;

    i = 0;
    cnt = -1;
    while (ttr[i])
    {
        if (ttr[i] == TR)
            g_ttr.arr[++cnt] = i;
        i++;
    }
    return (is_tetramino(j));
}

int		valid(char *ttr, int j)
{
    int		i;
    int		len;
    int		cnt;

    if (ttr[0] == '\0')
        return (1);
    i = -1;
    len = 0;
    cnt = 0;
    while (ttr[++i])
    {
        if (ttr[i] == TR)
            cnt++;
        else if (ttr[i] == '.')
            len++;
        else
            return (0);
    }
    if (cnt == 4 && len == 12)
        return (checker(ttr, j));
    return (0);
}


int     tetra_separator(char *ttr, int normal)
{
    int i;
    unsigned int cnt1;
    int cnt;

    cnt = 0;
    cnt1 = 0;
    i = 0;
    while (normal / 4 * 4 > cnt1)
    {
        printf("%s     %d   %d\n", ft_strsub(ttr, cnt1, 16), cnt1, 16);
        if (valid(ft_strsub(ttr, cnt1, 16), i) == 1)
        {
            i++;
            cnt += 16;
            g_lstttr.len++;
        }
        cnt1 += 16;

    }
    if (cnt == normal / 4 * 4)
        return (1);
    return (0x0);
}


int		separator(char *ttr, int normal)
{
    char *tempo;
    char *ttr2;

    ttr2 = ft_strnew(1);
    tempo = ttr2;
    while (*ttr)
    {
        if	(*ttr != '\n')
        {
            *tempo = *ttr;
            tempo++;
        }
        ttr++;
    }
    *tempo = '\0';
    return (tetra_separator(ttr2, normal));
}



int		start_validation(char *ttr)
{
    int normal;
    int i;
    int cnt;

    i = 1;
    cnt = 0;
    normal = 0;

    while (ft_strlen(ttr) > cnt)
    {

        if (ttr[cnt] == '#' || ttr[cnt] == '.' )
            normal++;
        else if (ttr[cnt] == '\n' && ttr[1 + cnt] == '\n')
            i++;
        cnt++;
    }
//    if (ttr[0] == '\n' || ttr[cnt - 1] != '\n')
//        return (0x0);
//    if (normal % 16 == 0 && normal / 16 == i)
//        return (separator(ttr, normal));
//    return (0x0);
    if (ttr[0] == '\n' || ttr[cnt - 1] != '\n')
        return (0x0);
    else
        return (separator(ttr, normal));
}
