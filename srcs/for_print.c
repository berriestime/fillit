/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 13:46:14 by selly             #+#    #+#             */
/*   Updated: 2019/06/18 17:18:58 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	hor_e(int c, int size, int step, char **line)
{
	char *tetr;
	int i;
	int len;

	tetr = *line;
	len = 4;
	if (step >= (size - 1) * (size - 2))
			return (-2);
	i = hor_begin(size, step);
	if (c == 12)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
			if (len == 2)
			i += size;
			else
			 i++;
		}
	}
	if (c == 13)
	{
		i += size;
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
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

int	vert_e(int c, int size, int step, char **line)
{
	char *tetr;
	int i;
	int len;

	if (step >= (size - 1) * (size - 2))
        return (-2);
	i = square_begin(size, step);
	tetr = *line;
	len = 4;
	if (c == 14)
	{
		i++;
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
			if (len == 2)
				--i;
			else
				i += size;
		}
	}
	if (c == 15)
	{
		while (tetr[i]=='.' && len)
		{
			tetr[i] = '#';
			len--;
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

int	hor_f(int c, int size, int step, char **line)
{
	char *tetr;
	int i;
	int len;

	if (step >= (size - 1) * (size - 2))
		return (-2);
	tetr = *line;
	len = 4;
	i = hor_begin(size, step);
	if (c == 16 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = '#';
		len--;
	}
	if (c == 17 && tetr[i + 1] == '.')
	{
		tetr[i + 1] = '#';
		len--;
		i += size;
	}
	if (len == 3)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i++] = '#';
			len--;
		}
	}
	if (len == 0)
		return (1);
	return(-1);
}

int		vert_f(int c, int size, int step, char **line)
{
	char	*tetr;
	int		i;
	int		len;

	if (step >= (size - 1) * (size - 2))
		return (-2);
	tetr = *line;
	len = 4;
	i = square_begin(size, step);
	if (c == 18 && tetr[i + size + 1] == '.')
	{
		tetr[i + size + 1] = '#';
		len--;
	}
	if (c == 19 && tetr[i + size] == '.')
	{
		tetr[i + size] = '#';
		len--;
		i++;
	}
	if (len == 3)
	{
		while (tetr[i] == '.' && len)
		{
			tetr[i] = '#';
			len--;
			i += size;
		}
	}
	if (len == 0)
		return (1);
	return (-1);
}
