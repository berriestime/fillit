/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termino.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 11:30:22 by selly             #+#    #+#             */
/*   Updated: 2019/05/29 15:51:50 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		type_E(char *str) /*здесь будет проверка на 5 фигуру*/

{
	return (1);
}

int     check_square(char *str) /*проверяет квадрат на пустоту и размер фигуры*/
{
	int i;
	int a;
	
	i = 0;
	a = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '.' &&  str[i] != '#' && str[i] != '\n' && str[i] != '\0')
			return (0);
		if (str[i] == '#')
			a++;
		i++;
	}
	if (a > 0)
		return(a);
	return (-1);
}

int		touch(char *str)    /*находит начальную точку фигуры*/
{
	int i;

	i = 0;
	while (str[i++])
		if (str[i] == '#')
			return (i);
	return (0);
}

int     type_A(char *str) /*проверяет является ли фигура линией фигура 1*/
{
	int     i;
	int     line;
	
	line = 4;
	i = touch(str);
	if (i >= 0 && i < 4)
	{
		while (str[i] == '#' && i < 19)
		{
			line--;
			i += 5;
		}
	}
	else
	{
		while (str[i] == '#' && i < 19)
		{
			line--;
			i++;
		}
	}
	if (line == 0)
		return (1);
	return (-1);
}

int		termino(char *str)
{
	int		type;

	type = check_square(str);
	printf("%d in\n", type);
	if (type == 4)
	{
		type = -1;
		type = type_A(str);
//		if (type <= 0)
//			type = type_B(str);
//		if (type <= 0)
//			type = type_C(str);
//		if (type <= 0)
//			type = type_D(str);
//		if (type <= 0)
//			type = type_E(str);
		return(type);
	}
	return (-1);
}
