#include <stdio.h>
#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int.
 * @b: A string of 0 and 1 characters.
 *
 * Return: The converted number, or 0 if there's a character other than 0 or 1.
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	for (int i = 0; b[i] != '\0'; i++)
	{
		if (b[i] == '0')
			result = (result << 1) | 0;
		else if (b[i] == '1')
			result = (result << 1) | 1;
		else
			return (0);
	}

	return (result);

}
int main(void)
{
	const char *binary = "10110";

	unsigned int decimal = binary_to_uint(binary);

	printf("Binary: %s, Decimal: %u\n", binary, decimal);

	return (0);
}
