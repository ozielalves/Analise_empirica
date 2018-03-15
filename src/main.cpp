// Custom includes
#include "util.h"
#include "binary.h"
#include "sequential.h"
#include "fibonacci.h"
#include "jsearch.h"
#include "ternary.h"

#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <new>

int main(int argc, char **argv) {
	// Default message headers
	std::string status 	= "\e[1;32mSTATUS: \e[0;0m";
	std::string error 	= "\n\e[1;4;91mERROR:\e[0;0m ";
	std::string min 	= "\n\e[0;0m"; 		// make it normal

	long int array_size, times_to_run;
	long int array_increment = pow(10, 6);
	int number_of_arrays = 25;
	
	// showArgs(&argc, argv);

	// An error message if the user leave argv empty
	if(argc != 3){
		std::cout << error << "Please, use:\n./bin/analise <array_size> <times>" << min << std::endl;
		return 1;
	} else {
		array_size = atol(argv[1]);
		std::cout << status << "array_size = " << array_size << min;
		times_to_run = atol(argv[2]);
		std::cout << status << "times_to_run = " << times_to_run << min;
		//array_increment = atol(argv[3]);
		//std::cout << status << "array_increment = " << array_increment << min;
	}

	bp();
	std::cout << status << "Running..." << min;

	/*
	 * Here are the notorious function pointers
	 * to add a function inside the 'list', just write after the last pointer[x] = &..
	 * example: pointer[3] = &function_name
	 * 
	 * And PLEASE, do not forget to update n_functions variable
	 */
	int n_functions = 3;
	long int *(*pointer[n_functions])(long int *, long int *, long int, long int *);
	pointer[0] = &i_binary;
	pointer[1] = &jsearch;
	pointer[2] = &ssearch;
		
	// Generate at least <number_of_arrays> different array sizes
	for(int aSize = 1; aSize <= number_of_arrays; aSize++) {
		array_size += array_increment;

		// Creates the vector that later we'll be working on
		long int *big_random_vector = cArray(array_size);
		
		if(!big_random_vector) {
			std::cout << error << "Random Array was not created!" << min; 
			free(big_random_vector);
			return 1;
		}
		
		// Clocks declarations
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point stop;

		int time;
		// Arrays that will have the algorithms times and iterations
		long int *sum_times = new long int[n_functions]; 
		long int *iterations = new long int[n_functions];


		// Just a timestamp for making easy if we want to change the time
		std::string timestamp;

		for(time = 0; time < times_to_run; time++) {
			int c = 0;
			for(auto run_algorithm : pointer) {
				start = std::chrono::steady_clock::now();

				// --- TIMER STARTS HERE --- //
				run_algorithm ( big_random_vector, big_random_vector + array_size, SEARCH_FOR, &iterations[c] );
				// --- TIMER ENDS HERE --- //

				stop = std::chrono::steady_clock::now();

				auto timer = (stop - start);

				timestamp = "nanoseconds"; // make it the same
				sum_times[c++] += std::chrono::duration <double, std::nano> (timer).count();
			}			
		}

		int average;
		int average_ite;
		
		// A print for-loop to show the results (time, iterations..)
		for(int i = 0; i < n_functions; i++){
			// Just a simple divisor to make things pretty
			if(!i) {
				bp();
				std::cout << "Run no. " << aSize << ":" << std::endl;
			}	
			
			std::cout << "Algorithm " << i+1 << ": ";

			average = sum_times[i] / time;	
			average_ite = iterations[i] / time;

			std::cout << "\e[1;96mAverage of " << std::right << std::setfill(' ') <<
			std::setw(12) << array_size << "\telements in " << time << " times:\t" <<
			average << " " << timestamp << "!\t(" << average_ite << " iterations)" << min;
		}

		free(sum_times);
		free(iterations);
		free(big_random_vector);
	}

	// It's over :D
	return 0;
}
