#include "main.h"
/**
 * factorial - Returns the factorial of a given number.
 * @n: The string to be printed.
 * Return: 0
 */
int factorial(int n)
{
	if (n == 0)
	{
		return (1);
	}
	else if (n < 0)
	{
		return (-1);
	}
	return (n * factorial(n - 1));
}
