#include <stdlib.h> /* for malloc, free */
#include <string.h> /* for strlen, strncpy, strncat */
#include "main.h"

/**
 * string_nconcat - Concatenates two strings with a limit on the second string
 * @s1: First string
 * @s2: Second string
 * @n: Maximum number of bytes to concatenate from s2
 *
 * Return: Pointer to the concatenated string (s1 + s2) with n bytes from s2,
 *         NULL if memory allocation fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
    unsigned int s1_len, s2_len;
    char *result;

    if (s1 == NULL)
        s1 = ""; /* Treat NULL as an empty string */
    if (s2 == NULL)
        s2 = ""; /* Treat NULL as an empty string */

    s1_len = strlen(s1);
    s2_len = strlen(s2);

    /* If n is greater or equal to the length of s2, use the entire string s2 */
    if (n >= s2_len)
        n = s2_len;

    /* Allocate memory for the concatenated string */
    result = (char *)malloc((s1_len + n + 1) * sizeof(char));

    if (result == NULL)
    {
        /* Failed to allocate memory, return NULL */
        return NULL;
    }

    /* Copy s1 to the result string */
    strncpy(result, s1, s1_len);
    result[s1_len] = '\0'; /* Null-terminate s1 in the result string */

    /* Copy the first n bytes of s2 to the result string */
    strncat(result + s1_len, s2, n);

    return result;
}

