/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figura.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:20:33 by selly             #+#    #+#             */
/*   Updated: 2019/07/08 17:42:15 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figures.h"
#include "tetriminos.h"

int			fill_position(int *i, int step, char **solution, char **buff)
{
	step = last_step(*i, 0, step);
	return (full_solution(&(*buff), &(*solution), &(*i)));
}

int			hor_g(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
		return (-2);
	i = hor_begin(size, step);
	if (c == 8 || c == 9)
		len = check_horg(c, size, i, &(*line));
	if (c == 10)
	{
		i = check_horg(c, size, i, &(*line));
		len--;
	}
	if (c == 11 && tetr[i + 2] == '.')
	{
		tetr[i + 2] = '#';
		len--;
		i += size;
	}
	if (len == 3 && i > -1)
		len = check_place(&(*line), i, c, 1);
	return (len == 0 ? 1 : -1);
}

int			vert_g(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
		return (-2);
	i = square_begin(size, step);
	if (c == 4 || c == 6)
		len = check_vertg(c, size, i, &(*line));
	if (c == 5 && tetr[i] == '.')
	{
		tetr[i++] = '#';
		len--;
	}
	if (c == 7 && tetr[i + size * 2] == '.')
	{
		tetr[i + size * 2] = '#';
		i++;
		len--;
	}
	if (len == 3)
		len = check_place(&(*line), i, c, size);
	return (len == 0 ? 1 : -1);
}

int			line_type(int c, int size, int step, char **line)
{
	int		i;
	int		len;

	i = 0;
	len = 4;
	if ((c == 1 || c == 2) && step > (size - 4 + 1) * size)
		return (-2);
	i = line_begin(c, size, step);
	if (c == 1)
		len = check_place(&(*line), i, c, size);
	if (c == 2)
		len = check_place(&(*line), i, c, 1);
	return (len == 0 ? 1 : -1);
}

int			figura(char tetr, int size_square, int step, char **buff)
{
	int		res;

	res = 0;
	if (tetr == 1 || tetr == 2)
		res = line_type(tetr, size_square, step, &(*buff));
	if (tetr == 3)
		res = square(size_square, step, &(*buff));
	if (tetr > 3 && tetr < 8)
		res = vert_g(tetr, size_square, step, &(*buff));
	if (tetr > 7 && tetr < 12)
		res = hor_g(tetr, size_square, step, &(*buff));
	if (tetr == 12 || tetr == 13)
		res = hor_e(tetr, size_square, step, &(*buff));
	if (tetr == 14 || tetr == 15)
		res = vert_e(tetr, size_square, step, &(*buff));
	if (tetr == 16 || tetr == 17)
		res = hor_f(tetr, size_square, step, &(*buff));
	if (tetr == 18 || tetr == 19)
		res = vert_f(tetr, size_square, step, &(*buff));
	return (res);
}
