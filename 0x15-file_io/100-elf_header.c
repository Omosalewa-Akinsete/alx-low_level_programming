#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/stat.h>
#include <elf.h>

/**
 * error_exit - Display an error message and exit with status code 98.
 * @msg: The error message to display.
 */
void error_exit(const char *msg)
{
	dprintf(STDERR_FILENO, "%s\n", msg);
	exit(98);
}

/**
 * print_elf_header_info - Print information from the ELF header.
 * @ehdr: Pointer to the ELF header structure.
 */
void print_elf_header_info(Elf64_Ehdr *ehdr)
{
	printf("Magic:   %02x %02x %02x %02x\n",
			ehdr->e_ident[EI_MAG0], ehdr->e_ident[EI_MAG1],
			ehdr->e_ident[EI_MAG2], ehdr->e_ident[EI_MAG3]);
	printf("Class:   %d-bit\n", (ehdr->e_ident[EI_CLASS] == ELFCLASS32) ? 32 : 64);
	printf("Data:    %s\n",
			(ehdr->e_ident[EI_DATA] == ELFDATA2LSB) ? "2's complement, little-endian" : "2's complement, big-endian");
	printf("Version: %d (current)\n", ehdr->e_ident[EI_VERSION]);
	printf("OS/ABI:  %d\n", ehdr->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("Type:    %d\n", ehdr->e_type);
	printf("Entry point address: 0x%lx\n", (unsigned long)ehdr->e_entry);
}

/**
 * main - Entry point for the elf_header program.
 * @argc: The number of command-line arguments.
 * @argv: An array of command-line argument strings.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		error_exit("Usage: elf_header elf_filename");

	const char *filename = argv[1];
	int fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_exit("Error: Unable to open file");

	Elf64_Ehdr ehdr;
	ssize_t n = read(fd, &ehdr, sizeof(ehdr));
	if (n == -1)
		error_exit("Error: Unable to read file");

	if (n != sizeof(ehdr) || ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
			ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
		error_exit("Error: Not an ELF file");

	print_elf_header_info(&ehdr);
	close(fd);

	return 0;
}
