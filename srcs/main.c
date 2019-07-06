/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <selly@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:17:01 by dmorrige          #+#    #+#             */
/*   Updated: 2019/06/26 15:36:20 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetriminos.h"

int				check_symbol(char *s, int l, int st, int i)
{
	while (s[i] == '#')
	{
		l--;
		i += st;
	}
	return (l);
}

void			ft_invalid_tetr(void)
{
	ft_putendl("error");
	exit(1);
}

unsigned int	tetr_parser(char *a)
{
	if (!a || !(*a))
		ft_invalid_tetr();
	if (a[4] != '\n' || a[9] != '\n' || a[14] != '\n' || a[19] != '\n')
		ft_invalid_tetr();
	while (*a)
	{
		if (*a != '#' || *a != '.' || *a != '\n' || *a != '\0')
			ft_invalid_tetr();
		a++;
	}
	return (0);
}

void			ft_tetr_validation(int fd, int tetrs[MAX_TETRS + 1])
{
	int				tmp_tetr;
	size_t			len;
	size_t			red_mem;
	char			buff[VALID_TTR_SYM_COUNT + 2];

	len = 0;
	ft_bzero(tetrs, MAX_TETRS + 1);
	red_mem = 0;
	while (len < 27 && red_mem != 20 && \
			(red_mem = read(fd, buff, VALID_TTR_SYM_COUNT + 1)) > 0)
	{
		buff[VALID_TTR_SYM_COUNT + 1] = 0;
		if (red_mem < 20 || (tmp_tetr = tetrimino(buff)) == -1)
			ft_invalid_tetr();
		tetrs[len] = tmp_tetr;
		len++;
	}
	if (red_mem != 20 || len > 26)
		ft_invalid_tetr();
	tetrs[len + 1] = 0;
	tetr_line(tetrs, start_size(tetrs, count_tetr(tetrs)), 0);
}

int				main(int argc, char const **argv)
{
	int			tetriminos[MAX_TETRS + 1];
	int			fd;

	if (argc != 2)
	{
		ft_putstr("usage: ");
		ft_putstr(argv[0]);
		ft_putendl(" [file name]");
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_invalid_tetr();
	ft_tetr_validation(fd, tetriminos);
	return (0);
}
