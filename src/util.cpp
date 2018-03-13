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

int checkNumber(long int *first, long int *last, long int number)
{
	int tripped = 0;
	for(long int *i = first; i < last; i++){
		if(*i == number) tripped = 1;	
	}
	return tripped;
}

long int *criarVetor(int n)
{
	long int *vetor = (long int *) calloc (n, sizeof(long int));
	for(int i = 0; i < n;)
	{
		std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
		long int pseudo_random = random() % 100;		
		int tripped = checkNumber(vetor, vetor+i, pseudo_random);	
		if(!tripped) vetor[i++] = pseudo_random;
	}
	return vetor;
}
