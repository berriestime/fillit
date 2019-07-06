/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:15:36 by dmorrige          #+#    #+#             */
/*   Updated: 2019/07/06 12:38:54 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	start_size(int *m, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (m[i] == 1 || m[i] == 2)
			return (4);
		if (m[i] == 3)
			return (2);
		i++;
	}
	return (3);
}
