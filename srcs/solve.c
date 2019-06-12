/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:45:10 by selly             #+#    #+#             */
/*   Updated: 2019/06/12 16:47:39 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	figura(char c, int size, int *step, char **line);
void	output(char *s, int size);

 void    *ft_memset(void *s, int c, size_t n)
{
	while (n-- != 0)
		((unsigned char *)s)[n] = (unsigned char)c;
	return (s);
}

char    *ft_strcpy(char *dest, char *src)
{
	unsigned int index;
	
	index = 0;
	while (src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = src[index];
	return (dest);
}

int     line_tetr(int c, char **solve, int size, int *step)
{
    int i;
    char *line;
	int		n; //number of tetr

    i = 0;
    if (!(line = (char *)malloc(sizeof(char) * (size * size) + 1)))
     return (-3);
    ft_memset(line, '.', size * size);
    line[size * size] = '\0';
   // i = figura(c, size, &(*step), &line);
   	output(line, size);
    /*
    while (i < size)
    {
		if((figura(c[i], size, &(*step), &line) = n) > 0)
		{
			*solve = ft_strcpy(*solve, line);
		}
		else if (n == -2)

    }
    free(line);
    step = 0;*/
    return (1);
}

int     find_solution(char **solve, int *c, int size)
{
    int     i;
    int     step;
    int     test;

    i = 0;
    step = 10;
    test = 0;
    test = line_tetr(c[0], &(*solve), size, &step);
    return (0);
    /*
    while (i < size)
    {
        if (test = line_tetr(c[i], solve, size, &step) && step == 0)
         i++;
        else if (step > 0)
        {
            while (step > 0)
                test = line_tetr(c[i], solve, size, &step);
            if (!test && i != 0)
            {
                i--;
                step = 0;
            }
            else
             i++;
        }
        else
            return (-1);
    }
    return (1);*/
}

void    tetr_line(int *c, int size)
{
    char *solve;

    if (!(solve = (char *)malloc(sizeof(char) * (size * size + 1))))
     return ;
    ft_memset(solve, '.', size * size);
    solve[size * size] = '\0';
    //printf("%s solve \n", solve);
    int a = find_solution(&solve, c, size);
    /*
    if (!(find_soluton(&solve, c, size)))
    {
        free(solve);
        tetr_line(c, (size + 1));
    }
    else
    {
        get_solution(solve, size);
        free(solve);
    }*/
}

int	main(void)
{
	int tetr[3] = {2, 1, 10};
	int i = 0;
	while (i < 3)
		printf("%d\n", tetr[i++]);
	printf("--------\n");
	tetr_line(tetr, 5);
	return (0);
}
