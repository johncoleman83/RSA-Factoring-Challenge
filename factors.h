#ifndef _FACTORS_H_
#define _FACTORS_H_
#define BUFSIZE 1024
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int _strlen(char *s);
void read_textfile(const char *filename, char *buffer);
void *_calloc(unsigned int nmemb, unsigned int size)
#endif
