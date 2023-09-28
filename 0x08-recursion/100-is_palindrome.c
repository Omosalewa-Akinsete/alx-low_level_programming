#include "main.h"
/**
 * long_1 - Returns 1 if a string is a palindrome and 0 if not.
 * @s: The string to be printed.
 * Return: 0
 */

int long_1(char *s)
{
	if (*s != '\0')
	{
		return (1 + long_1(s + 1));
	}
	return (0);

}
/**
 * compare - Returns 1 if a string is a palindrome and 0 if not.
 * @s: The string to be printed.
 * @l: The string to be printed.
 * Return: 0
 */
int compare(char *s, int l)
{
	if (l <= 0)
	{
		return (1);
	}
	if (*s == *(s + (l - 1)))
	{
		return (compare(s + 1, l - 2));
	}
	else
	{
		return (0);
	}
}

/**
 * is_palindrome - Returns 1 if a string is a palindrome and 0 if not.
 * @s: The string to be printed.
 * Return: 0
 */
int is_palindrome(char *s)
{
	int l;

	l = long_1(s);
	return (compare(s, l));
}
