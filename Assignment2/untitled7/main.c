//
// Created by Yiming Zhao 19353281 on 2020/4/21.
//
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "input_output.h"
#define PLAYERS_NUM 2



int main(void)
{
    player players[PLAYERS_NUM];
    square board[BOARD_SIZE][BOARD_SIZE];
    initialize_players(players);//Initialize the players
    initialize_board(board);//Initialize the board
    print_players(players);//Print the information of the players
    char cord[7];//The coordination
    const char REQUEST[10] = "new:";//The request to new a piece for holdings
    bool lose1=1;//lose conditions for the players
    bool lose2=1;
    //Loop for the game
    while (1) {
        print_board(board);
        //Print number of pieces player 1 is holding
        printf("You are holding %d pieces\n", players[0].hold);
        //Ask the move from the player 1
        printf("Enter the move with the before and after coordinates in the form of: 12to13, \nto put a new stack, just write in the form of new:12:\n");
        //Flush for the next player to enter the new value
        fflush(stdin);
        printf("Red player (%s)'s turn\n", players[0].name);
        while (1) {
        //Check if the move is valid then make the move.
            if (fgets(cord, sizeof cord, stdin)) {

                if (check_valid(board, 0, cord[0] - '1', cord[1] - '1', cord[4] - '1', cord[5] - '1') == true) {
                    place_existed(board, players, cord[0] - '1', cord[1] - '1', cord[4] - '1',cord[5] - '1');
                    printf("Move is made successfully\n");
                    break;
                }
        //If the player want to new a piece from the piece he/she holds, run the other function
                if (strstr(cord, REQUEST) != NULL) {
                    if (place_holded(board, players, 0, cord[4] - '1', cord[5] - '1') == true) {
                        printf("Move is made successfully\n");
                        break;
                    }
                } else {
        //If there is any problem with the entered value, ask again.
                    printf("please enter a move:\n");
                }
            }
        }
        //Check for the winning condition
        for(int i=0; i<BOARD_SIZE; i++){
            for(int j=0; j<BOARD_SIZE;j++){
                if(players[0].hold==0){
                    if(board[i][j].stack != NULL&&board[i][j].type==VALID&& board[i][j].stack->p_color==RED){
                        lose1 = 0;
                    }
                }
            }
        }
        //If the condition is met, jump out of the loop.
        if(lose1 == 1){
            printf("\n\nRed player (%s) is the LOSER!\n\n", players[0].name);
            printf("\n\nGreen player (%s) win the game, well done!\n\n",players[1].name);
            printf("\n\nThe number of pieces you have captured is: %d\n\n",players[1].captured);
            break;
        }

        //Player 2's turn
        // Ask the move from the player 2
        print_board(board);
        printf("Enter the move with the before and after coordinates in the form of: 12to13, \nto put a new stack, just write in the form of new:12:\n");
        //Flush for the next player to enter the new value
        fflush(stdin);
        printf("Green player (%s)'s turn\n", players[1].name);
        while(1) {
        //Check if the move is valid then make the move.
            if (fgets(cord, sizeof cord, stdin)){

                if (check_valid(board, 1, cord[0] - '1', cord[1] - '1', cord[4] -'1', cord[5] - '1')==true) {
                    place_existed(board, players, cord[0] - '1', cord[1] - '1', cord[4] - '1',cord[5] - '1');
                    printf("Move is made successfully\n");
                    break;
                }
        //If the player want to new a piece from the piece he/she holds, run the other function
                if (strstr(cord, REQUEST) != NULL){
                    if(place_holded(board, players, 1, cord[4] - '1', cord[5] - '1') == true) {
                        printf("Move is made successfully\n");
                        break;
                    }
                }else{
        //If there is any problem with the entered value, ask again.
                    printf("please enter a move:\n");
                }
            }

        }
        //Check for the winning condition
        for(int i=0; i<BOARD_SIZE; i++){
            for(int j=0; j<BOARD_SIZE;j++){
                if(players[1].hold==0){
                    if(board[i][j].stack != NULL&&board[i][j].type==VALID&& board[i][j].stack->p_color==GREEN){
                        lose2 = 0;
                    }
                }
            }
        }
        //If the condition is met, jump out of the loop.
        if(lose2 == 1){
            printf("\n\nGreen player (%s) is the LOSER!\n\n", players[1].name);
            printf("\n\nRed player (%s) win the game, well done!\n\n",players[0].name);
            printf("\n\nThe number of pieces you have captured is: %d\n\n",players[0].captured);
            break;
        }
    }
    //End the program
    return 0;
}


