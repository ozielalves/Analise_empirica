#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <chrono>
#include <random>
#include <iomanip>
#include <iterator>

// Default values
#define TAM 2000000		// How many elements the vector will have
#define SEARCH_FOR -2


// A simple array print function
void pArray( long int *, long int * );

// A function to create "random" arrays
long int *cArray( int );

// A simple args show function
void showArgs( int *argc, char **argv );

// a function to simply break page
void bp();

#endif
