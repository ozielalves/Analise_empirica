#include "util.h"

void print_array(int *first, int *last)
{
	std::cout << "[ ";
	std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

void print_larray(long int *first, long int *last)
{
	std::cout << "[ ";
	std::copy(first, last, std::ostream_iterator<long int>(std::cout, " "));
	std::cout << "]" << std::endl;
}

long int *criarVetor(int n)
{
	long int *vetor = (long int *) calloc (n, sizeof(long int));
	for(int i = 0; i < n; i++)
	{
		std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
		vetor[i] = random() % 100;		
	}
	return vetor;
}
