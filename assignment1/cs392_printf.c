#include <stdarg.h>
#include <stdio.h>

int cs392_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    unsigned int i;
    static char num_str[] = "0123456789";
    static char buffer[50];
    char *s;

    // iterative over "format" and find specifiers
    while (*format != '\0') {
        // get the first argument with va_arg

        if (*format == '%') {
            format++;
            if (*format == 0)
                break;

            // decimal argument
            if (*format == 'd') {
                i = va_arg(args, int);
                if (i < 0) {
                    i = -i;
                    putchar('-');
                }
                s = &buffer[49];
                *s = '\0';
                do {
                    *--s = num_str[i % 10];
                    i /= 10;
                } while (i != 0);
                fputs(s, stdout);
            }

            // string argument
            if (*format == 's') {
                s = va_arg(args, char *);
                fputs(s, stdout);
            }

            // character argument
            if (*format == 'c') {
                i = va_arg(args, int);
                putchar(i);
            }

        } else {
            putchar(*format);
        }
        ++format;
    }

    va_end(args);
}
