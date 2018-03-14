#include "sequential.h"

long int *ssearch( long int *first, long int *last, long int value )
{
	for( long int *i = first; i < last; i++ ){
		if ( *i == value )
		{
			std::cout << "Elemento " << value << " encontrado, posição " << std::hex << i << std::endl;
			return i;
		}
	}
	std::cout << "Não conseguimos encontrar o elemento!" << std::endl;
	return last; // STUB
}
