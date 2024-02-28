#include <stdio.h>
#include <stdlib.h>

extern char **environ;

int main(int ac __attribute__((unused)), char **argv, char **env)
{
	printf("env address: %p\n", &env);
	printf("environ address: %p\n", &environ);

		return (0);
}
