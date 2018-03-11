#include <iostream>
#include "util.h"
#include <vector>
#include <algorithm>
#include <iterator>
#include <array>

void print_array(std::vector<int> &vector){
	std::cout << "[ ";
	for( auto &i : vector )
	{
		std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
}

int main(int argc, char **argv) {
	std::vector<int> vetor = {1, 42, 8, 7, 12, 19, 22, 10, 76, 1022, 3, 2, 17, 34, 64, 50};

	std::cout << "Original Array:" << std::endl;
	print_array(vetor);
	
	return 0;
}
