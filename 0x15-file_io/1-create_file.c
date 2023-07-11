#include "main.h"

/**
 * create_file - creates a file
 * @filename: name of the file to create
 * @text_content: string to add to the file
 * Return: 1 on success else -1
 */

int create_file(const char *filename, char *text_content)
{

	int o, w, letters;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (letters = 0; text_content[letters];)
			letters++;
	}
	else
	{
		text_content = "";
		for (letters = 0; text_content[letters];)
			letters++;
	}

	o = open(filename, O_CREAT | O_RDWR | O_TRUNC, 0600);
	w = write(o, text_content, letters);

	if (o == -1 || w == -1 || w != letters)
		return (-1);

	close(o);

	return (1);
}
