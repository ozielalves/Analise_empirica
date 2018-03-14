#include "sequential.h"

long int *ssearch( long int *first, long int *last, long int value )
{
	for( long int *i = first; i < last; i++ ){
		if ( *i == value )
			return i;
	}
	return last; // STUB
}
