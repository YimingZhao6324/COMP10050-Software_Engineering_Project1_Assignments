//
// Created by Yiming Zhao on 2020/2/25.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>


FILE* nPtr;


/*Define all the function needed here*/
void count_characters_2(char inputStrings [][100], int charCount[][26]);

void find_anagrams(char inputStrings[14][100],char alterarr[14][100]);

void comprint_string(int charCount[][26],int i, char alterarr[14][100],int String_length[14]);



/*This function counts the characters in the sentences stored in Input strings and stores them in the 2D array charCount, it named after count_characters_2 to avoid muti defination*/
void count_characters_2(char inputStrings [][100], int charCount[][26])
{
    char lowerString[100];

    //initialize charCount
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
void missing_anagrams(char inputStrings[14][100])//This function will run after the find_anagrams function to get the missing anagrams
{
    char alterarr[14][100]={0};//creat an alter array in order to print all the no letter elements in the strings
    fprintf(nPtr,"The missing anagrams are:\n");
    for(int i=0;i<14;i++)
    {
        for(int j=0; j<100;j++)
        {
            alterarr[i][j]=inputStrings[i][j];//make the alter array equal to the inputString
        }
    }
    for(int i=0;i<14;i++)//Remove all the non letter elements in the inputstrings
    {
        for(int j=0;j<100;j++)
        {
            if(inputStrings[i][j]==' '|| inputStrings[i][j]==',' || inputStrings[i][j]=='!')
            {
                for(int p=j; p<100;p++)
                {
                    inputStrings[i][p]=inputStrings[i][p+1];
                }
                j--;
            }

        }
    }

    find_anagrams(inputStrings,alterarr);//call the find anagram function
}

void find_anagrams(char inputStrings[14][100],char alterarr[14][100]) {//this function will find the missing anagrams
    int String_length[14]={0};//define the length of each sentences
    char temp[14][100];//creat another temp array
    int charCount[14][26]={0};//define the count for characters
    for (int i = 0; i < 14; i++) {//find the length of each sentences
        for (int j = 0; j < 100; j++) {
            if ((inputStrings[i][j] >= 'A' && inputStrings[i][j] <= 'Z') || (inputStrings[i][j] >= 'a' && inputStrings[i][j] <= 'z')) {
                String_length[i]++;
            }

            else if (inputStrings[i][j] == '\0') {//break if it goes to the end
                break;
            }
        }
    }
    for(int i=0;i<14;i++)//let the temp array equal to the inputstrings
    {
        for(int j=0; j<100;j++)
        {
            temp[i][j]=inputStrings[i][j];
        }
    }
    for(int no=0;no<14;no++)
    {
        for (int k = 0; k < 14; k++) {
            inputStrings[k][String_length[no]] = '\0';
        }

        count_characters_2(inputStrings, charCount);//call the count characters function to find the frequency of letter appear in each sentence

        comprint_string(charCount, no, alterarr, String_length);//call the comprint function to compare the functions and print them out

        for(int i=0;i<14;i++)//exchange the value between temp array and the inputstrings.
        {
            for(int j=0; j<100;j++)
            {
                inputStrings[i][j]=temp[i][j];
            }
        }
    }

}

void comprint_string(int charCount[][26], int i,char alterarr[14][100],int String_length[14])// this function compare the strings and print them out
{
    int diff=0;
    for(int j=0; j<14;j++)//compare the frequency of letter appear in each sentence
    {
        bool flag=0;
        for(int p=0;p<26;p++)
        {
            if (charCount[i][p] != charCount[j][p])
            {
                flag=1;
            }
        }
        diff=String_length[j]-String_length[i];
        if(flag==0 && diff!=0)//if all the frequency are the same, print out the result
        {

                fprintf(nPtr,"%s is an anagram of %s if %d characters removed\n",alterarr[j],alterarr[i],diff);
        }
    }
}
