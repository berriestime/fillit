/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 12:15:36 by dmorrige          #+#    #+#             */
/*   Updated: 2019/07/06 18:02:22 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int	start_size(int *figures, int count_of_tetr)
{
	int i;

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
