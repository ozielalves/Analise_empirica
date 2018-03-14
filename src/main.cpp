// Custom includes
#include "util.h"
#include "binary.h"
#include "sequential.h"

#include <iostream>
#include <chrono>
#include <random>
#include <ctime>

// Default values
#define TAM 2000000		// How many elements the vector will have
#define TIMES 1		// How many times the program will run (TODO)

int main(int argc, char **argv) {
	// Creates the vector that later we'll be working on
	long int *big_random_vector = criarVetor(TAM);
	
	// Choose a random index on big_random_vector[] to be the random_element
	//std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	//long int random_element = *(big_random_vector+random() % TAM);

	std::cout << "STATUS: Original Random Array Created" << std::endl;

	/*	
		Function to print the current working array (debug only)
		uncomment to use
	*/
	//print_larray( big_random_vector, big_random_vector+TAM );

	std::cout << "STATUS: Starting clock!" << std::endl;
	std::cout << std::setfill('-') << std::setw(50) << "" << std::endl; 
	clock_t start_time = clock();

	/* Call section for the algorithmns */
	
	ssearch( big_random_vector, big_random_vector+TAM, 39000);	
	//i_binary( big_random_vector, big_random_vector+TAM, (long int)-2);

	/* End of call section */

	clock_t elapsed = clock() - start_time; // with this we will have how much time the algorithm took (in ms)
	

	std::cout << std::setfill('-') << std::setw(50) << "" << std::endl; 
	std::cout << "STATUS: The algorithm took " << std::dec << elapsed << " ms." << std::endl;

	free(big_random_vector);
	return 0;
}
