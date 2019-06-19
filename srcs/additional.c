/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 17:08:42 by selly             #+#    #+#             */
/*   Updated: 2019/06/19 14:53:15 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/tetriminos.h"

int		check_place(char **tetr, int i, int type, int step)
{
	char	*tmp;
	int		len;

	len = 4;
	type == 1 || type == 2 ? len : len--;
	tmp = *tetr;
	while(len && tmp[i] == '.')
	{
		tmp[i] = '#';
		i += step;
		len--;
	}
	return (len);
}
