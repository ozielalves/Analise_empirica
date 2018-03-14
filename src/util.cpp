#include "util.h"

void pArray(long int *first, long int *last)
{
	std::cout << "[ ";
	std::copy(first, last, std::ostream_iterator<long int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

long int *cArray(int n)
{
	long int *vetor = (long int *) calloc (n, sizeof(long int));
	for(int i = 0, k = 0; i < n;)
	{
		//std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
		//long int pseudo_random = random() % 3 + 1;		
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
