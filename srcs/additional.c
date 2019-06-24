/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:08:42 by selly             #+#    #+#             */
/*   Updated: 2019/06/24 15:12:05 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int			check_place(char **tetr, int i, int type, int step)
{
	char	*tmp;
	int		len;

	len = 4;
	type == 1 || type == 2 ? len : len--;
	tmp = *tetr;
	while (len && tmp[i] == '.')
	{
		tmp[i] = '#';
		i += step;
		len--;
	}
	return (len);
}

int			check_vertg(int c, int size, int i, char **line)
{
	char	*tetr;
	int		len;

	len = 4;
	tetr = *line;
	if (c == 4 && tetr[i + 1] == '.')
	{
		tetr[i + 1] = '#';
		len--;
	}
	if (c == 6 && tetr[i + 2 * size + 1] == '.')
	{
		tetr[i + 2 * size + 1] = '#';
		len--;
	}
	return (len);
}

int			check_e(char **line, int i, int step1, int step2)
{
	char	*tetr;
	int		len;

	len = 4;
	tetr = *line;
	while (tetr[i] == '.' && len)
	{
		tetr[i] = '#';
		len--;
		if (len == 2)
			i += step2;
		else
			i += step1;
	}
	return (len);
}

int			check_horg(int c, int size, int i, char **line)
{
	char	*tetr;
	int		len;

	len = 4;
	tetr = *line;
	if (c == 8 && tetr[i + size] == '.')
	{
		tetr[i + size] = '#';
		return (--len);
	}
	if (c == 9 && tetr[i + size + 2] == '.')
	{
		tetr[i + size + 2] = '#';
		return (--len);
	}
	if (c == 10 && tetr[i] == '.')
	{
		tetr[i] = '#';
		len--;
		i += size;
		return (i);
	}
	return (-1);
}

int			vert_f(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	if (step >= (size - 1) * (size - 2))
		return (-2);
	tetr = *line;
	len = 4;
	i = square_begin(size, step);
	if (c == 18 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = '#';
		len--;
	}
	if (c == 19 && tetr[i + size] == '.')
	{
		tetr[i + size] = '#';
		len--;
		i++;
	}
	if (len == 3)
		len = check_place(&(*line), i, c, size);
	return (len == 0 ? 1 : -1);
}
