/*
** EPITECH PROJECT, 2023
** B-CPE-100-LYN-1-1-cpoolday07-lorenzo.la-rocca
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void minimized(char *str, int index);
int my_strlen2(char const *str);
int my_count_int(double nb);
static int check_space(const char *format, int index, int len, va_list list);
int call_flags(const char *format, int index, int len, va_list list);
int my_printf(const char *format, ...);
static void show_long(char *hexadec, int decount, int count);
static void hexadecimal_long(unsigned long nb);
static void show_float(int upper, int prec, int defaut, int whole);
static void error_float_handling(double nb, int defaut);
void print_float(double nb);
void print_pointer(void *addr);
void show_float_modified(int upper, int prec, int defaut);
void static print_float_modified(double nb, int defaut);
void compute_after_dec(int exp, int whole);
void print_e(double nb);
int check_dspo(const char *format, int index, int len, va_list list);
int check_ciux(const char *format, int index, int len, va_list list);
int check_fgp(const char *format, int index, int len, va_list list);
int check_en(const char *format, int index, int len, va_list list);
int octal_type(const char *format, int len, int index, va_list list);
void my_put_signed_nbr(int nb);
static void my_put_unsigned_nbr(unsigned int nb);
void unsigned_type(int *nb);
static void show(char *hexadec, int decount, int flag, int count);
void hexadecimal(unsigned int nb, int flag);
void print_d(const char *format, int len, int index, va_list list);
void print_i(const char *format, int len, int index, va_list list);
void print_c(const char *format, int len, int index, va_list list);
void print_s(const char *format, int len, int index, va_list list);
void print_p(const char *format, int len, int index, va_list list);
char **my_str_to_word_array(char *str);

#endif /* !MY_H_ */
