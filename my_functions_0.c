#include "main.h"

/**
 * _putchar - Prints a char
 * @c: character argument
 * Return: int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
