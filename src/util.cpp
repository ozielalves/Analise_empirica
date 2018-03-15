#include "util.h"
#include <iostream>
#include <iterator>

void pArray(long int *first, long int *last)
{
	std::cout << "[ ";
	std::copy(first, last, std::ostream_iterator<long int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

long int *cArray(int n)
{
	long int *vetor = new long int[n]; 
	for(int i = 0, k = 0; i < n;)
	{
		vetor[i++] = (long int)k; 
		k += 5;
	}
	return vetor;
}

void showArgs(int *argc, char **argv)
{
	std::cout << "argc = " << *argc << std::endl;
	for(int i = 0; i < *argc; i++)
	{
		std::cout << "argv[" << i << "] = " << argv[i] << std::endl; 
	}
}
void bp(void)
{
	std::cout << std::setfill('-') << std::setw(70-11) << "" << std::endl; 
}

void printResults(int aSize, int array_size, long int time, int n_functions, long int *sum_times, long int *iterations ){
	// A print for-loop to show the results (time, iterations..)
		for(int i = 0; i < n_functions; i++){
			// Just a simple divisor to make things pretty
			if(!i) {
				bp();
				std::cout << "#" << aSize << ":\t";
				std::cout << "Array size\t";
				std::cout << "Times\t";
				std::cout << "Average time\t";
				std::cout << "Iterations" << std::endl;
			}	
			
			std::cout << i+1 << ":";

			long int average = *(sum_times+i) / time;	
			long int average_ite = *(iterations+i) / time;

			std::cout << std::fixed;
			std::cout << "\e[1;96m\t" << std::left << std::setfill(' ') << std::setw(12);
			std::cout << array_size;
			std::cout << "\t" << time << "\t" << std::dec;
			std::cout << std::setprecision(10) << average/(long double)1000000000;
			std::cout << "s" << "\t" << average_ite << "\n\e[0;0m";
		}
}
