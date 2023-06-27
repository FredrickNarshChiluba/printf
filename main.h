#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <unistd.h>

/**
 * _printf - custom printf
 * @format: format specifier
 * @...: variadic function parameter
 * Return: int
 */
int _printf(const char *format, ...);

/**
 * _putchar - print character to stdout
 * @c: character variable
 * Return: int
 */
int _putchar(char c);
#endif
