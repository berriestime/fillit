/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:45:55 by selly             #+#    #+#             */
/*   Updated: 2019/06/26 15:30:55 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int     remove_alpha(char **dest, char **line, int i)
{
	char *alpha;
	char *buf;
	char *buf_dest;
	
	alpha = "ABCDEFGHIGHIJKLMNOPQRSTUVWXYZ";
	buf = *line;
	buf_dest = *dest;
	while (*buf)
	{
		if (*buf == alpha[i])
			*buf = '.';
		buf++;
	}
	ft_strcpy(buf_dest, *line);
	return (last_step(i, 1, 0) + 1);
}

int     last_step(int a, int flag, int step)
{
	static int steps[26];

	if (flag == 0)
		steps[a] = step;
	if (flag == 1)
		return (steps[a]);
	return (1);
}

int		line_begin(int c, int size, int step)
{
	int		i;
	int		m;
	int		a;

	i = 0;
	m = 0;
	a = size - 4;
	while (m < step)
	{
		if (c == 1)
			i++;
		if (c == 2)
		{
			if (i < a)
				i++;
			else
			{
				i = i + size - (size - 4);
				a += size;
			}
		}
		m++;
	}
	return (i);
}

int		do_step(char **line, char **solve, int step)
{
	// char *tmp;

	// tmp = *solve;
	// tmp = ft_strcpy(*line, *solve);
	ft_strcpy(*line, *solve);
	return (++step);
}

void	output(char *s, int size)
{
	int i;
	int n;

	i = 0;
	n = size;
	while (s[i] && i < size * size)
	{
		if (i < n)
		{
			ft_putchar(s[i]);
			i++;
		}
		else
		{
			ft_putchar('\n');
			n = n + size;
		}
	}
	ft_putchar('\n');
}
