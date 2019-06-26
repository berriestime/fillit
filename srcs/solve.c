/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:10:36 by selly             #+#    #+#             */
/*   Updated: 2019/06/26 15:25:51 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

char		*fill_alpha(char *dest, char **line, int i)
{
	char	*alpha;
	char	*buf;

	alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	buf = *line;
	while (*buf)
	{
		if (*buf == '#')
			*buf = alpha[i];
		buf++;
	}
	return (ft_strcpy(dest, *line));
}

int			count_tetr(int *c)
{
	int		i;

	i = 0;
	while (c[i] > 0 && c[i] < 20)
		i++;
	return (i);
}

int			full_solution(char **line, char **solve, int *i)
{
	int		*tmp_i;

	tmp_i = i;
	*solve = fill_alpha(*solve, *(&line), *i);
	*tmp_i += 1;
	return (0);
}

int			line_tetr(int *c, char **solve, int size, int step)
{
	int		i;
	char	*line;
	int		n;
	int		m;

	i = 0;
	n = 0;
	if (!(line = ft_strnew(size * size)))
		return (-3);
	ft_memset(line, '.', size * size);
	m = count_tetr(c);
	while (i < m)
	{
		if ((n = figura(c[i], size, step, &line)) == 1)
		{
			step = last_step(i, 0, step);
			step = full_solution(&line, &(*solve), &i);
		}
		else if (n == -1)
			step = do_step(&line, &(*solve), step);
		else if (n == -2)
		{
			if (i != 0)
			{
				i--;
				step = remove_alpha(&(*solve), &line, i);
			}
			else
			{
				free(line);
				return (-1);
			}
		}
	}
	return (1);
}

void		tetr_line(int *c, int size, int step)
{
	char	*solve;
	int		test;

	test = 0;
	if (!(solve = ft_strnew(size * size)))
		return ;
	ft_memset(solve, '.', size * size);
	test = line_tetr(c, &solve, size, step);
	if (test < 0)
	{
		free(solve);
		solve = NULL;
		tetr_line(c, (size + 1), 0);
	}
	else
	{
		output(solve, size);
		free(solve);
		solve = NULL;
	}
}
