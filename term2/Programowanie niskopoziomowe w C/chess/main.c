#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <wchar.h>
#include <io.h>
#include <fcntl.h>

// Compiled with mingw-gcc on windows 10.

void intro(int x, int y);

void gotoxy(int x,int y)
{
    printf("%c[%d;%df",0x1B,y,x);
}

void drawBoard(int x, int y){
    for (int i = 0; i<8; i++){
        gotoxy(x, y+i);
        for (int j = 0; j<8; j++){
            if ((i+j) % 2 == 0)
                printf("\033[1;30;47m  \033[0m");
            else
                printf("\033[1;37;100m  \033[0m");
        }
        printf("\n\r");
    }
}

void drawLabels(int x, int y){
    for (int i = 0; i < 8; i++){
        gotoxy(x-1, y+i); printf("%d", 8-i);
        gotoxy(x+16, y+i); printf("%d", 8-i);
        gotoxy(x+2*i, y-1); printf("%c", 'A'+i);
        gotoxy(x+2*i, y+8); printf("%c", 'A'+i);
    }
}

typedef struct Piece {
    /* logic codes:
        0 - king
        1 - pawn
        2 - knight
        3 - bishop
        4 - rook
        5 - queen   */
    int logic;
    boolean isAlive;
    boolean isWhite;
} piece;

typedef struct BoardField {
    int x;
    int y;
    boolean empty;
    piece * p;
} field;

int printPiece(field f, int boardX, int boardY) {
    if (!f.p->isAlive) return 0;
    if (f.p == NULL) return 0;

    gotoxy(boardX + (f.x*2), boardY + f.y);
    
    if ((f.x + f.y) % 2 == 0) { // white field
        if (f.p->isWhite) printf("\033[1;34;47m");
        else printf("\033[1;31;47m");
    } else { // black field
        if (f.p->isWhite) printf("\033[1;34;100m");
        else printf("\033[1;31;100m");
    }

    switch (f.p->logic){
        case 0: printf("♚"); break;
        case 1: printf("♟"); break;
        case 2: printf("♞"); break;
        case 3: printf("♝"); break;
        case 4: printf("♜"); break;
        case 5: printf("♛"); break;
    }
    printf("\033[0m");
    return 0;
}

void setPieces(field board [8][8], int x, int y) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].p != NULL)
                printPiece(board[i][j], x, y);
        }
    }
}


int main(int argc, char *argv[]){
    system("cls");
    SetConsoleOutputCP(65001); // chess pieces support in console

    field board [8][8];
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            board[j][i].x = j;
            board[j][i].y = i;
        }
    }

    piece WhitePieces [16];
    piece BlackPieces [16];

    { // basic board setup
        // Common:
        for (int i = 0; i < 16; i++){
            WhitePieces[i].isAlive = TRUE;
            BlackPieces[i].isAlive = TRUE;
            WhitePieces[i].isWhite = FALSE;
            BlackPieces[i].isWhite = TRUE;
        }
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                board[j][i].p = NULL;
                
                if (i==0 || i==1 || i==6 || i==7)
                    board[j][i].empty = FALSE;
                else
                    board[j][i].empty = TRUE;
            }
        }
        
        // Kings:
            WhitePieces[8].logic = 0;
            BlackPieces[8].logic = 0;
            
            board[3][7].p = &WhitePieces[8];
            board[3][0].p = &BlackPieces[8];

        // Pawns:
        for (int i = 0; i < 8; i++){
            WhitePieces[i].logic = 1;
            BlackPieces[i].logic = 1;

            board[i][6].p = & WhitePieces[i];
            board[i][1].p = & BlackPieces[i];
        }
        // Knights:
        board[1][7].p = &WhitePieces[9];
        board[6][7].p = &WhitePieces[10];
        board[1][0].p = &BlackPieces[9];
        board[6][0].p = &BlackPieces[10];
        WhitePieces[9].logic = 2;
        WhitePieces[10].logic = 2;
        BlackPieces[9].logic = 2;
        BlackPieces[10].logic = 2;
        // Bishops:
        board[2][7].p = &WhitePieces[11];
        board[5][7].p = &WhitePieces[12];
        board[2][0].p = &BlackPieces[11];
        board[5][0].p = &BlackPieces[12];
        WhitePieces[11].logic = 3;
        WhitePieces[12].logic = 3;
        BlackPieces[11].logic = 3;
        BlackPieces[12].logic = 3;
        // Rooks:
        board[0][7].p = &WhitePieces[13];
        board[7][7].p = &WhitePieces[14];
        board[0][0].p = &BlackPieces[13];
        board[7][0].p = &BlackPieces[14];
        WhitePieces[13].logic = 4;
        WhitePieces[14].logic = 4;
        BlackPieces[13].logic = 4;
        BlackPieces[14].logic = 4;
        //Queens:
        board[4][7].p = &WhitePieces[15];
        board[4][0].p = &BlackPieces[15];
        WhitePieces[15].logic = 5;
        BlackPieces[15].logic = 5;
    }
    
    // chessboard position
    int boardX = 10;
    int boardY = 5;

    // colors:
{   printf("contrast: ");
    printf("\033[1;34;47m♚ \033[0m"); // white on white
    printf("\033[1;34;100m♚ \033[0m"); // white on black
    printf("\033[1;31;47m♚ \033[0m"); // black on white
    printf("\033[1;31;100m♚ \033[0m");} // black on black
    intro(50, 1);
    drawBoard(boardX, boardY);
    drawLabels(boardX, boardY);
    setPieces(board, boardX, boardY);
    

    // console:
    boolean turn = TRUE; // true - white, false - black
    while(TRUE) {
        
        int x = 40; // coordinates of console
        int y = 7;
        gotoxy(x-3,y-1);
        if (turn) printf("\033[1;34;40mblue\033[0m");
        else printf("\033[1;31;40mred \033[0m");
        char colLetter, rowNumber; // user input
        int row, col, rowD, colD; // piece addr and dest.
        boolean valid = TRUE;
        do { // get valid piece
            valid = TRUE;
            gotoxy(x, y); printf("                                      ");
            gotoxy(x, y+1); printf("                                      ");
            gotoxy(x, y+5); printf("                                      ");
            gotoxy(x, y); printf("choose piece: ");
            fflush(stdin);
            scanf("%c%c", &colLetter, &rowNumber);
            col = colLetter - 'A';
            row = 7 - (rowNumber - '1');
            printf("%d,%d",col,row);
            if (board[col][row].empty){
                gotoxy(x, y+4); printf("This field is empty!  ");
                valid = FALSE;
            } else if (board[col][row].p->isWhite != turn){
                gotoxy(x, y+4); printf("That's not your piece!");
                valid = FALSE;
            }
        } while (!valid);
        do { // get valid destination
            valid = TRUE;
            gotoxy(x, y+1); printf("                                      ");
            gotoxy(x, y+4); printf("                                      ");
            gotoxy(x, y+1); printf("choose destination: ");
            fflush(stdin);
            scanf("%c%c", &colLetter, &rowNumber);
            colD = colLetter - 'A';
            rowD = 7 - (rowNumber - '1');
            printf("%d,%d",rowD,colD);
            if (!board[colD][rowD].empty) {
                if (board[colD][rowD].p->isWhite == turn) {
                    gotoxy(x, y+5);
                    printf("This field is already occupied!");
                    valid = FALSE;
                }
            }
        } while (!valid);


        if (!board[colD][rowD].empty) {// TAKES!
            // possibly calculate score?
        }
        board[colD][rowD].p = board[col][row].p;
        board[col][row].p = NULL;
        board[col][row].empty = TRUE;
        board[colD][rowD].empty = FALSE;

        drawBoard(boardX,boardY);
        setPieces(board,boardX,boardY);
        turn = !turn;// next turn
    }

    gotoxy(1,20);
    return 0;
}

void intro(int x, int y) {
    gotoxy(x,y+0);    printf("  ____ _\n");
    gotoxy(x,y+1);    printf(" / ___| |__   ___  ___ ___\n");
    gotoxy(x,y+2);    printf("| |   | '_ \\ / _ \\/ __/ __|\n");
    gotoxy(x,y+3);    printf("| |___| | | |  __/\\__ \\__ \\\n");
    gotoxy(x,y+4);    printf(" \\____|_| |_|\\___||___/___/\n");
}