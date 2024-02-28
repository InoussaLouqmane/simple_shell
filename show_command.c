#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char **split_(char *ptr, int *counter)
{
	char **table_char;
	int i = 0;

	if (ptr == NULL)
	{
		return (NULL);
	}

	/*let's count number of words we have*/
	
	while(ptr[i] != '\0')
	{
		if (ptr[i] == 32)
			(*counter)++;
		i++;
	}

	/*Let's allocate memory for our table*/

	table_char = malloc(sizeof(char *) * (*counter));

	if (table_char == NULL)
		return (NULL);
	/*Let's start cutting the initial string*/

	char *str = strtok(ptr, " ");

	if (str == NULL)
	{
		return (NULL);
	}

	i = 0;

	while (str != NULL)
	{
		table_char[i] = strdup(str);

		/* Allocation Failure Management */

		if (table_char[i] == NULL)
		{
			for (int j = 0; j < i; j++)
			{
				free(table_char[j]);
			}
			free(table_char);
			return (NULL);
		}
		i++;
		str = strtok(NULL, " ");
	}

	//free(table_char);
	return (table_char);
}

int main (int ac, char **argv)
{
	int i = 1;
	char *ptr = NULL;
	size_t len = 0;	
	ssize_t nread = 0;
	char **table_char;
	int array_size = 1;

	printf("$ ");
	
	while (argv[i] != NULL)
	{
		printf("%s\n", argv[i]);
		i++;
	}

	nread = getline(&ptr, &len, stdin);

	if (nread == -1)
	{
		free(ptr);
		return (0);
	}

	table_char = split_(ptr, &array_size);

	if (table_char == NULL)
	{
		free(ptr);
		printf("\nOops ! Something went wrong !\n");
		return (0);
	}

	/* Calculating array size*/

	/*Printing and freeing each element*/
	for (i = 0; i < array_size; i++)
	{
		printf("%s\n", *(table_char + i));
		free(table_char[i]);
	}

	free(ptr);
	free(table_char);
	return (0);
}
