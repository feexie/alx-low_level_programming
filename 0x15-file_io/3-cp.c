#include "main.h"
/**
 * cp - copies content of file_from to file_to
 * @file_from: source file
 * @file_to: destination file
 * Returm: 0 on success, otherwise error code
 */
int cp(const char *file_from, const char *file_to)
{
	int fd_from, fd_to, bytes_read, bytes_written, total_bytes = 0;
	char buf[BUF_SIZE];

	if (!file_from || !file_to)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	fd_from = open(file_from, O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		return (98);
	}
	fd_to = open(file_to, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
		return (99);
	}
	while ((bytes_read = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buf, bytes_read);
		if (bytes_written != bytes_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			close(fd_from);
			close(fd_to);
			return (99);
		}
		total_bytes += bytes_written;
	}
	if (bytes_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can'read from file %s\n", file_from);
		close(fd_from);
		close(fd_to);
		return (98);
	}
	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", errno);
		return (100);
	}
	return (100);
}
/**
 * main - entry point
 * @argc: argument count
 * @argn: argument vector
 * Return: 0 on success, otherwise error code
 */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}
	return (cp(argv[1], argv[2]));
}
