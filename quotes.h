// quotes.h
#ifndef QUOTES_H
#define QUOTES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_QUOTES 10
#define MAX_LENGTH 256

void print_quote(char **quotes, int index);
void print_random_quote(char **quotes, int count);
void add_quote(char **quotes, int *count, char *new_quote);
void remove_quote(char **quotes, int *count, int index);
void display_quotes(char **quotes, int count);
void menu(char **quotes, int *count);

#endif // QUOTES_H