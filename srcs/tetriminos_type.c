/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:07:15 by selly             #+#    #+#             */
/*   Updated: 2019/06/05 16:36:24 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		type_f(char *s, int i, int l, int t)
{
	int		st;

	st = 1;
	if (s[i + 1] == '#' && s[i + 6] == '#')
		t = 16;
	if (s[i + 5] == '#' && s[i + 4] == '#' && s[i + 6] == '#')
	{
		t = 17;
		i += 4;
	}
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 4] == '#')
	{
		t = 19;
		st = 5;
	}
	if (s[i + 5] == '#' && s[i + 10] == '#' && s[i + 6] == '#')
	{
		t = 18;
		st = 5;
	}
	l = check_symbol(s, 3, st, i);
	return (l == 0 ? t : -1);
}

int		type_d(char *s, int i, int line, int a)
{
	if (s[i + 5] == '#' && s[i + 1] == '#')
		a = 8;
	if (s[i + 7] == '#' && s[i + 1] == '#')
		a = 9;
	if (s[i + 5] == '#' && s[i + 7] == '#')
	{
		i += 5;
		a = 10;
	}
	if (s[i + 3] == '#' && s[i + 5] == '#')
	{
		i += 3;
		a = 11;
	}
	line = check_symbol(s, 3, 1, i);
	if (line == 0)
		return (a);
	return (-1);
}

int		type_c(char *str, int i, int line, int a)
{
	if (str[i + 1] == '#' && str[i + 10] == '#')
		a = 4;
	if (str[i + 5] == '#' && str[i + 11] == '#')
		a = 6;
	if (str[i + 1] == '#' && str[i + 11] == '#')
	{
		i++;
		a = 5;
	}
	if (str[i + 9] == '#' && str[i + 5] == '#')
		a = 7;
	line = check_symbol(str, 3, 5, i);
	if (line == 0)
		return (a);
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

int		type_a(char *str, int i, int line, int a)
{
	a = i;
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
	i = a;
	line = check_symbol(str, 4, 1, i);
	if (line == 0)
		return (2);
	return (-1);
}
