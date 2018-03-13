// Custom includes
#include "util.h"
#include "binary.h"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <chrono>
#include <random>

// Default values
#define TAM 20		// How many elements the vector will have
#define TIMES 1		// How many times the program will run

int main(int argc, char **argv) {
	// Creates the vector that later we'll be working on
	long int *big_random_vector = criarVetor(TAM);
	
	// Choose a random index on big_random_vector[] to be the random_element
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	long int random_element = *(big_random_vector+random() % TAM);

	std::cout << "Original Random Array" << std::endl;
	
	// não funciona (?) // Perguntar a selan
	//print_larray( std::begin(big_random_vector), std::end(big_random_vector) );

	std::sort ( big_random_vector, big_random_vector+TAM );
	print_larray( big_random_vector, big_random_vector+TAM );

	/* Call section for the algorithmns */


	free(big_random_vector);
	return 0;
}
