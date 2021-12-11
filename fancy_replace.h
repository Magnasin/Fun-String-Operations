#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef code_fancy_replace_h
#define code_fancy_replace_h

void wildCard(char *str, char *a, int *occur, int *size);
char *fancy_replace(char *str, char *a, char *b);

#endif
