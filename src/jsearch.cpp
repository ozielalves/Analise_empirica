#include "jsearch.h"

long int *jsearch( long int *first, long int *last, long int value, long int *counter ) 
{
	// vector size  
	long int n = last - first;
	long int m = sqrt(n);
	long int *last_backup = last;
	
	for( auto k(1); (k * m) < n; k++ )
	{
		*counter++;
		if( value == *(first + k * m) )
			return first + k * m;
		if( *(first + k * m) > value )
		{
			// ponteiros passados - analisar
			auto result = ssearch( (first + (k - 1) * m), ((first + k * m)), value);
		
			if( result != (first + k * m) )
				return result;
			else
				return last;
		}
	}
	return last_backup;
}
