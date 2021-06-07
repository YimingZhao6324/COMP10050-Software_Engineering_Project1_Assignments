//
// Created by Yiming Zhao on 26/02/2020.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>


FILE* nPtr;
//define all the function here
void count_characters(char inputStrings [][100], int charCount[][26]);
void anagrams(char array[14][100], int charCount[14][26]);
void identify_anagrams(char inputStrings[14][100]) {
    int charCount[14][26];
    count_characters(inputStrings, charCount);
    anagrams(inputStrings, charCount);
}

/*This function counts the characters in the sentences stored in Input strings and stores them in the 2D array charCount*/
void count_characters(char inputStrings [][100], int charCount[][26])
{
    char lowerString[100];

    //initialize the charCount
    for(int i =0; i < 14; i++)
        for(int j =0;  j< 26; j++)
            charCount[i][j] = 0;

    for(int i =0; i< 14; i++){
        //converts a string into lower case letters
        toLower(inputStrings[i], lowerString);
        for (int j =0; j < strlen(inputStrings[i]); j++){
            //increments the cell in char count associated with the corresponding character
            switch(lowerString[j]){
                case 'a': charCount[i][0]++;
                    break;
                case 'b': charCount[i][1]++;
                    break;
                case 'c': charCount[i][2]++;
                    break;
                case 'd': charCount[i][3]++;
                    break;
                case 'e': charCount[i][4]++;
                    break;
                case 'f': charCount[i][5]++;
                    break;
                case 'g': charCount[i][6]++;
                    break;
                case 'h': charCount[i][7]++;
                    break;
                case 'i': charCount[i][8]++;
                    break;
                case 'j': charCount[i][9]++;
                    break;
                case 'k': charCount[i][10]++;
                    break;
                case 'l': charCount[i][11]++;
                    break;
                case 'm': charCount[i][12]++;
                    break;
                case 'n': charCount[i][13]++;
                    break;
                case 'o': charCount[i][14]++;
                    break;
                case 'p': charCount[i][15]++;
                    break;
                case 'q': charCount[i][16]++;
                    break;
                case 'r': charCount[i][17]++;
                    break;
                case 's': charCount[i][18]++;
                    break;
                case 't': charCount[i][19]++;
                    break;
                case 'u': charCount[i][20]++;
                    break;
                case 'v': charCount[i][21]++;
                    break;
                case 'w': charCount[i][22]++;
                    break;
                case 'x': charCount[i][23]++;
                    break;
                case 'y': charCount[i][24]++;
                    break;
                case 'z': charCount[i][25]++;
                    break;
                default: break;

            }
        }

    }
}

void anagrams(char array[14][100], int charCount[14][26])
{
    char check[14][14] = {0};

    //if two array equal to each other, add 1 to 2D array check[i][j]
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            for (int p = 0; p < 26; p++) {
                if (charCount[i][p] == charCount[j][p]) {
                    check[i][j]++;
                }
            }
        }
    }

    //turn all non letter element to 0
    for (int i = 0; i < 14; i++) {
        for (int j = 0; j < 14; j++) {
            if (check[i][j] != 26) {
                check[i][j] = 0;
            } else {
                check[i][j] = j + 1;
            }
        }
    }

    //if only this number appear in this row, change this number to 0
    for (int i = 0; i < 14; i++) {
        int counter = 0;
        for (int j = 0; j < 14; j++) {
            counter = counter + check[i][j];
        }
        if (counter == i + 1) {
            for (int j = 0; j < 14; j++) {
                check[i][j] = 0;
            }
        }
    }


    //turn repeated rows to zero
    for (int i = 0; i < 13; i++) {
        for (int j = i + 1; j < 14; j++) {
            for (int p = 0; p < 14; p++) {
                if (check[i][p] == check[j][p]) {
                    check[j][p] = 0;
                }
            }
        }
    }

    //print out the results
    fprintf(nPtr,"\nAnagram1:\n");
    int note = 0;
    for (int i = 0; i < 3; i++)
    {
        note = 0;
        for (int j = 0; j < 14; j++)
        {
            if (check[i][j] != 0)
            {
                fprintf(nPtr,"%s", array[check[i][j] - 1]);
                note++;
            }
        }
        if (note != 0)
        {
            fprintf(nPtr,"\n");
        }
    }
    fprintf(nPtr,"Anagram2:\n");

    for (int i = 3; i < 7; i++)
    {
        note = 0;
        for (int j = 0; j < 14; j++)
        {
            if (check[i][j] != 0)
            {
                fprintf(nPtr,"%s", array[check[i][j] - 1]);
                note++;
            }
        }
        if (note != 0)
        {
            fprintf(nPtr,"\n");
        }
    }
    fprintf(nPtr,"Anagram3:\n");
    for (int i = 7; i < 14; i++)
    {
        note = 0;
        for (int j = 0; j < 14; j++)
        {
            if (check[i][j] != 0)
            {
                fprintf(nPtr,"%s", array[check[i][j] - 1]);
                note++;
            }
        }
        if (note != 0)
        {
            fprintf(nPtr,"\n");
        }
    }
}