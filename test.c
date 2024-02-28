#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (void)
{
	int status;
	int i = 0;
	pid_t child_pid;
	char *argv[] = {"/bin/ls", NULL};

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();
		if (child_pid == -1)
			return (1);


		if (child_pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror("Oops ! Something went wrong !");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(&status);
			printf("\n\n\n====================================================================================================================\n\n\n");
		}
	}

	return (0);
}
