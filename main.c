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
	init(&v, argv[0]);
	_exec(&v);
	return (0);
}
