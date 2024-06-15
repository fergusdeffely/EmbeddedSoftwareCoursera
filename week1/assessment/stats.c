/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file main.c 
 * @brief Calculate statistics for an array of 8-bit values 
 *
 * Analyze an array of unsigned char data items and report analytics on the 
 * maximum, minimum, mean, and median of the data set.
 *
 * @author Fergus Deffely 
 * @date 14-06-2024 
 *
 */

#include <stdio.h>
#include <stdbool.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  printf("\n");
  printf("==============\n");
  printf("array contents\n");
  printf("==============\n");
  print_array(test, SIZE);
  
  sort_array(test, SIZE);
  printf("\n");
  printf("=====================\n");
  printf("sorted array contents\n");
  printf("=====================\n");
  print_array(test, SIZE);

  print_statistics(test, SIZE);
}

void print_statistics(unsigned char * array, unsigned int len) {

  int maximum = find_maximum(array, SIZE);
  int minimum = find_minimum(array, SIZE);
  float mean = find_mean(array, SIZE);
  float median = find_median(array, SIZE);

  printf("\n");
  printf("================\n");
  printf("array statistics:\n");
  printf("================\n\n");
  printf("maximum = %d\n", maximum);
  printf("minimum = %d\n", minimum);
  printf("mean = %.2f\n", mean);
  printf("median = %.1f\n\n", median);
}

void print_array (unsigned char * array, unsigned int len) {

    if ( len <= 0 ) {
        return;
    }

    for ( int i = 0; i < len; i++ ){
        if ( i % 5 == 0 ){
            printf("\n");
        }
        printf("[%02d] = %3d : ", i, array[i]);
    } 
    printf("\n");
}

float find_median (unsigned char * array, unsigned int len) {

    if ( len <= 0 ) {
        return 0;
    }

    if ( len % 2 > 0 ) {
        return array[len / 2];
    }

    return (float)(array[len / 2] + array[(len / 2) - 1]) / 2;
}

float find_mean (unsigned char * array, unsigned int len) {

    int sum = 0;

    for ( int i = 0; i < len; i++) {
        sum += array[i];
    }

    return (float)sum / len;
}

unsigned char find_maximum (unsigned char * array, unsigned int len) {

    int maximum = 0;

    for ( int i = 0; i < len; i++ ) {
        if ( array[i] > maximum ) {
            maximum = array[i];
        }
    } 

    return maximum; 
}

unsigned char find_minimum (unsigned char * array, unsigned int len) {

    if ( len <= 0 ) {
        return 0;
    }

    int minimum = array[0];

    for ( int i = 0; i < len; i++ ) {
        if ( array[i] < minimum ) {
            minimum = array[i];
        }
    } 

    return minimum; 
}

unsigned char * sort_array(unsigned char * array, unsigned int len) {

    bool sorted;
    int swap;

    do {
        sorted = true;
        for ( int i = 0; i + 1 < len; i++) {
            if ( array[i] > array[i + 1]) {
                /* 
                    printf("array: [%d] and [%d] : %d > %d : swapping...\n", i, i+1, array[i], array[i+1]);
                */
                swap = array[i];
                array[i] = array[i + 1];
                array[i + 1] = swap;
                sorted = false;
            }
        }
    } while(sorted == false);

    return array;
}

