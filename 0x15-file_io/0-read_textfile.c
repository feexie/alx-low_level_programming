##include "main.h"

/**
 * read_textfile - reads a text file and prints it to the POSIX std output
 * @filename: pointer to the file
 * @letters: number of letters
 * Return: actual numbers of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t o, r, w;
	char *buf;

	if (filename == NULL)
		return (0);

	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);

	o = open(filename, O_RDONLY);
	r = read(o, buf, letters);
	w = write(STDOUT_FILENO, buf, r);

	if (o == -1 || r == -1 || w == -1)
	{
		free(buf);
		return (0);
	}

	free(buf);
	close(o);

	return (w);
}
