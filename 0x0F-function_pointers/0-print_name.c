#include "function_pointers.h"

/**
 * print_name - a function that prints a name.
 * @name: name of the person
 * @f: variable to hold string name
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;
	f(name);
}
