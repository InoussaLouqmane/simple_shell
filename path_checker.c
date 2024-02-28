#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

void check_command(char *command)
{
	if (access(command, F_OK) == 0)	
	{
		printf("%s : FOUND\n", command);
	}
	else
		printf("%s : NOT FOUND\n", command);
}
int main (void)
{
	size_t len = 0;
	ssize_t nread = 0;
	char *ptr = NULL;
	char *command;
	char *token;
	int i = 0;
	i = 1;

	while(1)
	{
		printf("\nLOUQISFUN$ ");

		if (getline(&ptr, &len, stdin) == -1)
		{
			perror("Oops ! Something went wrong with getline");
			free(ptr);
			exit(EXIT_FAILURE);
		}

		token = strtok(ptr, " \t\n");

		if (token == NULL)
		{
			free(ptr);
			perror("Oops! strtok() went wrong !\n");
			exit(EXIT_FAILURE);
		}
		if (strcmp(token, "_which") == 0)
		{
			while (token != NULL)
			{
				token = strtok(NULL, " \t\n");

				if (token != NULL)
				{
					check_command(token);
				}
			}
		}
		else if (strcmp(token, "exit") == 0)
		{
			printf("\nExit...\n");
			break;
		}
		else
		{
			printf("unknown command\n");
		}
	}
	free(ptr);
	return (1);
}
