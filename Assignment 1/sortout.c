//
// Created by Yiming Zhao on 2020/2/22.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>


#define STR_NUM 14
#define MAX_LEN 100
FILE* nPtr;
char insertionSort(char inputStrings [][MAX_LEN]);

int printStrings(char inputStrings [][MAX_LEN]);

void sort(char array[14][100])
{
    insertionSort(array);
    printStrings(array);
}

/*
 * This function converts inputString in a string having all
 * lowercase letters and copies the result in lowerString
 */
void toLower(char inputString[], char lowerString[]){

    for(int i = 0; i< strlen(inputString); i++){
        // function to lower converts a character in its lower case version
        lowerString[i] = tolower(inputString[i]);
    }
}

/*
 * This function sorts an input array using the insertion sort algorithm
 *
 */
char insertionSort(char inputStrings [][MAX_LEN]) {
    int i, j;

    char swap[MAX_LEN], lowerString1[MAX_LEN], lowerString2[MAX_LEN];
    for (i = 1; i < STR_NUM; i++) {
        j = i;

        // before comparing strings at positions j and j-1
        // it is necessary to convert them into lowercase strings
        toLower(inputStrings[j], lowerString1);
        toLower(inputStrings[j-1], lowerString2);

        while (j > 0 && strcmp(lowerString1, lowerString2) < 0) {
            // swapping of strings is performed using strcpy
            strcpy(swap, inputStrings[j]);
            strcpy(inputStrings[j], inputStrings[j - 1]);
            strcpy(inputStrings[j - 1], swap);
            j--;
            toLower(inputStrings[j], lowerString1);
            toLower(inputStrings[j-1], lowerString2);
        }
    }
}

/*
 * This function prints a set of strings provided as input
 */
int printStrings(char inputStrings [][MAX_LEN]){
    fprintf(nPtr,"The sorted list of words follows:\n");
    for(int i =0; i< STR_NUM; i++)
        fprintf(nPtr,"%s",inputStrings[i]);
    return 0;
}