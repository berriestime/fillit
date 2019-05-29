/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tetr_validation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 09:17:14 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/29 12:02:54 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"
#include <unistd.h> /* for read and write */

void	ft_tetr_validation(int fd, unsigned int tetrs[MAX_TETRS + 1])
{
	unsigned int	tmp_tetr;
	size_t			len;
	size_t			red_mem;
	char			buff[VALID_TTR_SYM_COUNT + 2];

	ft_bzero(tetrs, MAX_TETRS + 1);
	len = 0;
	red_mem = 0;
	while (len < 27 && red_mem != 20 &&\
	(red_mem = read(fd, buff, VALID_TTR_SYM_COUNT + 1)) > 0)
	{
		buff[VALID_TTR_SYM_COUNT + 1] = 0;
		if (red_mem < 20 || !(tmp_tetr = termino(buff)))
			ft_invalid_tetr();
		tetrs[len] = tmp_tetr;
		len++;
	}
	if (red_mem != 20 || len > 26)
		ft_invalid_tetr();
	tetrs[len + 1] = 0;
}
