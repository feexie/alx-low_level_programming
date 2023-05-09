#include "main.h"
#include <string.h>
/**
 * create_file - creates a file and write text_content to it
 * @filename: name of the file to create
 * @text_content: NULL terminated string to write to the file
 * Return: 1 on success, -1 on failure
 * The created file must have permission rw-------
 * if the file already exists, truncate it
 * if filename is NULL return -1
 * if text_content is NULL, create an empty file
 */
int create_file(const char *filename, char *text_content)
{
	int fd, written_bytes, text_len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content != NULL)
		text_len = strlen(text_content);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);
	if (text_len > 0)
	{
		written_bytes = write(fd, text_content, text_len);
		if (written_bytes != text_len)
		{
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (1);
}
