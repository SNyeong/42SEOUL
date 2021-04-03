/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:48:54 by seungnle          #+#    #+#             */
/*   Updated: 2021/04/04 05:55:06 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

# define TYPE "cspdiuxX%%"

typedef struct	s_option
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int		base;
	int		sign;
}				t_option;

int				ft_printf(const char *str, ...);
int				ft_parse(char *str, va_list ap);
void			check_flags(char *str, va_list ap, t_option *option, int idx);
void			init_option(t_option *option);
void			check_option(t_option *option);
int				ft_print_char(int c, t_option *option);
int				ft_put_char_w(int width, int zero);
int				ft_print_str(char *str, t_option *option);
char			*ft_set_str(char *str, int len);
int				ft_put_str_w(char **str, t_option *option);
int				ft_print_nb(unsigned long long nb, t_option *option);
char			*ft_set_nb(unsigned long long nb, t_option *option);
char			*ft_put_nb_pr(char *str, t_option *option);
char			*ft_put_nb_sign_x(char *str, t_option *option);
char			*ft_put_nb_w(char *str, t_option *option);
char			*ft_base(char c);
int				ft_nblen(unsigned long long nb, t_option *option);
void			ft_swap(char *c1, char *c2);

#endif
