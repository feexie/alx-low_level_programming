/**
 * _strcat - Concentrate two strings
 * @dest: Pointer to destination string.
 * @src: Pointer to source string
 * Return: Pointer to destination string
 */
char *_strcat(char *dest, char *src)
{
	char *start = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}
