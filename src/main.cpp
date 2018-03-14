// Custom includes
#include "util.h"
#include "binary.h"
#include "sequential.h"
#include "fibonacci.h"
#include "jsearch.h"
#include "ternary.h"

#include <iostream>
#include <chrono>

int main(int argc, char **argv) {
	// Default message headers
	std::string status 	= "\e[1;32mSTATUS: \e[0;0m";
	std::string error 	= "\n\e[1;4;91mERROR:\e[0;0m ";
	std::string min 	= "\n\e[0;0m"; 		// make it normal

	// An error message if the user leave argv empty
	if(argc == 1){
		std::cout << error << "Please, use:\n./bin/analise <array_size> <times>" << min << std::endl;
		return 1;
	}	

	// Some argv default variables
	// (in case argv = 0)
	int array_size 		= TAM;
	int times_to_run	= 1;
	int array_increment = 1000000;

	// debug only, uncomment this to show all the args	
	//showArgs(&argc, argv);


	if(argc == 3)
	{
		array_size = atoi(argv[1]);
		std::cout << status << "array_size = " << array_size << min;
		times_to_run = atoi(argv[2]);
		std::cout << status << "times_to_run = " << times_to_run << min;
	}
	bp();
	std::cout << status << "Running..." << min;
		
	// generate at least 25 different array sizes
	for(int aSize = 1; aSize <= 25; aSize++)
	{
		array_size = array_size + aSize * array_increment;
		// Creates the vector that later we'll be working on
		long int *big_random_vector = cArray(array_size);
		if(!big_random_vector)
		{
			std::cout << error << "Random Array was not created!" << min; 
			free(big_random_vector);
			return 1;
		}

		//pArray( big_random_vector, big_random_vector+ array_size );
		
		// Simple declarations of clocks
		std::chrono::high_resolution_clock::time_point start;
		std::chrono::high_resolution_clock::time_point stop;
		std::chrono::nanoseconds timer(0);

		int time = 0;
		int sum_times = 0;
		long int iterations = 0;

		for(time = 0; time < times_to_run; time++)
		{
			start = std::chrono::high_resolution_clock::now();

			// function pointer here

			// How to call a function:
			// funcionName( big_random_vector, big_random_vector + array_size, (long int) SEARCH_FOR );
			i_binary( big_random_vector, big_random_vector + array_size, (long int) SEARCH_FOR, &iterations);
			//ssearch( big_random_vector, big_random_vector + array_size, (long int) SEARCH_FOR, &iterations);

			stop = std::chrono::high_resolution_clock::now();

			// uncomment this if you want to see case by case debug
			//std::cout << status << "took " << timer.count() << " nanoseconds." << min;

			timer = std::chrono::duration_cast<std::chrono::nanoseconds> (stop - start);
			sum_times += timer.count();
		}
		int average = sum_times/time;
		int average_ite = iterations / time;	

		std::cout << "\e[1;96mAverage of " << array_size << " elements in " << 
		time << " times:\t" << average << " nanoseconds!\t(" << average_ite << " iterations)" << min;

		free(big_random_vector);
	}
	return 0;
}
