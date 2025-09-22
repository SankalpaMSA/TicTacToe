#include <stdio.h>
#include <stdbool.h>

void menu(){
    printf("Welcome to Tic Tac Toe!\n");
    printf("-----------------------\n\n");
}

// Initialize the board with empty spaces
void initializeBoard(char board[][10], int size){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            board[row][col] = ' ';
        }
    }
}

// Function to print the board
void printboard(char board[][10], int size){
    // Print column headers
    printf("    ");
    for(int col = 0; col < size; col++){
        printf("%d   ", col);
    }
    printf("\n");

    // Print board with row numbers and cell contents
    for(int row = 0; row < size; row++){
        // Print horizontal border
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
    
    // Print bottom border
    printf("  ");
    for(int col = 0; col < size; col++){
        printf("----");
    }
    printf("-\n");
}

// Check if a move is valid
bool isValidMove(char board[][10], int size, int row, int col){
    if(row < 0 || row >= size || col < 0 || col >= size){
        return false;
    }
    if(board[row][col] != ' '){
        return false;
    }
    return true;
}

// Make a move on the board
void makeMove(char board[][10], int size, int row, int col, char player){
    board[row][col] = player;
}

// Check for a win condition
bool checkWin(char board[][10], int size, char player){
    // Check rows
    for(int row = 0; row < size; row++){
        bool win = true;
        for(int col = 0; col < size; col++){
            if(board[row][col] != player){
                win = false;
                break;
            }
        }
        if(win) return true;
    }

    // Check columns
    for(int col = 0; col < size; col++){
        bool win = true;
        for(int row = 0; row < size; row++){
            if(board[row][col] != player){
                win = false;
                break;
            }
        }
        if(win) return true;
    }

    // Check main diagonal (top-left to bottom-right)
    bool win = true;
    for(int i = 0; i < size; i++){
        if(board[i][i] != player){
            win = false;
            break;
        }
    }
    if(win) return true;

    // Check secondary diagonal (top-right to bottom-left)
    win = true;
    for(int i = 0; i < size; i++){
        if(board[i][size-1-i] != player){
            win = false;
            break;
        }
    }
    if(win) return true;

    return false;
}

// Check if the board is full (draw condition)
bool isBoardFull(char board[][10], int size){
    for(int row = 0; row < size; row++){
        for(int col = 0; col < size; col++){
            if(board[row][col] == ' '){
                return false;
            }
        }
    }
    return true;
}

int main(){
    menu();
    int size;
    char board[10][10];
    char currentPlayer = 'X';
    int row, col;
    bool gameOver = false;

    // Get board size
    printf("Enter the size of the board (3-10): ");
    scanf("%d", &size);

    if(size < 3 || size > 10){
        printf("Invalid board size! Please enter a number between 3 and 10.\n");
        return 1;
    }

    initializeBoard(board, size);

    // Game loop
    while(!gameOver){
        printboard(board, size);
        printf("Player %c's turn. Enter row and column (e.g., 0 1): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Validate move
        if(!isValidMove(board, size, row, col)){
            printf("Invalid move! Try again.\n");
            continue;
        }

        // Make move
        makeMove(board, size, row, col, currentPlayer);

        // Check for win
        if(checkWin(board, size, currentPlayer)){
            printboard(board, size);
            printf("Player %c wins!\n", currentPlayer);
            gameOver = true;
            continue;
        }

        // Check for draw
        if(isBoardFull(board, size)){
            printboard(board, size);
            printf("It's a draw!\n");
            gameOver = true;
            continue;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}
