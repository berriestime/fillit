/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:46:14 by selly             #+#    #+#             */
/*   Updated: 2019/06/12 16:47:43 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	hor_begin(int size, int step)
{
	int i;
	int b;
	int m;

	i = 0;
	b = 0;
	m = 0;
	while (m < step)
	{
		if (i < (size - 2) + b - 1)
		{
			m++;
			i++;
		}
		else
		{
			i += 3;
			b += size;
			m++;
		}
	}
	return (i);
}

int    square_begin(int size, int step)
{
        int i;
        int b;
        int m;

        i = 0;
        b = 0;
        m = 0;
        while (m < step)
        {
                if (i < (size - 1) + b - 1)
                {
                        m++;
                        i++;
                }
                else
                {
                        i = i + 2;
                        b += size;
                        m++;
                }
        }
        return (i);
}

int	hor_e(int c, int size, int *step, char **line)
{
	char *tetr;
	int i;
	int len;

	tetr = *line;
	len = 4;
	if (*step >= (size - 1) * (size - 2))
			return (-1);
	i = hor_begin(size, *step);
	printf("%d i\n", i);
	if (c == 12)
	{
		while (tetr[i] && len)
		{
			if (tetr[i] == '.')
			{
				tetr[i] = 'E';
				len--;
			}
			if (len == 2)
			 i += size;
			 else
			 i++;
		}
	}
	if (c == 13)
	{
		i += size;
		while (tetr[i] && len)
		{
			if (tetr[i] == '.')
			{
				tetr[i] = 'E';
				len--;
			}
			if (len == 2)
				i -= size;
			else
				i++;
		}
	}
	if (len == 0)
		return (1);
	return (-1);
}

int	vert_e(int c, int size, int *step, char **line)
{
	char *tetr;
	int i;
	int len;

	if (*step >= (size - 1) * (size - 2))
                        return (-1);
	i = square_begin(size, *step);
        printf("%d our i\n", i);
	tetr = *line;
	len = 4;
	if (c == 14)
	{
		i++;
		while (tetr[i] && len)
		{
			if (tetr[i] == '.')
			{
				tetr[i] = 'E';
				len--;
			}
			if (len == 2)
				--i;
			else
				i += size;
		}
	}
	if (c == 15)
	{
		while (tetr[i] && len)
		{
			if (tetr[i] == '.')
			{
				tetr[i] = 'E';
				len--;
			}
			if (len == 2)
				i++;
			else
				i += size;
		}
	}
	if (len == 0)
		return (1);
	return (-1);
}

int	hor_f(int c, int size, int *step, char **line)
{
	char *tetr;
	int i;
	int len;

	if (*step >= (size - 1) * (size - 2))
		return (-1);
	tetr = *line;
	len = 4;
	i = hor_begin(size, *step);
	printf("%d our i\n", i);
	if (c == 16 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = 'F';
		len--;
	}
	if (c == 17 && tetr[i + 1] == '.')
	{
		tetr[i + 1] = 'F';
		len--;
		i += size;
	}
	if (len == 3)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i++] = 'F';
			len--;
		}
	}
	if (len == 0)
		return (1);
	return(-1);
}

int		vert_f(int c, int size, int *step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	if (*step >= (size - 1) * (size - 2))
		return (-1);
	tetr = *line;
	len = 4;
	i = square_begin(size, *step);
	printf("%d our i\n", i);
	if (c == 18 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = 'F';
		len--;
	}
	if (c == 19 && tetr[i + size] == '.')
	{
		tetr[i + size] = 'F';
		len--;
		i++;
	}
	if (len == 3)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i] = 'F';
			len--;
			i += size;
		}
	}
	if (len == 0)
		return (1);
	return (-1);
}
