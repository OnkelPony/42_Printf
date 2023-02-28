/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:53:07 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/28 17:09:44 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <stddef.h>
# include "libft_subset/libft.h"
# ifndef ARG_CHARS
#  define ARG_CHARS "cspdiuxX"
# endif

int	ft_printf(const char *format, ...);


#endif