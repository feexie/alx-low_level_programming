#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define BUFSIZE 1024

void clean_buf(char *buf);

/**
 * main - copy file to an other
 * @argc: number of arguments
 * @argv: arguments
 * Return: 0 on success
 */

int main(int argc, char **argv)
{
	int fd_from, fd_to, letters, close_from, close_to;
	char buf[BUFSIZE];

	clean_buf(buf);

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((letters = read(fd_from, buf, BUFSIZE)) > 0)
	{
		if (fd_to < 0 || write(fd_to, buf, letters) != letters)
		{
			dprintf(STDERR_FILENO, "Error: Can't write from file %s\n", argv[2]);
			close(fd_to);
			exit(99);
		}
	}
	close_from = close(fd_from);
	close_to = close(fd_to);
	if (close_from < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close_to < 0)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}
	return (0);
}

/**
 * clean_buf - clean buffer
 * @buf: the buffer to clean
 */

void clean_buf(char *buf)
{
	int i;

	for (i = 0; buf[i]; i++)
		buf[i] = 0;
}
