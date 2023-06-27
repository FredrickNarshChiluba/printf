#include "main.h"

int count = 0;

int _printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

    while (*format != '\0') {
        if (*format == '%') {
            format++;

            if (*format == 'c') {
                int c = va_arg(args, int);
                _putchar(c);
                count++;
            } else if (*format == 's') {
                char* str = va_arg(args, char*);
                while (*str != '\0') {
                    _putchar(*str);
                    str++;
                    count++;
                }
            } else if (*format == '%') {
                _putchar('%');
                count++;
            }
        } else {
            _putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return (count);
}