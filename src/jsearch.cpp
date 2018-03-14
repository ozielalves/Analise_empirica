#include "jsearch.h"
#include "sequential.h"
#include <cmath>

long int *jsearch( long int *first, long int *last, long int value, long int *counter ) {
// vector size  
   long int n = ( last - first );
   long int m = sqrt(n);
   long int *last_backup;
   last_backup = last;

   for( auto k(1); k*m < n; k++)
   {
	   *counter++;
       if( value == *(first + k*m) )
       {	
		   return (first + k*m);
       }
       if( *(first + k*m) > value )	
	   {
// ponteiros passados - analisar
			auto result = lsearch( (first + (k-1)*m), ((first + k*m)), value);
			if(result != ((first + k*m)))
			{
				 return result;
			}
			else return last;
		}
		if( *(first + k*m) < value )
		{
			//first = (first + k*m);
			continue;
		}																																																																				     }
																																																																						     return last_backup;
	}
}
