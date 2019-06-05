/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:22:04 by selly             #+#    #+#             */
/*   Updated: 2019/06/05 14:35:33 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int			touch(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			return (i);
		i++;
	}
	return (-1);
}

int			type_line_e(char *s, int i, int line, int step)
{
	int		flag;

	flag = 0;
	if (s[i + 5] == '#' && s[i + 9] == '#')
		step = -1;
	if (s[i + 5] == '#' && s[i + 11] == '#')
		step = 1;
	while (s[i] == '#')
	{
		line--;
		flag++;
		if (flag == 2)
			i += step;
		else
			i += 5;
	}
	if (line == 0 && step != 0)
		return (step > 0 ? 15 : 14);
	return (-1);
}

int			type_e(char *s, int i, int line, int step)
{
	int		flag;

	flag = 0;
	if (s[i + 7] == '#' && s[i + 1] == '#')
		step = 5;
	if (s[i + 4] == '#' && s[i + 1] == '#')
		step = 3;
	while (s[i] == '#')
	{
		line--;
		flag++;
		if (flag == 2)
			i += step;
		else
			i++;
	}
	if (line == 0 && step == 5)
		return (12);
	if (line == 0 && step == 3)
		return (13);
	if ((step = type_line_e(s, touch(s), 4, 0)) > 0)
		return (step);
	return (-1);
}

int			check_square(char *str)
{
	int		i;
	int		a;
	int		c;

	i = 0;
	a = 0;
	c = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != '\0')
			return (0);
		if (str[i] == '\n')
			c++;
		if (str[i] == '#')
			a++;
		i++;
	}
	if (a > 0 && str[20] == '\n')
		return (a);
	return (-1);
}

int			tetrimino(char *str)
{
	int		type;
	int		start;
	int		line;

	type = check_square(str);
	start = touch(str);
	line = 4;
	if (type == 4)
	{
		type = -1;
		type = type_a(str, start, line, type);
		if (type <= 0)
			type = type_b(str, start, line);
		if (type <= 0)
			type = type_c(str, start, line, type);
		if (type <= 0)
			type = type_d(str, start, line, type);
		if (type <= 0)
			type = type_f(str, start, line, type);
		if (type <= 0)
			type = type_e(str, start, line, 0);
		return (type);
	}
	return (-1);
}
