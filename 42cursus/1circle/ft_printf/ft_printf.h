/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seungnle <seungnle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 20:48:54 by seungnle          #+#    #+#             */
/*   Updated: 2020/11/19 05:03:11 by seungnle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_option
{
	int		flags[5];
	int		width;
	int		precision;
	int		len;
	char	type;

	int		n_idx;
	int		*n_value;
	void	**n_addr;
}				t_option;

int				ft_printf(const char *str, ...);
int				ft_parse(char *str, va_list ap);
int				check_flags(char **str, va_list ap);
int				check_width(char **str, va_list ap, t_option option);
int				check_precision(char **str, va_list ap, t_option option);
int				check_len(char **str, va_list ap, t_option option);
int				check_type(char **str, va_list ap, t_option option);
t_option		init_option(void);
int				ft_char_count(char c);
int				ft_str_count(char *str);

#endif
