//
// Created by Yiming Zhao on 2020/3/27.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input_output.h"


/* FUnction to print the board:
 * Invalid Squares are printed as | -- |
 * Valid empty squares are printed as |   |
 * Valid squares with a GREEN piece are printed as | numberG |
 * Valid squares with a RED piece are printed as | numberR | */




void print_board(square board[BOARD_SIZE][BOARD_SIZE]) {
            printf("*************** The Board ***************\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == VALID) {
                if (board[i][j].stack == NULL)
                    printf("|    ");
                else {
                    if (board[i][j].stack->p_color == GREEN)
                        printf("| %dG ",board[i][j].num_pieces);
                    else printf("| %dR ",board[i][j].num_pieces);
                }
            } else
                printf("| -- ");
        }
        printf("|\n");
    }
}


void place_existed(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM], int x, int y, int ax, int ay) {
    //Set the top stack
    piece *top = board[x][y].stack;
    //Remove it from original position
    piece *curr = top;
    board[x][y].stack = NULL;
    board[x][y].num_pieces =0;
    int size = 1;
    while (curr->next != NULL) {
        curr = curr->next;
        size++;
    }
    // Last of the current stack is the first one to join
    piece *last = curr;
    // Join the target stack with the top stack
    curr->next = board[ax][ay].stack;
    // Find the new last point
    while (size < 5 && last->next != NULL) {
        last = last->next;
        size++;
    }
    curr = last->next;//The new current is the one after the last point.
    // Decide if the number of hold or captured will increase
    while (curr != NULL) {
        for (int i=0; i<2; i++) {
            //If the player own the stack
            if (players[i].player_color == top->p_color) {
                if (players[i].player_color == curr->p_color) {
                    //If player's own piece was taken, number of hold increase by 1
                    players[i].hold += 1;
                }
                //Otherwise captured increase by one
                else {
                    players[i].captured += 1;
                }
            }
        }
        //Move to the next piece
        curr = curr->next;
    }
    //Cut the exceed pieces
    if(last!= NULL) {
        curr = last->next;
        while (curr != NULL) {
            piece *toRemove = curr;
            curr = curr->next;
            free(toRemove);
        }
        last->next = NULL;
    }
    board[ax][ay].stack = top;
    board[ax][ay].num_pieces = size;
}
bool place_holded(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM], color colour, int ax, int ay) {
    //Out of the board
    if (ax<0 || ax>7 || ay<0 || ay>7)
    {
        printf("Out of the board\n");
        return false;
    }
    //Invalid square being chosen
    if (board[ax][ay].type ==INVALID)
    {
        printf("Invalid square\n");
        return false;
    }

    //The player doesn't have enough pieces stored
    if (players[colour].hold < 1)
    {
        printf("You don't have enough pieces stored\n");
        return false;
    }
    //Make the 00square available to store the new square temporarily
    board[0][0].type = VALID;
    board[0][0].stack = (piece *) malloc (sizeof(piece));
    board[0][0].stack->p_color = colour;
    board[0][0].stack->next = NULL;
    board[0][0].num_pieces = 1;
   //Decrease the number of pieces hold by player by one
    players[colour].hold -= 1;
    //Use the place_existed function again

    piece *top = board[0][0].stack;
    board[0][0].type = VALID;
    board[0][0].stack = NULL;
    board[0][0].num_pieces =0;
    piece *bottom = board[ax][ay].stack;

    piece *curr = top;
    int size = 1;

    while (curr->next != NULL) {
        curr = curr->next;
        size++;
    }
    piece *last = curr;
    curr->next = bottom;
    while (size < 5 && last->next != NULL) {
        last = last->next;
        size++;
    }
    curr = last->next;
    while (curr != NULL) {
        for (int i=0; i<PLAYERS_NUM; i++) {
            if (players[i].player_color == top->p_color) {
                if (players[i].player_color == curr->p_color) {
                    players[i].hold += 1;
                } else {
                    players[i].captured += 1;
                }
            }
        }
        curr = curr->next;
    }
    if(last!= NULL) {
        curr = last->next;
        while (curr != NULL) {
            piece *toRemove = curr;
            curr = curr->next;
            free(toRemove);
        }
        last->next = NULL;
    }
    board[ax][ay].stack = top;
    board[ax][ay].num_pieces = size;
    //Set the square back to invalid
    board[0][0].type = INVALID;
    board[0][0].stack = NULL;
    board[0][0].num_pieces =0;
    return true;
}