#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(int ac, char **argv, char **env)
{
	char *ptr = NULL;
	size_t len = 0;
	ssize_t nread = 0;
	char *str = NULL;
	int i = 0;
	char *env_str = NULL;
	int found = 0;


		while(1)
		{
			printf("CIDFUN$ ");

			if (getline(&ptr, &len, stdin) == -1)
			{
				perror("Oops ! getline went wrong !");
				free(ptr);
				return (0);
			}

			str = strtok(ptr, " \t\n");
			if (str == NULL)
			{
				perror("OOps, erros in strtok");
				free(ptr);
				exit(EXIT_FAILURE);
			}
			if (strcmp(str, "echo") == 0)
			{
				while (str != NULL)
				{
					str = strtok(NULL, " \n\t");
					if (str != NULL)
					{
						while (env[i] != NULL)
						{
							found = 0;
							env_str = strstr(env[i], str);
							if (env_str == NULL)
							{
								free(str);
								free(ptr);
								perror("failed to read env");
								exit(EXIT_FAILURE);
							}
							else if (env_str != NULL)
							{
								if (*env_str 
							}
							i++;
						}
						if (found == 0)
							printf("\n%s : VARIABLE NOT FOUND!", str);
					}
				}
				free(ptr);
				free(env_str);
			}
			else if (strcmp(str, "exit") == 0)
			{
				free(str);
				free(ptr);
				return (0);
			}
			else
			{
				printf("Unknown Command\n");
			}
		}
	return (0);
}
