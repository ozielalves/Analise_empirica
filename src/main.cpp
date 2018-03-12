// Custom includes
#include "util.h"
#include "binary.h"

#include <iostream>
#include <algorithm>
#include <iterator>

void print_array( int *first, int *last )
{
	std::cout << "[ ";
	std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

int main(int argc, char **argv) {
	int random_vector[] = {1, 42, 8, 7, 12, 19, 22, 10, 76, 1022, 3, 2, 17, 34, 64, 50};

	std::cout << "Original Array:" << std::endl;
	print_array( std::begin(random_vector), std::end(random_vector) );
	
	return 0;
}
