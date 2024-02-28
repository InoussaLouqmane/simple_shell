#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>

int main (void)
{
	pid_t child_id;
	size_t len = 0;
	char *ptr = NULL;
	ssize_t nread = 0;
	char **argv;
	int status;

	argv = malloc(sizeof(char *) * 2);

	if (argv == NULL)
		return (1);

	printf("\n");

	child_id = fork();

	if (child_id == -1)
		return (1);

	if (child_id == 0)
	{
			printf("\n#shell_of_louq$ ");
			nread = getline(&ptr, &len, stdin);

			if (nread == -1)
			{
				free (ptr);
				perror("Oops getline went wrong ! :");
				exit(EXIT_FAILURE);
			}
			*(ptr + nread -1) = '\0';
			argv[0] = ptr;
			argv[1] = NULL;

			if((execve(argv[0], argv, NULL)) == -1)
			{
				perror("Oops execve went wrong ! :");
				free(argv[0]);
				exit(EXIT_FAILURE);
			}

	}
	else
	{
		wait(&status);
	}

	free(argv);
	return (0);
}
