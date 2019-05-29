/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminos_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:57:43 by selly             #+#    #+#             */
/*   Updated: 2019/05/29 16:45:58 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		touch(char *str);

int		type_F(char *str)
{
	return (0);
}

int		type_D(char *str)
{
	return (0);
}

int		type_C(char *str) 
{
	return (0);
}
int		type_B(char *str)
{
	int		i;
	int		line;

	line = 4;
	i = touch(str);
	if (i >= 0 && i < 13)
	{
		while (str[i] == '#')
		{
			line--;
			i++;
		}
		if (line == 2)
		{
			i  += 3;
			while (str[i++] == '#')
				line--;
		}
	}
	if (line == 0)
		return (2);
	return (-1);
}
