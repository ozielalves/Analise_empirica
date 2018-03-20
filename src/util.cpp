#include "util.h"
#include <iostream>
#include <iterator>

long int min(long int x, long int y) { 
	return (x <= y) ? x : y; 
}

long int *makeFib(long int size) {
	long int *fib_seq = new long int[size];	
	for( int i = 0; i < size; i++){
		if(i == 0) fib_seq[i] = 0;
		if(i == 1) fib_seq[i] = 1;
		else{
			fib_seq[i] = fib_seq[i-1] + fib_seq[i-2];	
		}
		std::cout << fib_seq[i] << " ";
	}
	std::cout << std::endl;

}


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

void printResults(int aSize, int array_size, long int time, const int n_functions, long int *sum_times, long int *iterations ){
	// A print for-loop to show the results (time, iterations..)
		for(int i = 0; i < n_functions; i++){
			// Just a simple divisor to make things pretty
			if(!i) {
				bp();
				std::cout << std::setw(3) << std::right << "\e[34m#" << aSize << "\e[0m\t"; // 3
				std::cout << std::setw(10) << std::left << "Array size\t"; // 10
				std::cout << std::setw(5) << std::left << "Times\t"; // 5
				std::cout << std::setw(13) << std::left << "Average time\t"; // 12
				std::cout << std::setw(10) << std::left << "Iterations" << std::endl;
				bp();
			}	
			
			std::cout << "" << "~" << std::right << std::setw(2) << std::setfill(' ') << i+1 << ":";

			long int average = *(sum_times+i) / time;	
			long int average_ite = *(iterations+i) / time;

			std::cout << std::fixed << "\e[1;96m\t"; // turn 'bold' and 'cyan' ascii options on
			std::cout << std::left << std::setfill(' ') << std::setw(12); // defines the align and fill

			std::cout << array_size;
			std::cout << "\t" << time << "\t";
			std::cout << std::setprecision(10) << average/(long double)1000000000;
			std::cout << "s" << "\t";
			std::cout << average_ite;

			std::cout << "\n\e[0;0m"; // set bold and cyan to normal again
		}
}

void generateResults(int i, std::ofstream &file, int aSize, int array_size, long int time, const int n_functions, long int *sum_times, long int *iterations){
	long int average = *(sum_times + i) / time;
	long int average_ite = *(iterations + i) / time;
	file << array_size << " " << time << " " << std::fixed << std::setprecision(10) <<average/(long double)1000000000 << " " << average_ite << std::endl;
	//file << array_size << " " << std::fixed << std::setprecision(10) << average/(long double)1000000000 << std::endl;
}
