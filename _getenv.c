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
					str = strtok(NULL, " \n\t");
					if (str != NULL)
					{
						while (env[i] != NULL)
						{
							found = 0;
							env_str = strtok(env[i], "=");
							if (env_str == NULL)
							{
								free(str);
								free(ptr);
								perror("failed to read env");
								exit(EXIT_FAILURE);
							}

							if (strcmp(env_str, str) == 0)
							{
								env_str = strtok(NULL, "\0");
								if (env_str != NULL)
								{
									found = 1;
									printf("%s=%s", str, env_str);
									free(env_str);
									break;
								}
							}
							i++;
						}
					
						if (found == 0)
							printf("\n%s : VARIABLE NOT FOUND!", str);

					}
			}
			else if (strcmp(str, "exit") == 0)
			{
				free(str);
				free(ptr);
				break;
			}
			else
			{
				printf("Unknown Command\n");
			}
		}
	free(str);
	free(ptr);
	return (0);
}
