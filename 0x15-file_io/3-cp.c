#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUF_SIZE 1024

/**
 * exit_with_error - Prints an error message and exit with the specified code.
 * @code: The exit code.
 * @message: The error message to print.
 */
void exit_with_error(int code, const char *message)
{
	dprintf(STDERR_FILENO, "%s\n", message);
	exit(code);
}

/**
 * main - Entry point
 * @argc: The number of command-line arguements.
 * @argv: An array of command-line arguement strings.
 * Return: 0 on success, other values on failure.
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t bytes_read, bytes_written;

	char buffer[BUF_SIZE];

	if (argc != 3)
	{
		exit_with_error(97, "Usage: cp file_from_file_to");
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		exit_with_error(98, "Error: Can't read from file");
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		exit_with_error(99, "Error: Can't write to file");
	}

	while ((bytes_read = read(fd_from, buffer, BUF_SIZE)) > 0)
	{
		bytes_written = write(fd_to, buffer, bytes_read);
	}
		if (bytes_written == -1)
		{
			exit_with_error(99, "Error: Can't write to file");
		}


	if (bytes_read == -1)
	{
		exit_with_error(98, "Error: Can't read from file");
	}

	if (close(fd_from) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
		exit(100);
	}
	if (close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
		exit(100);
	}

	return (0);
}
