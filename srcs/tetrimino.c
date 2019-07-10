/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 15:22:04 by selly             #+#    #+#             */
/*   Updated: 2019/07/10 19:01:14 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

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

int			type_e_vert(char *s, int i, int line, int step)
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
	if ((step = type_e_vert(s, touch(s), 4, 0)) > 0)
		return (step);
	return (-1);
}

int			check_square(char *str)
{
	int		i;
	int		count_hash;
	int		check_on_four_line;

	i = 0;
	count_hash = 0;
	check_on_four_line = 0;
	while (i < 20)
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n' && str[i] != '\0')
			return (0);
		if (str[i] == '\n')
			check_on_four_line++;
		if (str[i] == '#')
			count_hash++;
		i++;
	}
	if ((count_hash > 0 && str[20] == '\n' && check_on_four_line > 4) ||
			(check_on_four_line == 4 && count_hash == 4 && str[19] == '\n'))
		return (count_hash);
	return (-1);
}

int			tetrimino(char *str)
{
	int		type_tetr;
	int		start;
	int		searching_hashes;

	type_tetr = check_square(str);
	start = touch(str);
	searching_hashes = 4;
	if (type_tetr == 4)
	{
		type_tetr = -1;
		type_tetr = type_a(str, start, searching_hashes, type_tetr);
		if (type_tetr <= 0)
			type_tetr = type_b(str, start, searching_hashes);
		if (type_tetr <= 0)
			type_tetr = type_c(str, start, searching_hashes, type_tetr);
		if (type_tetr <= 0)
			type_tetr = type_d(str, start, searching_hashes, type_tetr);
		if (type_tetr <= 0)
			type_tetr = type_f(str, start, searching_hashes, type_tetr);
		if (type_tetr <= 0)
			type_tetr = type_e(str, start, searching_hashes, 0);
		return (type_tetr);
	}
	return (-1);
}
