/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkeirouz <kkeirouz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 14:33:44 by kkeirouz          #+#    #+#             */
/*   Updated: 2024/11/13 18:08:24 by kkeirouz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += handle_format(*format, args);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (count);
}
/*
int main(void) {
    // Test printing characters
    ft_printf("my printf -> Character: %c\n", 'A');
	printf("printf -> Character: %c\n", 'A');
    // Test no Format 
    ft_printf("\nmy printf -> String: %d\n", ft_printf(NULL));
	printf("printf -> String: %d\n", printf(NULL));
    // Test printing strings
    ft_printf("\nmy printf -> String: %s\n", "super");
	printf("printf -> String: %s\n", "Super");
    // Test printing integers
    ft_printf("\nmy printf -> Integer: %d\n", 0);
    ft_printf("my printf -> Negative integer: %d\n", -42);
    ft_printf("my printf -> Minimum integer: %d\n", -2147483648);
    printf("printf -> Integer: %d\n", 0);
    printf("printf -> Negative integer: %d\n", -42);
    printf("printf -> Minimum integer: %ld\n", -2147483648);

    // Test printing unsigned integers
    ft_printf("\nmy printf -> Unsigned integer: %u\n", 42);
    ft_printf("my printf -> Unsigned large integer: %u\n", 4294967295u);
    printf("printf -> Unsigned integer: %u\n", 42);
    printf("printf -> Unsigned large integer: %u\n", 4294967295u);

    // Test printing hexadecimal numbers
    ft_printf("\nmy printf -> Hexadecimal (lowercase): %x\n", 255);
    ft_printf("my printf -> Hexadecimal (uppercase): %X\n", 255);
    printf("printf -> Hexadecimal (lowercase): %x\n", 255);
    printf("printf -> Hexadecimal (uppercase): %X\n", 255);

    // Test printing pointers
    int n = 42;
    ft_printf("\nmy printf -> Pointer: %p\n", (void*)&n);
    printf("printf -> Pointer: %p\n", (void*)&n);

    // Test printing a percent sign
    ft_printf("\nmy printf -> Percent sign: %%\n");
    printf("printf -> Percent sign: %%\n");

    return 0;
}
*/
