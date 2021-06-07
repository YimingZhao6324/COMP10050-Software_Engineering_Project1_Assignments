//
// Created by Yiming Zhao on 2020/3/27.
//


#include <stdio.h>
#include <stdlib.h>
#include "game_init.h"

void initialize_players(player players[PLAYERS_NUM]){
    // implement here the functionality to initialize the players
    for(int i =0; i < PLAYERS_NUM; i++){
    //Ask for the name of the players
        printf("Player's name: ");
        scanf("%s", players[i].name);
    //Set the color and the numbers for the players
        players[0].player_color=RED;
        players[1].player_color=GREEN;
        players[i].hold=0;
        players[i].captured=0;
    }
}
void print_players (player players[PLAYERS_NUM]){
    //Print the information of the players
    for(int i =0; i < PLAYERS_NUM; i++){
        printf("\nPlayer %d", i+1);
        printf("\nName: %s", players[i].name);
        printf("\nColor: ");
        if(players[i].player_color == RED) printf("RED");
        if(players[i].player_color == GREEN) printf("GREEN");
        printf("\nThe stacks player owned is:%d",players[i].hold);
        printf("\nThe stacks player captured is: %d\n",players[i].captured);
    }
}

//Set Invalid Squares (where it is not possible to place stacks)
set_invalid(square * s){
s->type = INVALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set Empty Squares (with no pieces/stacks)
set_empty(square * s){
s->type = VALID;
s->stack = NULL;
s->num_pieces = 0;
}

//Set squares  with a GREEN piece
set_green(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = GREEN;
s->stack->next = NULL;
s->num_pieces = 1;
}

//Set squares with a RED piece
set_red(square * s){
s->type = VALID;
s->stack = (piece *) malloc (sizeof(piece));
s->stack->p_color = RED;
s->stack->next = NULL;
s->num_pieces = 1;
}


//initializes the board
void initialize_board(square board [BOARD_SIZE][BOARD_SIZE]){

    for(int i=0; i< BOARD_SIZE; i++){
        for(int j=0; j< BOARD_SIZE; j++){
            //invalid squares
            if((i==0 && (j==0 || j==1 || j==6 || j==7)) ||
               (i==1 && (j==0 || j==7)) ||
               (i==6 && (j==0 || j==7)) ||
               (i==7 && (j==0 || j==1 || j==6 || j==7)))
                set_invalid(&board[i][j]);

            else{
                //squares with no pieces
                if(i==0 || i ==7 || j==0 || j == 7)
                    set_empty(&board[i][j]);
                else{
                    //squares with red pieces
                    if((i%2 == 1 && (j < 3 || j> 4)) ||
                       (i%2 == 0 && (j == 3 || j==4)))
                        set_red(&board[i][j]);
                        //green squares
                    else set_green(&board[i][j]);
                }
            }
        }
    }
}
