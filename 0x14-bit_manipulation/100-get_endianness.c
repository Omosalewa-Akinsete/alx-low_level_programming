#include "main.h"

/**
 * get_endianness - Checks the endianness of the system.
 *
 * Returns: 0 if big endian, 1 if little endian.
 */
int get_endianness(void)
{
	unsigned int test = 1;
	char *ch = (char *)&test;

	if (*ch)
		return (1);
	else
		return (0);
}
