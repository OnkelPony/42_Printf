/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimartin <jimartin@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:50:24 by jimartin          #+#    #+#             */
/*   Updated: 2023/02/28 19:21:54 by jimartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
Counts number of arguments included in the format. The arguments are %d, %s, %c
etc. as used in the printf() function.
format: string in which arguments are present
Return: number of arguments, negative number in case of error.
*/
int	args_count(const char *format)
{
	int		count;
	size_t	i;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
			i += 2;
		if (format[i] == '%' && ft_strchr(ARG_CHARS, format[i + 1]))
			count++;
	}
	return (count);
}

/*
Implement the function that will mimic the original printf()
Implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.
format: This is the string that contains the text to be written to stdout.
It can optionally contain embedded format tags that are replaced by the values
specified in subsequent additional arguments and formatted as requested.
Return: If successful, the total number of characters written is returned.
On failure, a negative number is returned.
*/
int	ft_printf(const char *format, ...)
{
	va_list arguments;
	size_t i;
	size_t written;

	va_start(arguments, format);
	i = -1;
	written = 0;
	while (format[++i])
	{
		if (format[i] == '%')
			ft_process_format(&written, format, i++);
		else
			written += write(1, &format[i], 1);
	}
	va_end(arguments);
	return (written);
}
