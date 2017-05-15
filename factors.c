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
int read_textfile(const char *filename, char *buffer)
{
	int fd;
	ssize_t letters, letters2;

	letters = BUFSIZE;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	read(fd, buffer, letters);
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
 * _split - splits string by newlines
 * @buffer: buffer to split to numbers
 *
 * Return: 0 always Success
 */
char **_split(char *buffer)
{
	int i = 0, j = 0, numtotal = 0, len, start;
	char **numbers;
	char *num;

	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
			numtotal++;
		i++;
	}
	numbers = _calloc(numtotal + 1, sizeof(char *));
	i = 0;
	while (buffer[i] != '\0')
	{
		start = i, len = 0;
		for(len = 0; buffer[i] != '\n'; i++)
			len++;
		num = _calloc(len + 1, sizeof(char));
		for(i = start, len = 0; buffer[i] != '\n'; i++, len++)
			num[len] = buffer[i];
		num[len] = '\0';
		numbers[j++] = num;
		i++;
	}
	numbers[j] = NULL;
	return (numbers);
}

/**
 * _atoi - returns integer values from string
 * @s: input string
 *
 * Return: will return integer
 */
int _atoi(char *s)
{
	int result = 0, sign = 0, c;

	for (c = 0; s[c] != '\0'; c++)
	{
		if (s[c] == '-')
			sign++;
		if (s[c] > 47 && s[c] < 58)
		{
			while (s[c] > 47 && s[c] < 58)
				result = result * 10 - (s[c++] - 48);
			break;
		}
	}
	return (result *= sign % 2 == 0 ? -1 : 1);
}

/**
 * print_numbers - returns integer values from string
 * @s: input string
 *
 * Return: will return integer
 */
void print_factors(char **numbers)
{
	int i = 0, num, p, q;

	while (numbers[i])
	{
		num = _atoi(numbers[i]);
		q = 2;
		while (1)
		{
			p = num / q;
			if (p * q == num)
				break;
			if (q > num / 2)
			{
				q = 1, p = num;
				break;
			}
			q++;
		}
		printf("%d=%d*%d\n", num, p, q);
		i++;
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
	char *filename = argv[1], *buffer, **numbers;

	buffer = _calloc(BUFSIZE, sizeof(char));
	read_textfile(filename, buffer);
	numbers = _split(buffer);
	print_factors(numbers);
	return (0);
}
