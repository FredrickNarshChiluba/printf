#include "main.h"

/**
 * unsign_print - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int unsign_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int i = BUFFR_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_unsgned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFR_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd_handler(0, i, buffer, flags, width, precision, size));
}

/**
 * oct_print - Prints an unsigned number in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int oct_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{

	int i = BUFFR_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOT_USED(width);

	num = convert_unsgned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFR_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & FLAG_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd_handler(0, i, buffer, flags, width, precision, size));
}

/**
 * hexa_dec_print - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_dec_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (hexa_print(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/**
 * hexa_upper_print - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int hexa_upper_print(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (hexa_print(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/**
 * hexa_print - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int hexa_print(va_list types, char map_to[], char buffer[],
		int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFFR_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	NOT_USED(width);

	num = convert_unsgned_size(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFR_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & FLAG_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd_handler(0, i, buffer, flags, width, precision, size));
}
