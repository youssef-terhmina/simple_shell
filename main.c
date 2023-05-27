#include "head.h"

/**
 * main - init data
 * @argc: input size of @argv
 * @argv: input array of command line arguments
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	value v;
	(void)argc;
	init_data(&d, argv[0]);
	_exec(&d);
	return (0);
}
