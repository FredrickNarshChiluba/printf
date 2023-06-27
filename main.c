#include <limits.h>
#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int charCount = _printf("Hello, %c! This is a %s function.\n", 'W', "custom printf");
	printf("Number of characters printed: %d\n", charCount);
	
	return (0);
}
