/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:21:13 by dmorrige          #+#    #+#             */
/*   Updated: 2019/05/29 15:52:06 by selly            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "libft/libft.h"

# define MAX_TETRS 26
# define MAX_SQUARE 16
# define VALID_TTR_SYM_COUNT 20

void			ft_tetr_validation(int fd, unsigned int tetr[MAX_TETRS + 1]);
unsigned int	tetr_parser(char *a);

int				termino(char *str);
int				type_B(char *str);
int				type_C(char *str);
int				typr_D(char *str);
int             typr_F(char *str);

#endif
