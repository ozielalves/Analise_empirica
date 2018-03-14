#include "sequential.h"

long int *ssearch( long int *first, long int *last, long int value, long int *counter)
{
	for( long int *i = first; i < last; i++ )
	{
		*counter += 1;
		if ( *i == value )
			return i;
	}
	return last; // STUB
}
