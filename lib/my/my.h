/*
** EPITECH PROJECT, 2023
** include
** File description:
** include structs and funcs for myprintf
*/

#ifndef INCLUDE
    #define INCLUDE

    #include <stdarg.h>
typedef struct link_s {
    char flag;
    int (*funct)(int count, va_list list);
} link_t;

int pmy_putchar(char c);
int pmy_putstr(char const *str);
int pmy_put_nbr(int nb);
int pfunct_d(int count, va_list list);
int pfunct_i(int count, va_list list);
int pfunct_c(int count, va_list list);
int pfunct_s(int count, va_list list);
int pfunct_percent(int count, va_list list);
int pfunct_o(int count, va_list list);
int pmy_put_octal(int nb);
int pfunct_u(int count, va_list list);
int pmy_put_unbr(unsigned int nb);
int pfunct_x_min(int count, va_list list);
int pmy_put_hexa_min(unsigned int nb);
int pfunct_x_maj(int count, va_list list);
int pmy_put_hexa_maj(unsigned int nb);
int pfunct_p(int count, va_list list);
int pmy_put_hexa_min_long(unsigned long nb);
int pfunct_n(int count, va_list list);
void my_putchar(char c);
char *my_strstr(char *str, char const *to_find);
int my_isneg(int nb);
int my_strcmp(char const *s1, char const *s2);
int my_put_nbr(int nb);
int my_strncmp(char const *s1, char const *s2, int n);
void my_swap(int *a, int *b);
char *my_strupcase(char *str);
int my_putstr(char const *str);
char *my_strlowcase(char *str);
int my_strlen(char const *str);
char *my_strcapitalize(char *str);
int my_getnbr(char const *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strcat(char *dest, char const *src);
char *my_revstr(char *str);
char *my_strncat(char *dest, char const *src, int nb);
int my_printf(char const *format, ...);
#endif
