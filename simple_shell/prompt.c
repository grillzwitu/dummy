#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry Point
 *
 * Description: Prompts for string input and prints it in stdout
 *
 * Return: 0(Success)
 */

int main()
{
	char *buffer;
	size_t bufsize = 32;
	size_t characters;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("$: ");
	characters = getline(&buffer,&bufsize,stdin);
	printf("%u characters were read.\n", (unsigned) sizeof(characters));
	printf("%s",buffer);
	(void) characters;

	free(buffer);
	return(0);
}
