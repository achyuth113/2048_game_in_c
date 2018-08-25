#include "boardutils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>


int isValidInput(char letter);
int goLeft(Board *board);
int goUp(Board *board);
int goDown(Board *board);
int goRight(Board *board);
int checkState(Board *board);


int goLeft(Board *board){
	int j;
	int flag = -1;
	for (j = 0; j < board->rows; j++){
		int num1 = board->table[j][0];
		int num2 = board->table[j][1];
		int num3 = board->table[j][2];
		int num4 = board->table[j][3];
		if (num1 == 0){
			if (num2 != 0){ num1 = num2; num2 = 0; }
			else if (num3 != 0){ num1 = num3; num3 = 0; }
			else if (num4 != 0){ num1 = num4; num4 = 0; }
		}
		if (num2 == 0){
			if (num3 != 0){ num2 = num3; num3 = 0; }
			else if (num4 != 0){ num2 = num4; num4 = 0; }
		}
		if (num3 == 0){
			if (num4 != 0){ num3 = num4; num4 = 0; }
		}
		if ((num1 != 0 && num2 != 0) && num1 == num2){
			num1 += num2;
			num2 = 0; flag = 1;
		}
		if ((num3 != 0 && num2 != 0) && num2 == num3){
			num2 += num3;
			num3 = 0; flag = 1;
		}
		if ((num4 != 0 && num3 != 0) && num3 == num4){
			num3 += num4;
			num4 = 0; flag = 1;
		}
		int k = 0;
		if (num1 != 0){
			board->table[j][k++] = num1;
		}
		if (num2 != 0){
			board->table[j][k++] = num2;
		}
		if (num3 != 0){
			board->table[j][k++] = num3;
		}
		if (num4 != 0){
			board->table[j][k++] = num4;
		}
		while (k<board->cols){
			board->table[j][k++] = 0;
		}
	}

	if(flag==1)return 2;
	return 1;
}
int goRight(Board *board){
	int j;
	int flag = -1;
	for (j = 0; j < board->rows; j++){
		int num4 = board->table[j][0];
		int num3 = board->table[j][1];
		int num2 = board->table[j][2];
		int num1 = board->table[j][3];
		if (num1 == 0){
			if (num2 != 0){ num1 = num2; num2 = 0; }
			else if (num3 != 0){ num1 = num3; num3 = 0; }
			else if (num4 != 0){ num1 = num4; num4 = 0; }
		}
		if (num2 == 0){
			if (num3 != 0){ num2 = num3; num3 = 0; }
			else if (num4 != 0){ num2 = num4; num4 = 0; }
		}
		if (num3 == 0){
			if (num4 != 0){ num3 = num4; num4 = 0; }
		}
		if (num1 == num2){
			num1 += num2;
			num2 = 0; flag = 1;
		}
		if (num2 == num3){
			num2 += num3;
			num3 = 0; flag = 1;
		}
		if (num3 == num4){
			num3 += num4;
			num4 = 0; flag = 1;
		}
		int k = board->cols - 1;
		if (num1 != 0){
			board->table[j][k--] = num1;
		}
		if (num2 != 0){
			board->table[j][k--] = num2;
		}
		if (num3 != 0){
			board->table[j][k--] = num3;
		}
		if (num4 != 0){
			board->table[j][k--] = num4;
		}
		while (k >= 0){
			board->table[j][k--] = 0;
		}
	}

	if (flag == 1)return 2;
	return 1;
}

int goUp(Board *board){
	int j;
	int flag = -1;
	for (j = 0; j < board->cols; j++){
		int num1 = board->table[0][j];
		int num2 = board->table[1][j];
		int num3 = board->table[2][j];
		int num4 = board->table[3][j];
		if (num1 == 0){
			if (num2 != 0){ num1 = num2; num2 = 0; }
			else if (num3 != 0){ num1 = num3; num3 = 0; }
			else if (num4 != 0){ num1 = num4; num4 = 0; }
		}
		if (num2 == 0){
			if (num3 != 0){ num2 = num3; num3 = 0; }
			else if (num4 != 0){ num2 = num4; num4 = 0; }
		}
		if (num3 == 0){
			if (num4 != 0){ num3 = num4; num4 = 0; }
		}
		if (num1 == num2){
			num1 += num2;
			num2 = 0; flag = 1;
		}
		if (num2 == num3){
			num2 += num3;
			num3 = 0; flag = 1;
		}
		if (num3 == num4){
			num3 += num4;
			num4 = 0; flag = 1;
		}
		int k = 0;
		if (num1 != 0){
			board->table[k++][j] = num1;
		}
		if (num2 != 0){
			board->table[k++][j] = num2;
		}
		if (num3 != 0){
			board->table[k++][j] = num3;
		}
		if (num4 != 0){
			board->table[k++][j] = num4;
		}
		while (k<4){
			board->table[k++][j] = 0;
		}
	}

	if(flag==1)return 2;
	return 1;
}

int goDown(Board *board){
	int j;
	int flag = -1;
	for (j = 0; j < board->cols; j++){
		int num1 = board->table[3][j];
		int num2 = board->table[2][j];
		int num3 = board->table[1][j];
		int num4 = board->table[0][j];
		if (num1 == 0){
			if (num2 != 0){ num1 = num2; num2 = 0; }
			else if (num3 != 0){ num1 = num3; num3 = 0; }
			else if (num4 != 0){ num1 = num4; num4 = 0; }
		}
		if (num2 == 0){
			if (num3 != 0){ num2 = num3; num3 = 0; }
			else if (num4 != 0){ num2 = num4; num4 = 0; }
		}
		if (num3 == 0){
			if (num4 != 0){ num3 = num4; num4 = 0; }
		}

		if (num1 == num2){
			num1 += num2;
			num2 = 0; flag = 1;
		}
		if (num2 == num3){
			num2 += num3;
			num3 = 0; flag = 1;
		}
		if (num3 == num4){
			num3 += num4;
			num4 = 0; flag = 1;
		}
		int k = board->rows - 1;
		if (num1 != 0){
			board->table[k--][j] = num1;
		}
		if (num2 != 0){
			board->table[k--][j] = num2;
		}
		if (num3 != 0){
			board->table[k--][j] = num3;
		}
		if (num4 != 0){
			board->table[k--][j] = num4;
		}
		while (k >= 0){
			board->table[k--][j] = 0;
		}
	}

	if(flag==1)return 2;
	return 1;
}

int checkState(Board *board){
	int i, j;
	for (i = 0; i < board->rows; i++){
		for (j = 0; j < board->cols; j++){
			if (board->table[i][j] == 2048){
				return -1;
			}
		}
	}
	return 1;
}

int hasMove(Board *board){
	int i, j;
	for (i = 0; i < board->rows; i++){
		for (j = 0; j < board->cols; j++){
			if (board->table[i][j] == 0){
				return -1;
			}
		}
	}
	int arr[4][4];
	for (i = 0; i < board->rows; i++){
		for (j = 0; j < board->cols; j++){
			arr[i][j] = board->table[i][j];
		}
	}
	int flag = -1;
	if (goLeft(board) == 2){
		flag = 1;
	}
	else if (goDown(board) == 2){
		flag = 1;
	}
	else if (goRight(board) == 2){
		flag = 1;
	}
	else if (goUp(board) == 2){
		flag = 1;
	}
	if (flag == 1){
		for (i = 0; i < board->rows; i++){
			for (j = 0; j < board->cols; j++){
				board->table[i][j] = arr[i][j];
			}
		}
		return -1;
	}
	return 1;

}


void giveAMove(Board* board){
	int i = rand() % board->rows;
	int j = rand() % board->cols;
	while (board->table[i][j] != 0){
		i = rand() % board->rows;
		j = rand() % board->cols;
	}
	board->table[i][j] = 2;
}

char takeInput()
{
	char ch;
	do{
		fflush(stdin);
		scanf("%c", &ch);
	} while (isValidInput(ch));
	return ch;
}

int isValidInput(char letter){
	char z = letter;
	if (z == 'e' || z == 'E' || z == 'w' || z == 'a' || z == 's' || z == 'd' || z == 'W' || z == 'A' || z == 'S' || z == 'D' || z == 'z' || z == 'Z')
		return 0;
	else
		return 1;
}
char* convertint(int n){
	if (n == 0){
		return "0\0";
	}
	char *num;
	num = (char*)calloc(1000, sizeof(char));
	int j = 0;
	while (n>0){
		int k = n % 10;
		num[j++] = k + '0';
		n /= 10;
	}
	num[j++] = '\0';
	return _strrev(num);
}


void saveGame(User *user, Board *board){
	int length = 0;
	int i;
	char *ch;
	char *s, **buffer;
	s = (char*)calloc(300, sizeof(char));
	buffer = (char**)calloc(300, sizeof(char*));
	char *file;
	file = (char*)calloc(300, sizeof(char));
	file[0] = '\0';
	strcat(file, user->name);
	strcat(file, ".csv");
	FILE* fp = fopen(file, "r+");
	if (fp == NULL){
		printf("File has no data");
		return;
	}
	i = 0;
	while ((ch = fgets(s, 100, fp)) != NULL){
		buffer[i] = (char*)calloc(200, sizeof(char));
		strcpy(buffer[i], ch); i++;
	}
	length = i;
	strcat(buffer[i - 1], user->name);
	strcat(buffer[i - 1], ",");
	strcat(buffer[i - 1], convertint(user->movesCount));
	strcat(buffer[i - 1], ",");
	int x, y;
	for (x = 0; x<board->rows; x++){
		for (y = 0; y<board->cols; y++){
			strcat(buffer[i - 1], convertint(board->table[x][y]));
			strcat(buffer[i - 1], ",");
		}
	}
	strcat(buffer[i - 1], "end\n");
	printf("%s", buffer[i - 1]);
	fclose(fp);
	fp = fopen(file, "w");
	for (i = 0; i < length; i++){
		fputs(buffer[i], fp);
	}
	fclose(fp);

}


int processInput(User *user, Board *board, char inputChar)
{

	/*
	Handle the input char inputChar ,which is either w,a,s,d,W,A,S,D for up,left,down and right
	*/

	if (inputChar == 'E' || inputChar == 'e')return -1;
	else if (inputChar == 'Z' || inputChar == 'z'){
		saveGame(user, board);
		return -1;
	}
	else if (inputChar == 'A' || inputChar == 'a'){
		user->movesCount++;
		return goLeft(board);
	}
	else if (inputChar == 'd' || inputChar == 'D'){
		user->movesCount++;
		return goRight(board);
	}
	else if (inputChar == 'S' || inputChar == 's'){
		user->movesCount++;
		return goDown(board);
	}
	else if (inputChar == 'w' || inputChar == 'W'){
		user->movesCount++;
		return goUp(board);
	}
	return 0;
}

char** get_board(User* name,int *l){
	char** b = NULL;
	b = (char**)calloc(100, sizeof(char*));
	int count=0,i;
	int length = 0;
	char *ch;
	char *s, **buffer;
	s = (char*)calloc(300, sizeof(char));
	buffer = (char**)calloc(300, sizeof(char*));
	FILE* fp = fopen("achyuth.csv", "r");
	if (fp == NULL){
		printf("File has no data");
		return NULL;
	}
	i = 0;
	while ((ch = fgets(s, 100, fp)) != NULL){
		buffer[i] = (char*)calloc(200, sizeof(char));
		strcpy(buffer[i], ch); i++;
	}
	length = i;
	for (int i = 1; i < length; i++){
		if (contains(buffer[i], name->name) == 0){
			b[count] = (char*)calloc(1000, sizeof(char));
			strcpy(b[count], buffer[i]);
			count++;
		}
	}
	fclose(fp);
	*l = count;
	return b;
}

Board* get_the_game(User* name, char** b, int length){
	int i, j;
	Board* board;

	for (i = 0; i < length; i++){
		int len=0;
		char **t = tokenize(b[i], &len);
		printf("\nName:%s", t[0]);
		printf("\nMoves Count:%s", t[1]);
		board = (Board*)malloc(sizeof(Board));
		board->table = (int**)calloc(4, sizeof(int*));
		board->rows = 4;
		board->cols = 4;
		int c = 2;
		for (j = 0; j < 4; j++){
			board->table[j] = (int*)calloc(4, sizeof(int));
			board->table[j][0] = convertint(t[c++]);
			board->table[j][1] = convertint(t[c++]);
			board->table[j][2] = convertint(t[c++]);
			board->table[j][3] = convertint(t[c++]);
		}
		clearAndRedrawScreen(board);
		printf("\nyou want this game enter 1 else 0");
		scanf("%d", &c);
		if (c == 1){
			name->movesCount = convertint(t[1]);
			return board;
		}
	}
	printf("\n no game left");
	return NULL;
}



void createUser1(){
	int length = 0;
	int i;
	char *ch;
	char *s, **buffer;
	s = (char*)calloc(300, sizeof(char));
	buffer = (char**)calloc(300, sizeof(char*));
	FILE* fp = fopen("user.csv", "r+");
	FILE *fp1=NULL;
	if (fp == NULL){
		printf("File has no data");
		return;
	}
	i = 0;
	while ((ch = fgets(s, 100, fp)) != NULL){
		fp1 = fp;
		buffer[i] = (char*)calloc(200, sizeof(char));
		strcpy(buffer[i], ch); i++;
	}
	length = i;
	int t;
	fp = fp1;
	label1:char *name, *pass;
	name = (char*)calloc(300, sizeof(char));
	pass = (char*)calloc(300, sizeof(char));
	printf("\nwelcome new user  \nEnter username and password \n");
	scanf("%s%s", name, pass);
	for (i = 0; i < length - 1; i++){
		char** t1 = tokenize1(buffer[i], &t);
		if (strcmp(name, t1[0]) == 0){
			printf("\nThis username has already taken enter try new");
			goto label1;
		}
	}
	fputs(name, fp);
	fputs(",", fp);
	fputs(pass, fp);
	fputs("\n", fp);
	fclose(fp);
}