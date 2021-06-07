//
// Created by Yiming Zhao on 2020/2/22.
//

#include <stdio.h>
#include "input.h"
#include "sortout.h"
#include "Identify_anagram.h"
#include "miss_anagram.h"
const char *input_file_path = "input.txt";

char string[14][100];

int main() {
    input_file(input_file_path, string);//all the function is called in the main file
    sort(string);
    identify_anagrams(string);
    missing_anagrams(string);
    printf("The process is done");
    return 0;
}
