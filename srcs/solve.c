/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:45:10 by selly             #+#    #+#             */
/*   Updated: 2019/06/18 16:54:47 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

char    *fill_alpha(char *dest, char **line, int i)
{
    char *alpha;
    char *buf;

    alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    buf = *line;
    while (*buf)
    {
        if (*buf == '#')
            *buf = alpha[i];
        buf++;
    }
    return(ft_strcpy(dest, *line));
}

int     count_tetr(int *c)
{
    int i;

    i = 0;
    while (c[i] > 0 && c[i] < 20)
        i++;
    return (i);
}
int     line_tetr(int *c, char **solve, int size, int step)
{
    int i;
    char *line;
    char *buf;
    int n;
    int m;

    i = 0;
    n = 0;
    if (!(line = (char *)malloc(sizeof(char) * (size * size) + 1)))
     return (-3);
    ft_memset(line, '.', size * size);
    line[size * size] = '\0';
    m = count_tetr(c);
    while (i < m)
    {
		if((n = figura(c[i], size, step, &line)) == 1)
		{       
            
			*solve = fill_alpha(*solve, &line, i);
            step = 0;
            i++;
		}
		else if (n == -1)
        {
            line = ft_strcpy(line, *solve);
			step++;
        }
		else if (n == -2)
        {
            free(line);
            return(-1);
        }
    }
    return (1);
}

void    tetr_line(int *c, int size, int step)
{
    char *solve;
    int     test;

    test = 0;
    if (!(solve = (char *)malloc(sizeof(char) * (size * size + 1))))
     return ;
    ft_memset(solve, '.', size * size);
    solve[size * size] = '\0';
    test = line_tetr(c, &solve, size, step);
    if (test < 0)
    {
        free(solve);
        tetr_line(c, (size + 1), 0);
    }
    else
    {
        output(solve, size);
        free(solve);
    }
}
