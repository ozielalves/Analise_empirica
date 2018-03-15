#include "util.h"

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
	std::cout << std::setfill('-') << std::setw(50) << "" << std::endl; 
}
