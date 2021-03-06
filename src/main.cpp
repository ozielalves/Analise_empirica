// Custom includes
#include "util.h"
#include "binary.h"
#include "sequential.h"
#include "fibonacci.h"
#include "jsearch.h"
#include "ternary.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <new>
#include <stdlib.h>

#define DATADIR "data/"

int main(int argc, char **argv) {
	system("clear");
	system("rm -rf data/*");
	
	// Default message headers
	std::string status 	= "\e[1;32mSTATUS: \e[0;0m";
	std::string error 	= "\n\e[1;4;91mERROR:\e[0;0m ";
	std::string min 	= "\n\e[0;0m"; 		// make it normal

	long int array_size, times_to_run;
	long int array_increment = pow(10, 6);
	int number_of_arrays = 25;
	std::string algorithms_to_run;
	
	// showArgs(&argc, argv);

	// An error message if the user leave argv empty
	if(argc != 6){
		std::cout << error << "Please, use:" << std::endl;
		std::cout << "./bin/analise [TIC] [NT] [I] [NI] [AS]";
		std::cout << min << std::endl;
		std::cout << "\tTIC - Tamanho Inicial do Conjunto";
		std::cout << std::endl; 

		std::cout << "\t NT - Número de Testes";
		std::cout << std::endl; 

		std::cout << "\t  I - Incremento";
		std::cout << std::endl; 

		std::cout << "\t NI - Número de Incrementos";
		std::cout << std::endl; 

		std::cout << "\t AS - Algoritmos Selecionados";
		std::cout << std::endl; 

		std::cout << "\nFor more info, please visit ozielalves/Analise_empirica." << std::endl;

		return 1;
	} else {
		array_size = atoll(argv[1]);
		std::cout << status << "array_size = " << array_size << min;
		times_to_run = atoll(argv[2]);
		std::cout << status << "times_to_run = " << times_to_run << min;
		array_increment = pow(10, atol(argv[3]));
		std::cout << status << "array_increment = " << array_increment << min;
		number_of_arrays = atoll(argv[4]);
		std::cout << status << "number_of_arrays = " << number_of_arrays << min;
		algorithms_to_run = argv[5];
		std::cout << status << "algorithms_to_run = " << algorithms_to_run << min;
	}
	long int SEARCH_FORN = -9391932919980;
	long int SEARCH_FOR  =  1000000000000;


	std::cout << status << "Searching for " << SEARCH_FOR << " element." << min;
bp();
	std::cout << status << "Processing..." << min;

	/*
	 * Here are the notorious function pointers
	 * to add a function inside the 'list', just write after the last pointer[x] = &..
	 * example: pointer[3] = &function_name
	 * 
	 * And PLEASE, do not forget to update n_functions variable
	 */
	const int n_functions = 7; // VERY IMPORTANT CONSTANT

	long int *(*pointer[n_functions])(long int *, long int *, long int, long int *);
	pointer[0] = &ssearch;
	pointer[1] = &i_binary;
	pointer[2] = &r_binary;
	pointer[3] = &i_ternary;
	pointer[4] = &r_ternary;
	pointer[5] = &jsearch;
	pointer[6] = &fibonacci;

	// Here the names are defined for the output files
	std::string names[n_functions];
	names[0] = "1-Sequential Search";
	names[1] = "2-Iterative Binary";
	names[2] = "3-Recursive Binary";
	names[3] = "5-Iterative Ternary";
	names[4] = "6-Recursive Ternary";
	names[5] = "4-Jump Search";
	names[6] = "7-Fibonacci Search";

	// Creates the vector that later we'll be working on
	long int *big_random_vector = cArray(array_size + (number_of_arrays * array_increment));

	// Generate at least <number_of_arrays> different array sizes
	for(int aSize = 1; aSize <= number_of_arrays; aSize++) {
		if(!big_random_vector) {
			std::cout << error << "Random Array was not created!" << min; 
			free(big_random_vector);
			return 1;
		}
		
		// Clocks declarations
		std::chrono::steady_clock::time_point start;
		std::chrono::steady_clock::time_point stop;


		// Arrays that will have the algorithms times and iterations
		long int *sum_times = new long int[n_functions]; 
		long int *iterations = new long int[n_functions];

		// Initializer for sum_times & iterations 
		for(int i=0; i < n_functions; i++){
			sum_times[i] = 0;
			iterations[i] = 0;
		}

		/*
		* This will test the algorithm <times_to_run> times
		* and then will store all the data on sum_times[algorithm_number] & iterations[algorithm_number]
		* *without the average, only the sum
		*/

		for(int time = 0; time < times_to_run; time++) {
			int c = 0;
			// for-loop thru function pointer array, 
			// each for, one of the correspondent algorithms
			// gets to run thru run_algorithm
			for(auto run_algorithm : pointer) {
				// std::cout << "Algorithm[" << c << "]" << algorithms_to_run[c] << std::endl;
				if( (int) algorithms_to_run[c] == '1' ) {
					start = std::chrono::steady_clock::now();

					// --- TIMER STARTS HERE --- //
					run_algorithm ( big_random_vector, big_random_vector + array_size, SEARCH_FOR, &iterations[c] );
					// --- TIMER ENDS HERE --- //

					stop = std::chrono::steady_clock::now();
					auto timer = (stop - start);

					sum_times[c] += std::chrono::duration <double, std::nano> (timer).count();
				}
				c++;
			}			
		}


		for(int i = 0; i < n_functions; i++){
			std::stringstream filepath;

			filepath << DATADIR << names[i] << ".dat";
			std::ofstream outFile(filepath.str(), std::ios::app);	
			generateResults(i,outFile, aSize, array_size, times_to_run, n_functions, sum_times, iterations);
			outFile.close();
		}
		

		// Function to print all the results
		// printResults(aSize, array_size, times_to_run, n_functions, sum_times, iterations);

		delete[] sum_times;
		delete[] iterations;
		array_size += array_increment;
	}
	delete[] big_random_vector;

	// It's over :D
	return 0;
}
