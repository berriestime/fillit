/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 17:06:35 by selly             #+#    #+#             */
/*   Updated: 2019/07/08 17:14:33 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int		start_size_of_square(int *figures, int count_of_tetr)
{
	int	i;

	i = 0;
	while (i < count_of_tetr)
	{
		if (figures[i] == 1 || figures[i] == 2)
			return (4);
		if (figures[i] == 3)
			return (2);
		i++;
	}
	return (3);
}
