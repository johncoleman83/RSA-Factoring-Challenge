#ifndef _FACTORS_H_
#define _FACTORS_H_
#define BUFSIZE 1024
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int _strlen(char *s);
int read_textfile(const char *filename, char *buffer);
void *_calloc(unsigned int nmemb, unsigned int size);
void print_factors(char **numbers);
int _atoi(char *s);
char **_split(char *buffer);
#endif
