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
 * @file main.h 
 * @brief Calculate statistics for an array of 8-bit values 
 *
 * Analyze an array of unsigned char data items and report analytics on the 
 * maximum, minimum, mean, and median of the data set.
 *
 * @author Fergus Deffely 
 * @date 14-06-2024 
 *
 */

#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief print_statistics 
 *
 * A function that prints the statistics of an array including 
 * minimum, maximum, mean, and median. 
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return void 
 */

void print_statistics(unsigned char * array, unsigned int);

/**
 * @brief print_array
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return void 
 */

void print_array (unsigned char * array, unsigned int);

/**
 * @brief find_median 
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return int - the median value 
 */

unsigned char find_median (unsigned char * array, unsigned int);

/**
 * @brief find_mean 
 *
 * Given an array of data and a length, returns the mean
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return float - the mean value 
 */

float find_mean (unsigned char * array, unsigned int);

/**
 * @brief find_maximum
 * 
 * Given an array of data and a length, returns the maximum
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return int - the maximum value 
 */

unsigned char find_maximum (unsigned char * array, unsigned int);

/**
 * @brief find_minimum
 * 
 * Given an array of data and a length, returns the minimum
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return int - the minimum value
 */

unsigned char find_minimum (unsigned char * array, unsigned int);

/**
 * @brief sort_array 
 * 
 * Given an array of data and a length, sorts the array from largest to 
 * smallest. (The zeroth element will be the largest value, and the last 
 * element (n-1) will be the smallest value. )
 *
 * @param unsigned char * array    Pointer to an array of 8-bit values 
 * @param unsigned int         Length of the array 
 *
 * @return unsigned char * array   Pointer to the sorted array 
 */

unsigned char * sort_array(unsigned char * array, unsigned int);

#endif /* __STATS_H__ */
