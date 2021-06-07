//
// Created by Yiming Zhao on 2020/4/21.
//
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "logic.h"
bool check_valid(square board[BOARD_SIZE][BOARD_SIZE], color colour, int x, int y, int ax, int ay) {
    if (x<0 || x>7 || y<0 || y>7|| ax<0 || ax>7 || ay<0 || ay>7)//The coordinate player entered is out of the board
    {
        printf("Out of the board\n");
        return false;
    }
    if (board[x][y].type == INVALID||board[ax][ay].type == INVALID)//The square player chose is invalid
    {
        printf("Invalid square being selected\n");
        return false;
    }
    if (x==ax && y==ay)//Player can't between the same squares
    {
        printf("You are moving to the same space\n");
        return false;
    }
    if (board[x][y].num_pieces == 0)//The player can't move a empty square
    {
        printf("Empty square\n");
        return false;
    }
    if (board[x][y].stack->p_color != colour)//The player can't move square with other color
    {
        printf("The square is not your colour\n");
        return false;
    }
    if ((abs(x-ax) + abs(y-ay)) > board[x][y].num_pieces)//The player can't move in distance beyond the size of stack
    {
        printf("You are going too far!\n");
        return false;
    }
    return true;//Otherwise, the player can make the move
}