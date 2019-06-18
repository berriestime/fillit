/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figura.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:45:26 by selly             #+#    #+#             */
/*   Updated: 2019/06/18 17:27:08 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int		hor_g(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
		return (-2);
	i = hor_begin(size, step);
	if (c == 8 && tetr[i + size] == '.')
	{
		tetr[i + size] = '#';
		len--;
	}
	if (c == 9 && tetr[i + size + 2] == '.')
	{
		tetr[i + size + 2] = '#';
		len--;
	}
	if (c == 10 && tetr[i] == '.')
	{
		tetr[i] = '#';
		len--;
		i += size;
	}
	if (c == 11 && tetr[i + 2] == '.')
	{
		tetr[i + 2] = '#';
		len--;
		i += size;
	}
	if (len == 3)
	{
		 while (tetr[i] && len)
                {
                        if (tetr[i] == '.')
                                tetr[i] = '#';
                        else
                                return (-1);
                        i++;
                        len--;
                }
                return (1);

	}
	return (-1);
}

int	vert_g(int c, int size, int step, char **line)
{
	char	*tetr;
	int	i;
	int	len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
                return (-2);
	i = square_begin(size, step);
	if (c == 4 && tetr[i + 1] == '.')
	{
		tetr[i + 1] = '#';
		len--;
	}
	if (c == 5 && tetr[i] == '.')
	{
		tetr[i++] = '#';
		len--;
	}
	if (c == 6 && tetr[i + 2 * size + 1] == '.')
	{
		tetr[i + 2 * size + 1] = '#';
		len--;
	}
	if (c == 7 && tetr[i + size * 2] == '.')
	{
		tetr[i + size * 2] = '#';
		i++;
		len--;
	}
	if (len == 3)
	{
		while (tetr[i] && len)
		{
			if (tetr[i] == '.')
				tetr[i] = '#';
			else
				return (-1);
			i += size;
			len--;
		}
		return (1);
	}
	return (-1);
}

int	square(int size, int step, char **line)
{
	char *tetr;
	int	i;
	int	b;

	tetr = *line;
	i = 0;
	if (step > (size - 1) * (size - 1))
	 return (-2);
	i = square_begin(size, step);
	b = 4;
	while (tetr[i] && b)
	{
		if (tetr[i] == '.')
			tetr[i] = '#';
		else
			return (-1);
		if (b == 3)
			i +=size - 1;
		else
			i++;
		b--;
	}
	if (b == 0)
		return (1);
	return (-1);
}

int    line_type(int c, int size, int step, char **line)
{
	char *tetron;
	int i;
	int len;
	
	i = 0;
	max_step(c, step, size) == 1 ? return (-2) : len = 4;
	tetron = *line;
	i = line_begin(c, size, step);
    if (c == 1)
    {
        while (tetron[i] == '.' && len)
         {
			 tetron[i] = '#';
			 i += size;
			 len--;
		 } 
    }
    if (c == 2)
    {
        while (len && tetron[i] == '.')
		{
			tetron[i] = '#';
			i++;
			len--;
		}
	}
	if (len == 0)
		return (1);
    return (-1);
}

int figura(char c, int size, int step, char **line)
{
	int a;
	
	a = 0;
	if (c == 1 || c == 2)
		a = line_type(c, size, step, &(*line));
	if (c == 3)
		a = square(size, step, &(*line));
	if (c > 3 && c < 8)
		a =  vert_g(c, size, step, &(*line));
	if (c > 7 && c < 12)
		a = hor_g(c, size, step, &(*line));
	if (c == 12 || c == 13)
		a = hor_e(c, size, step, &(*line));
	if (c == 14 || c == 15)
		a = vert_e(c, size, step, &(*line));
	if (c == 16 || c == 17)
		a = hor_f(c, size, step, &(*line));
	if (c == 18 || c == 19)
		a = vert_f(c, size, step, &(*line));
	if (c < 0 && c > 19)
		return (-1);
	return (a);
}