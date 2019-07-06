/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:03:34 by dmorrige          #+#    #+#             */
/*   Updated: 2019/07/06 12:38:50 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "figures.h"

int			square(int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		b;

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
			i += size - 1;
		else
			i++;
		b--;
	}
	return (b == 0 ? 1 : -1);
}

int			square_begin(int size, int step)
{
	int		i;
	int		b;
	int		m;

	i = 0;
	b = 0;
	m = 0;
	while (m < step)
	{
		if (i < (size - 1) + b - 1)
		{
			m++;
			i++;
		}
		else
		{
			i = i + 2;
			b += size;
			m++;
		}
	}
	return (i);
}
