#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct User{
	char *name;
	int rsize;
	int csize;
	int movesCount;
}User;
User **U = NULL;
int Ulength = 0;


typedef struct leaders{
	char *name;
	int moves;
	char *date;
}Leader;

Leader **l;

typedef struct Board {
	int **table;
	int rows;
	int cols;
}Board;

