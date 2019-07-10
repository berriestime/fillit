/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:07:15 by selly             #+#    #+#             */
/*   Updated: 2019/07/10 18:43:10 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		type_f(char *s, int i, int l, int type_tetr)
{
	int		st;

	st = 1;
	if (s[i + 1] == '#' && s[i + 6] == '#')
		type_tetr = 16;
	if (s[i + 5] == '#' && s[i + 4] == '#' && s[i + 6] == '#')
	{
		type_tetr = 17;
		i += 4;
	}
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 4] == '#')
	{
		type_tetr = 19;
		st = 5;
	}
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 6] == '#')
	{
		type_tetr = 18;
		st = 5;
	}
	l = check_symbol(s, 3, st, i);
	return (l == 0 ? type_tetr : -1);
}

int		type_d(char *s, int i, int line, int type_tetr)
{
	if (s[i + 5] == '#' && s[i + 1] == '#')
		type_tetr = 8;
	if (s[i + 7] == '#' && s[i + 1] == '#')
		type_tetr = 9;
	if (s[i + 5] == '#' && s[i + 7] == '#')
	{
		i += 5;
		type_tetr = 10;
	}
	if (s[i + 3] == '#' && s[i + 5] == '#')
	{
		i += 3;
		type_tetr = 11;
	}
	line = check_symbol(s, 3, 1, i);
	if (line == 0)
		return (type_tetr);
	return (-1);
}

int		type_c(char *str, int i, int line, int type_tetr)
{
	if (str[i + 1] == '#' && str[i + 10] == '#')
		type_tetr = 4;
	if (str[i + 5] == '#' && str[i + 11] == '#')
		type_tetr = 6;
	if (str[i + 1] == '#' && str[i + 11] == '#')
	{
		i++;
		type_tetr = 5;
	}
	if (str[i + 9] == '#' && str[i + 5] == '#')
		type_tetr = 7;
	line = check_symbol(str, 3, 5, i);
	if (line == 0)
		return (type_tetr);
	return (-1);
}

int		type_b(char *str, int i, int line)
{
	if (i >= 0 && i < 13)
	{
		while (str[i] == '#')
		{
			line--;
			i++;
		}
		if (line == 2)
		{
			i += 3;
			while (str[i++] == '#')
				line--;
		}
	}
	if (line == 0)
		return (3);
	return (-1);
}

int		type_a(char *str, int i, int line, int buf)
{
	buf = i;
	if (i >= 0 && i < 4)
	{
		while (str[i] == '#' && i < 19)
		{
			line--;
			i += 5;
		}
		if (line == 0)
			return (1);
	}
	i = buf;
	line = check_symbol(str, 4, 1, i);
	if (line == 0)
		return (2);
	return (-1);
}
