#include "binary.h"

int *i_binary(int *first, int *last, int value)
{
	int *primeiro = first, *ultimo = last;

	if(value >= *first and value < *last){
		// se o valor tiver chances de estar dentro do vetor...		
		while(true){
			// printar o array
			//std::cout << "[ ";
			//std::copy(first, last, std::ostream_iterator<int>(std::cout, " "));
			//std::cout << "]\n";
			// fim do print do array

			int *meio = first + (last - first)/2;
			//std::cout << "O meio é: " << *meio << std::endl;
			if(*meio == value){
				return meio;
			} else {
				if(*meio > value){
					// se estiver na primeira metade
					last = meio;
				}else{
					// se estiver na segunda metade
					first = meio+1;
				}	
			}		
		}	
	}
	return ultimo;
}	
