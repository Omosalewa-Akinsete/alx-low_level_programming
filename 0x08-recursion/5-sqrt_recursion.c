#include "main.h"
/**
 * _sqrt_a - Returns the natural square root of a number.
 * @a: The string to be printed.
 * @b: The string to be printed.
 * Return: 0
 */
int sqrt_a(int a, int b)
{
	if (b * b == a)
	{
		return (b);
	}
	else if (b * b > a)
	{
		return (-1);
	}
	return (sqrt_a(a, b + 1));
}

/**
 * _sqrt_recursion - Returns the natural square root of a number.
 * @n: The string to be printed.
 * Return: 0
 */
int _sqrt_recursion(int n)
{
	return (sqrt_a(n, 0));
}
