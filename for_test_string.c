/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_test_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: selly <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:36:03 by selly             #+#    #+#             */
/*   Updated: 2019/05/29 15:40:04 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 int     main(void)
{
	int m = 0;
	int c;
	int q;
	char a[20];
	while (m < 18)
	{
		c = 0;
		while (c++ < 4)
			a[m++] = '.';
		if (m != 19)
			a[m++] = '\n';
	}
	a[m] = '\0';
	q = 5;
	while (q < 9)
	{
		a[q] = '#';
		q++;
	}
   	printf("%s\n", a);
	printf("%d\n", termino(a));
	return (0);
}