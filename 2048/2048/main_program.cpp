#include "moves.h"

void perform(struct User* user, Board* board){
	
	clearAndRedrawScreen(board);
	int num = 1;
	while (num > 0){
		char ch = takeInput();
		num = processInput(user, board, ch);
		if (num < 0)return;
		if (checkState(board) == -1){
			printf("%s You won the game in %d moves", user->name, user->movesCount);
			return;
		}
		else{
			if (hasMove(board) == -1){
				giveAMove(board);
			}
			else{
				printf("you lost the game"); return;
			}
		}
		clearAndRedrawScreen(board);
	}

}
void perform1(User* name){
	int x=1,choice;
	while (x == 1){
		printf("\nPress \n1 for new game\n2 for saved games\n3 for leader board\n-1 for exit\n");
		scanf("%d", &choice);
		if (choice == -1){
			x = -1;
		}
		else if (choice == 1){
			struct Board* board = createBoard(4, 4);
			initializeBoard(board);
			perform(name, board);
		}
		else if (choice == 2){
			int length = 0;
			char** b = get_board(name,&length);
			Board* board=get_the_game(name,b,length);
			perform(name, board);
		}
		else if (choice == 3){
			//show_leader();
		}
	}
}

int main(){
	char *username, *password;
	password = (char*)calloc(1000, sizeof(char));
	username = (char*)calloc(1000, sizeof(char));

lable:printf("\nEnter Username and password:\n");
	scanf("%s%s", username, password);
	if (checkUser(username, password) == 1){
		struct User* name = createUser(username);
		printf("Hello %s Welcome to 2048 world", name->name);
		struct Board* board = createBoard(4, 4);
		initializeBoard(board);
		perform1(name);
		goto lable;
	}
	else if(strcmp(username,"new")==0){
		createUser1();
		goto lable;
	}
	else{
		goto lable;
	}
	return 0;
}