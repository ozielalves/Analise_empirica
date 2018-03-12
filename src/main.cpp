// Custom includes
#include "util.h"
#include "binary.h"

#include <iostream>
#include <algorithm>
#include <iterator>

int main(void) {
	int tam = 100;
	int random_vector[] = {1, 42, 8, 7, 12, 19, 22, 10, 76, 1022, 3, 2, 17, 34, 64, 50};
	long int *big_random_vector = criarVetor(tam);

	std::cout << "Original Array:" << std::endl;
	print_array( std::begin(random_vector), std::end(random_vector) );
	
	std::cout << "Original Random Array" << std::endl;
	// não funciona (?) // Perguntar a selan
	//print_array( std::begin(big_random_vector), std::end(big_random_vector) );
	
	print_larray( big_random_vector, big_random_vector+tam-1 );
	
	return 0;
}
