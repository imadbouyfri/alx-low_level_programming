#include "main.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * print_binary - a function ....
 * @n: the chaine of caractere
 *
 * Return: 1 or 0
 */
void print_binary(unsigned long int n)
{
int i, count = 0;
	unsigned long int current;

	for (i = 63; i >= 0; i--)
	{
		current = n >> i;

		if (current & 1)
		{
			_putchar('1');
			count++;
		}
		else if (count)
			_putchar('0');
	}
	if (!count)
		_putchar('0');


}
