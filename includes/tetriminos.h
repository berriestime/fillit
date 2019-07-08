/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmorrige <dmorrige@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 08:21:13 by dmorrige          #+#    #+#             */
/*   Updated: 2019/07/08 15:29:55 by dmorrige         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRIMINOS_H
# define TETRIMINOS_H

# include "libft/libft.h"
# include <fcntl.h>

# define MAX_TETRS 26
# define MAX_SQUARE 16
# define VALID_TTR_SYM_COUNT 20

int				main(int argc, char const **argv);
int				tetrimino(char *str);
int				type_a(char *str, int i, int line, int type);
int				type_b(char *str, int i, int line);
int				type_c(char *str, int i, int line, int a);
int				type_d(char *str, int i, int line, int a);
int				type_f(char *str, int i, int line, int a);
int				check_symbol(char *s, int l, int st, int i);
int				figura(char c, int size, int step, char **line);
int				square_begin(int size, int step);
int				hor_begin(int size, int step);
int				hor_e(int c, int size, int step, char **line);
int				vert_e(int c, int size, int step, char **line);
int				hor_f(int c, int size, int step, char **line);
int				vert_f(int c, int size, int step, char **line);
int				line_begin(int c, int size, int step);
int				check_place(char **tetr, int i, int type, int step);
int				check_e(char **line, int i, int step1, int step2);
int				check_vertg(int c, int size, int i, char **line);
int				check_horg(int c, int size, int i, char **line);
int				do_step(char **line, char **solve, int step);
int				last_step(int a, int flag, int step);
int				remove_alpha(char **dest, char **line, int i);
void			output(char *s, int size);
void			solve(int *figures, int size_square, int step);
int				count_tetr(int *c);
int				start_size_of_square(int *m, int size);
void			ft_invalid_tetr(void);

#endif
