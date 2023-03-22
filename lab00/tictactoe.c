#include <stdlib.h>  /* exit() y EXIT_FAILURE */
#include <stdio.h>   /* printf(), scanf()     */
#include <stdbool.h> /* Tipo bool             */

#include <assert.h>  /* assert() */

#define CELL_MAX (3 * 3 - 1)

void print_sep(int length) {
    printf("\t ");
    for (int i=0; i < length;i++) printf("................");
    printf("\n");

}

void print_board(char board[3][3])
{
    int cell = 0;

    print_sep(3);
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            printf("\t | %d: %c ", cell, board[row][column]);
            ++cell;
        }
        printf("\t | \n");
        print_sep(3);
    }
}

char get_line_winner(char l[3], char prev_winner)
{
    char new_winner = prev_winner;
    bool exist_serie = false;
    if(l[0] != '-'){
        exist_serie = true;
        for(int i=1; i<3; i++){
            if(l[i-1] != l[i]){
                exist_serie = false;
            }
        }
    }
    if(exist_serie) {
        if(l[0] == 'X') {
            new_winner = 'X';
        }else if(l[0] == 'O') {
            new_winner = 'O';
        }
    }
    return new_winner;
}

char get_winner(char board[3][3])
{
    char winner = '-';
    char line[3];

    for(int i=0; i<3; i++) {
        //horizontal
        for(int j=0; j<3; j++) {
            line[j]= board[i][j];
        }
        winner = get_line_winner(line, winner);
        
        //vertical
        for(int j=0; j<3; j++) {
            line[j]= board[j][i];
        }
        winner = get_line_winner(line, winner);
    }

    //diagonals
    for(int i=0; i<3; i++) {
        line[i]= board[i][i];
    }
    winner = get_line_winner(line, winner);
    for(int i=0; i<3; i++) {
        int j = (3-1)-i;
        line[i]= board[i][j];
    }
    winner = get_line_winner(line, winner);
    
    return winner;
}

bool has_free_cell(char board[3][3])
{
    bool free_cell=false;
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            if(board[i][j] == '-')
            free_cell=true;
            break;
        }
    }
    return free_cell;
}

int main(void)
{
    printf("TicTacToe\n");

    char board[3][3] = {
        { '-', '-', '-' },
        { '-', '-', '-' },
        { '-', '-', '-' }
    };

    char turn = 'X';
    char winner = '-';
    int cell = 0;
    while (winner == '-' && has_free_cell(board)) {
        print_board(board);
        printf("\nTurno %c - Elija posición (número del 0 al %d): ", turn,
               CELL_MAX);
        int scanf_result = scanf("%d", &cell);
        if (scanf_result <= 0) {
            printf("Error al leer un número desde teclado\n");
            exit(EXIT_FAILURE);
        }
        if (cell >= 0 && cell <= CELL_MAX) {
            int row = cell / 3;
            int colum = cell % 3;
            if (board[row][colum] == '-') {
                board[row][colum] = turn;
                turn = turn == 'X' ? 'O' : 'X';
                winner = get_winner(board);
            } else {
                printf("\nCelda ocupada!\n");
            }
        } else {
            printf("\nCelda inválida!\n");
        }
    }
    print_board(board);
    if (winner == '-') {
        printf("Empate!\n");
    } else {
        printf("Ganó %c\n", winner);
    }
    return 0;
}