#include "sequential.h"

int *ssearch( int *first, int *last, int value )
{
	for( int *i = first; i <= last; i++ )
	{
			if ( *i == value )
					return i;
	}
	return last; // STUB
}
