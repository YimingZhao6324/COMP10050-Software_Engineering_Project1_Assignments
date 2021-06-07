//
// Created by Yiming Zhao on 2020/3/27.
//
#ifndef FOCUS_INPUT_OUTPUT_H
#define FOCUS_INPUT_OUTPUT_H

#endif //FOCUS_INPUT_OUTPUT_H


#include "logic.h"
//Function to print the board
void print_board(square board[BOARD_SIZE][BOARD_SIZE]);
//Function to place a new piece
bool place_holded(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM], color colour, int ax, int ay);
//Function to move an existed piece
void place_existed(square board[BOARD_SIZE][BOARD_SIZE], player players[PLAYERS_NUM], int x, int y, int ax, int ay);


