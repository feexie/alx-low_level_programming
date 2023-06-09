#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int str_len(char *str)
{
    int len;

    for (len = 0; *str != '\0'; len++)
        len++, str++;
    return (len / 2);
}

void *_calloc(unsigned int bytes, unsigned int size)
{
    unsigned int i;
    char *p;

    if (bytes == 0 || size == 0)
        return (NULL);
    if (size >= UINT_MAX / bytes || bytes >= UINT_MAX / size)
        return (NULL);
    p = malloc(size * bytes);
    if (p == NULL)
        return (NULL);
    for (i = 0; i < bytes * size; i++)
        p[i] = 0;
    return ((void *)p);
}

void add_arrays(int *mul_result, int *sum_result, int len_r)
{
    int i = 0, len_r2 = len_r - 1, carry = 0, sum;

    while (i < len_r)
    {
        sum = carry + mul_result[len_r2] + sum_result[len_r2];
        sum_result[len_r2] = sum % 10;
        carry = sum / 10;
        i++;
        len_r2--;
    }
}

int is_digit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    printf("Error\n");
    return (0);
}

int *multiply(char *num1, int len_1, char *num2, int len_2, int len_r)
{
    int i = 0, i1 = len_1 - 1;
    int i2, product, carry, digit, *mul_result, *sum_result;

    sum_result = _calloc(sizeof(int), (len_r));
    while (i < len_1)
    {
        mul_result = _calloc(sizeof(int), len_r);
        i2 = len_2 - 1, digit = (len_r - 1 - i);
        if (!is_digit(num1[i1]))
            return (NULL);
        carry = 0;
        while (i2 >= 0)
        {
            if (!is_digit(num2[i2]))
                return (NULL);
            product = (num1[i1] - '0') * (num2[i2] - '0');
            product += carry;
            mul_result[digit] += product % 10;
            carry = product / 10;
            digit--, i2--;
        }
        add_arrays(mul_result, sum_result, len_r);
        free(mul_result);
        i++, i1--;
    }
    return (sum_result);
}

void print_me(int *sum_result, int len_r)
{
    int i = 0;

    while (sum_result[i] == 0 && i < len_r)
        i++;
    if (i == len_r)
        _putchar('0');
    while (i < len_r)
        _putchar(sum_result[i++] + '0');
    _putchar('\n');
}

int main(int argc, char **argv)
{
    int len_1, len_2, len_r, temp, *sum_result;
    char *num1, *num2;

    if (argc != 3)
    {
        printf("Error\n");
        exit(98);
    }
    len_1 = str_len(argv[1]), len_2 = str_len(argv[2]);
    len_r = len_1 + len_2;
    if (len_1 < len_2)
}
