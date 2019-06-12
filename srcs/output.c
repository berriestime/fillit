/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:45:55 by selly             #+#    #+#             */
/*   Updated: 2019/06/12 16:47:50 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		line_begin(int c, int size, int step)
{
	int		i;
	int		m;
	int		b;
	int		a;

	i = 0;
	m = 0;
	b = size - 4;
	a = b;
	while (m < step)
	{
		if (c == 1)
			i++;
		if (c == 2)
		{
			if (i < a)
				i++;
			else
			{
				i = i + size - b;
				a += size;
			}
		}
		m++;
	}
	return (i);
}

void	output(char *s, int size)
{
	int i;
	int n;

	i = 0;
	n = size;
	while (s[i] && i < size * size)
	{
		if (i < n)
		{
			ft_putchar(s[i]);
			i++;
		}
		else
		{
			ft_putchar('\n');
			n = n + size;
		}
	}
	ft_putchar('\n');
}
