//
// Created by 100652479 on 3/27/2020.
//

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

//Returns number of elements in terminated array
int arraySize(const void** array) {
    int count;
    for(count = 0; array[count] != NULL; count++);
    return count;
}
//Reads a line in format "<int1>, <int2>, ..., <int8>" from a filestream and returns the
//int values in an malloced array of size 8.
int * readInfo(FILE *file) {
    const int SIZE = 8;
    int * array = malloc(sizeof(int) * SIZE);
    int index = 0;
    //Read line
    while(!feof(file) && index < SIZE) {
        char number[] = "\0\0\0\0";
        char digit = '\0';
        int i = 0;
        while (!feof(file) && isdigit(digit = fgetc(file) ) )
            number[i++] = digit;

        if(strlen(number) > 0)
            array[index++] = atoi(number);

        if(digit == nl)
            break;
    }
    /*Single newline encountered. Set array to NULL to indicate the read failed*/
    if(index < SIZE) {
        free(array);
        array = NULL;
    }

    return array;
}

//Reads the contents of a file and stores them in a string.
void read_file(FILE* file, char* buffer, size_t size) {
    int i;
    for(i = 0; !feof(file) && i < size; i++)
        buffer[i] = fgetc(file);

    buffer[i - 1] = '\0';	//Add the terminating null character.
}