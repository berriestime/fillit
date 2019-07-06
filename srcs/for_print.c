/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:46:14 by selly             #+#    #+#             */
/*   Updated: 2019/07/06 17:03:31 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int			hor_begin(int size, int step)
{
	int		i;
	int		b;
	int		m;

	i = 0;
	b = 0;
	m = 0;
	while (m < step)
	{
		if (i < (size - 2) + b - 1)
		{
			m++;
			i++;
		}
		else
		{
			i += 3;
			b += size;
			m++;
		}
	}
	return (i);
}

int			hor_e(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
		return (-2);
	i = hor_begin(size, step);
	if (c == 12)
		len = check_e(&(*line), i, 1, size);
	if (c == 13)
	{
		i += size;
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
			if (len == 2)
				i -= size;
			else
				i++;
		}
	}
	return (len == 0 ? 1 : -1);
}

int			vert_e(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	if (step >= (size - 1) * (size - 2))
		return (-2);
	i = square_begin(size, step);
	tetr = *line;
	len = 4;
	if (c == 14)
		len = check_e(&(*line), i + 1, size, -1);
	if (c == 15)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
			if (len == 2)
				i++;
			else
				i += size;
		}
	}
	return (len == 0 ? 1 : -1);
}

int			hor_f(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	if (step >= (size - 1) * (size - 2))
		return (-2);
	tetr = *line;
	len = 4;
	i = hor_begin(size, step);
	if (c == 16 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = '#';
		len--;
	}
	if (c == 17 && tetr[i + 1] == '.')
	{
		tetr[i + 1] = '#';
		len--;
		i += size;
	}
	if (len == 3)
		len = check_place(&(*line), i, c, 1);
	return (len == 0 ? 1 : -1);
}
