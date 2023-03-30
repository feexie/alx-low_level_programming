/**
 * _strcmp - a function that compare two strings
 * @s1: Pointer to first string
 * @s2: Pointer to second string
 * Return: An integer greater than, equal to, or less than 0,
 * according as the string s1 is greater than, equal to,
 * or less than the string s2 (based on ASCII value comparison)
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, r;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			r = s1[i] - s2[i];
			break;
		}
		else
		{
			r = s1[i] - s2[i];
		}
		i++;
	}
	return (r);
}
