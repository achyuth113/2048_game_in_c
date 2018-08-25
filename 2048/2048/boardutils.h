#include "userutils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int convertint(char *s){
	int num = 0, i = 10, j = 0;

	while (s[j] != '\0'){
		num *= i;
		num += (s[j++] - '0');
	}
	return num;
}

int contains(char* s1, char* s2){
	int i = 0, j = 0;
	int flag = 0;
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	while (i < l1){
		if (s1[i] == s2[j]){
			int i1 = i, j1 = j;
			while (i1<l1&&j1<l2&&s1[i1] == s2[j1]){
				i1++; j1++;
			}
			if (j1 == l2)return 0;
		}
		i++;
	}
	return 2;
}

char** tokenize(char *s, int *len){
	char **s1; int count = 1;
	s1 = (char**)calloc(1000, sizeof(char*));
	int i = 0, j = 0, k = 0;
	char **s2;
	int count2 = 0;

	for (i = 0; i < 1000; i++)s1[i] = (char*)calloc(1000, sizeof(char));
	i = 0, j = 0, k = 0;
	while (s[i] != '\0'){
		if (s[i] == ','){
			count++; j++; k = 0;
			i++;
		}
		else{
			char ch = s[i++];
			s1[j][k++] = ch;
		}
	}
	s2 = (char**)calloc(1000, sizeof(char*));
	for (int x = 0; x < count; x++){
		if (s1[x][0] != '\0'){
			s2[count2] = (char*)calloc(1000, sizeof(char));
			strcpy(s2[count2], s1[x]); count2++;
		}
	}
	*len = count2;
	return s2;

}



User * createUser(char *name){
	if (name == NULL)return NULL;
	struct User *sai;
	sai = (struct User *)malloc(sizeof(struct User));
	sai->name = (char*)calloc(1000, sizeof(char));
	strcpy(sai->name, name);
	sai->movesCount = 0;
	return sai;
}
char** tokenize1(char *s, int *len){
	char **s1; int count = 1;
	s1 = (char**)calloc(1000, sizeof(char*));
	int i = 0, j = 0, k = 0;
	char **s2;
	int count2 = 0;

	for (i = 0; i < 1000; i++)s1[i] = (char*)calloc(1000, sizeof(char));
	i = 0, j = 0, k = 0;
	while (s[i] != '\0'){
		if (s[i] == ',' || s[i] == '\n'){
			s1[j][k++] = '\0';
			count++; j++; k = 0;
			i++;
		}
		else{
			char ch = s[i++];
			s1[j][k++] = ch;
		}
	}
	s2 = (char**)calloc(1000, sizeof(char*));
	int x;
	for (x = 0; x < count; x++){
		if (s1[x][0] != '\0'){
			s2[count2] = (char*)calloc(1000, sizeof(char));
			strcpy(s2[count2], s1[x]); count2++;
		}
	}
	*len = count2;
	return s2;

}


int checkUser(char *name, char* pass){
	int length = 0;
	int i;
	char *ch;
	char *s, **buffer;
	s = (char*)calloc(300, sizeof(char));
	buffer = (char**)calloc(300, sizeof(char*));
	FILE* fp = fopen("user.csv", "r");
	if (fp == NULL){
		printf("File has no data");
		return -1;
	}
	i = 0;
	while ((ch = fgets(s, 100, fp)) != NULL){
		buffer[i] = (char*)calloc(200, sizeof(char));
		strcpy(buffer[i], ch); i++;
	}
	length = i;
	int t;
	for (i = 0; i < length - 1; i++){
		char** t1 = tokenize1(buffer[i], &t);
		if (strcmp(name, t1[0]) == 0){
			if (strcmp(pass, t1[1]) == 0)return 1;
		}
	}
	fclose(fp);
	return 0;
}

void modifyMoveCountBasedOnProccessInput(User *user, int processInputOutCome){
	if (processInputOutCome == 1)
	{
		//user->movesCount++;
	}
}

void printUser(User *user){
	printf("\n USER PRINTING NOT IMPLEMENTED YET \n");
	printf("Hey %s , You have playede %d Moves\n", user->name, user->movesCount);
}

Board * createBoard(int rows, int cols){
	if (rows <= 0 || cols <= 0)
		return NULL;
	Board *board;
	int i;
	board = (Board*)malloc(sizeof(Board));
	int **table;
	table = (int**)calloc(rows, sizeof(int*));
	for (i = 0; i<rows; i++)
		table[i] = (int *)calloc(cols, sizeof(int));
	board->table = table;
	board->rows = rows;
	board->cols = cols;
	return board;
}

void initializeBoard(Board * source){
	int i = rand() % source->rows;
	int j = rand() % source->cols;
	int i1 = rand() % source->rows;
	int j1 = rand() % source->cols;
	while ((i1 == i) && (j1 == j)){
		i = rand() % source->rows;
		j = rand() % source->cols;
		i1 = rand() % source->rows;
		j1 = rand() % source->cols;
	}
	source->table[i][j] = 2;
	source->table[i1][j1] = 2;
}

void drawBoardOnScreen(Board *board){
	int i, j;
	printf("\n\n");
	for (i = 0; i<board->rows; i++)
	{
		for (j = 0; j < board->cols; j++)
		{
			if (board->table[i][j] != 0)printf("%4d|", board->table[i][j]);
			else{
				printf("    |");
			}
		}
		printf("\n");
	}
	printf("\n\n----------[W] UP --- [S] Down --- [A] LEFT ---------- [D] Right---------[Z]save&Exit-----------[E]EXIT---------\n");
}

void clearScreen(){
	system("cls");
}

void clearAndRedrawScreen(Board * board){
	clearScreen();
	drawBoardOnScreen(board);
}
