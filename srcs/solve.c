/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:10:36 by selly             #+#    #+#             */
/*   Updated: 2019/07/06 18:11:33 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

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

int			count_tetr(int *figures)
{
	int		i;

	i = 0;
	while (figures[i] > 0 && figures[i] < 20)
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

int			line_tetr(int *figures, char **solution, int size, int step)
{
	int		i;
	char	*buff;
	int		flag;
	int		max_tetrs;

	i = 0;
	flag = 0;
	if (!(buff = ft_strnew(size * size)))
		ft_invalid_tetr();
	ft_memset(buff, '.', size * size);
	max_tetrs = count_tetr(c);
	while (i < max_tetrs)
	{
		if ((flag = figura(c[i], size, step, &buff)) == 1)
		{
			step = last_step(i, 0, step);
			step = full_solution(&buff, &(*solve), &i);
		}
		else if (flag == -1)
			step = do_step(&buff, &(*solve), step);
		else if (flag == -2)
		{
			if (i != 0)
			{
				i--;
				step = remove_alpha(&(*solve), &buff, i);
			}
			else
			{
				free(buff);
				return (-1);
			}
		}
	}
	return (1);
}

void		solve(int *figures, int size_square, int step)
{
	char	*solution;
	int		flag;

	flag = 0;
	if (!(solution = ft_strnew(size_square * size_square)))
		ft_invalid_tetr();
	ft_memset(solution, '.', size_square * size_square);
	flag = line_tetr(figures, &solution, size_square, step);
	if (flag < 0)
	{
		free(solve);
		solve = NULL;
		solve(figures, (size + 1), 0);
	}
	else
	{
		output(solution, size);
		free(solution);
		solve = NULL;
	}
}
