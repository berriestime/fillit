/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:03:26 by selly             #+#    #+#             */
/*   Updated: 2019/06/04 19:27:19 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int		check_type(char *s, int i, int *t)
{
	int		st;

	st = 0;
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
	return (st);
}

int		type_f(char *s, int i, int l, int t)
{
	int		st;

	st = check_type(s, i, &t);
	l--;
	while (s[i] == '#')
	{
		l--;
		i += st;
	}
	return (l == 0 ? t : -1);
}
