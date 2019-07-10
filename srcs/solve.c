/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:10:36 by selly             #+#    #+#             */
/*   Updated: 2019/07/08 17:46:05 by selly            ###   ########.fr       */
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

int			line_tetr(int *figures, char **solution, int size, char **buff)
{
	int		i;
	int		step;
	int		flag;
	int		max_tetrs;

	i = 0;
	step = 0;
	max_tetrs = count_tetr(figures);
	while (i < max_tetrs)
	{
		if ((flag = figura(figures[i], size, step, &(*buff))) == 1)
			step = fill_position(&i, step, &(*solution), &(*buff));
		else if (flag == -1)
			step = do_step(&(*buff), &(*solution), step);
		else if (flag == -2)
		{
			if (i != 0)
				step = remove_alpha(&(*solution), &(*buff), --i);
			else
				return (-1);
		}
	}
	return (1);
}

void		solve(int *figures, int size_square)
{
	char	*solution;
	int		flag;
	char	*buff;

	flag = 0;
	if (!(solution = ft_strnew(size_square * size_square)))
		ft_invalid_tetr();
	if (!(buff = ft_strnew(size_square * size_square)))
		ft_invalid_tetr();
	ft_memset(solution, '.', size_square * size_square);
	ft_memset(buff, '.', size_square * size_square);
	flag = line_tetr(figures, &solution, size_square, &buff);
	if (flag < 0)
	{
		ft_strdel(&solution);
		ft_strdel(&buff);
		solve(figures, (size_square + 1));
	}
	else
	{
		output(solution, size_square);
		ft_strdel(&solution);
		ft_strdel(&buff);
	}
}
