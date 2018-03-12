#include "binary.h"

int *i_binary( int *first, int *last, int value )
{
	int *ultimo = last;
	if(value >= *first and value < *last){
		// se o valor tiver chances de estar dentro do vetor...		
		while(true){
			int *meio = first + (last - first)/2;
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
