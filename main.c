/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:17:01 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/29 12:02:56 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include <fcntl.h>/* for open */

int					main(int argc, char const **argv)
{
	unsigned int	tetriminos[MAX_TETRS + 1];
	int				fd;

	if (argc != 2)
		ft_invalid_tetr();
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_invalid_tetr();
	ft_tetr_validation(fd, tetriminos);
	return (0);
}
