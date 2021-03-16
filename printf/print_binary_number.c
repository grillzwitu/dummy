#include "holberton.h"

/**
 * print_binary_number - Entry point
 *
 * @list: int to be converted
 *
 * Description: converts an unsigned int to binary
 *
 * Return: no of resulting binary characters
 */

int print_binary_number(va_list list)
{
	unsigned int num;
	int printed_chars = 0, index = 0;
	char bin[sizeof(unsigned int) * 8];

	num = va_arg(list, unsigned int);

	if (num == 0)
	{
		printed_chars += _putchar('0');
		return (printed_chars);
	}
	if (num == 1)
	{
		printed_chars += _putchar('1');
		return (printed_chars);
	}
	for (; num > 0; index++)
	{
	bin[index] = '0' + (num % 2);
	num = num / 2;
	}
	index--;
	for (; index >= 0; index--)
	{
	printed_chars += _putchar(bin[index]);
	}
	return (printed_chars);
}
