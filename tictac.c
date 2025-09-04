#include <stdio.h> 

void menu(){
    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n\n");
}

//Intialize the board with empty spaces
void initializeBoard(char board[][10],int size){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            board[row][col] = ' ';
        }
    }
}

//Function to print the board
void printboard(char board[][10], int size){
    //Print column headers
    printf("    ");
    for(int col = 0; col < size; col++){
        printf("%d   ", col);
    }
    printf("\n");

    //Prints a horizontal border under column headers
    for(int row = 0; row < size; row++){
        printf("  ");
        for(int col = 0; col < size; col++){
        printf("----");
        }
    printf("-\n");
    

    printf("%d ", row);//Prints row number at the beginning of each row
        //Prints each cell in the row with vertical borders
    for (int col = 0; col < size; col++) {
        printf("| %c ", board[row][col]);
        }
        printf("|\n");
    }
    
    //Print bottom border
    printf("  ");
    for(int col = 0; col < size; col++){
        printf("----");
    }
    printf("-\n");
}

int main(){

    menu();
    int size;
    char board[10][10];

    printf("Enter the size of the board (3-10): ");
    scanf("%d", &size);

    if(size < 3 || size > 10){
        printf("Invalid board size! Please enter a number between 3 and 10.\n");
        return 1;
    }

    initializeBoard(board, size);
    printboard(board, size);

    return 0;
}


