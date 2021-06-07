//
// Created by Yiming Zhao on 2020/2/22.
//
#include <stdio.h>
#include <string.h>
FILE* nPtr;//This is the pointer for the output file
void input_file(const char *input_file_path,char inputArr[14][100])
{

    FILE *fp = fopen(input_file_path, "rw" );
    int i=0, lineNo=0;

    if (fp == NULL )
    {
        perror ("Error opening input file");
        lineNo = -1; //use this as a file not found code
    }
    else
    {
        while ( fgets( inputArr[lineNo], sizeof(inputArr[lineNo]), fp ) != NULL )
        {
       
            lineNo++;
        }
        fclose (fp);
    }
    if ((nPtr = fopen("output.txt", "w+")) == NULL) {//print "Failed to open output.txt" if the file doesn't exist
        printf("Failed to open output.txt\n");
    }

}