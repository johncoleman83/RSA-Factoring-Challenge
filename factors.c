#include "factors.h"
/**
 * _strlen - returns string length of input string
 * @s: string to check length of
 * Return: length of string
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * read_textfile - reads a text file and prints it to the POSIX stdout
 * @filename: the file
 * Return: actual number of letters it could read and print
 */
void read_textfile(const char *filename, char *buffer)
{
	int fd;
	ssize_t letters, letters2;

	letters = _strlen(buffer);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buffer = malloc(sizeof(char) * letters);
	if (buffer == NULL)
		return (0);
	if (read(fd, buffer, letters) == -1)
	{
		free(buffer);
		return (0);
	}
}

/**
 * _calloc - allocates memory for an array using malloc
 * @nmemb: elements of memory needed
 * @size: size in bytes of each element
 * Return: pointer to the allocated memory
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i;
	char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size >= UINT_MAX / nmemb || nmemb >= UINT_MAX / size)
		return (NULL);
	p = malloc(size * nmemb);
	if (p == NULL)
		return (NULL);
	for (i = 0; i < nmemb * size; i++)
		p[i] = 0;
	return ((void *)p);
}

/**
 * main - finds factors of input file
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: 0 always Success
 */
int *_split(char *buffer)
{
	int i = 0, j = 0, l = 0;
	char **numbers;
	char *num;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			l++;
		i++;
	}
	numbers = _calloc(l, sizeof(int));
	i = 0;
	while (buffer[i] != '\0')
	{
		for(j = 0; buffer[i] != '\n'; j++)
			;
		i = j + 1;
		num = _calloc(j, sizeof(int));
		for(j = 0; buffer[j] != '\n'; j++)
			;

		
	}

}

/**
 * main - finds factors of input file
 * @argc: arguments count
 * @argv: arguments
 *
 * Return: 0 always Success
 */
int main(int argc, char **argv)
{
	char *filename = argv[1], *buffer;
	int *numbers;

	buffer = _calloc(BUFSIZE, sizeof(char));
	read_textfile(filename, buffer);
	numbers = _split(buffer);
}
