#include "binary.h"

long int *i_binary( long int *first, long int *last, long int value, long int *counter )
{
	long int *last_backup = last;
	// if first == last and the program doesn't stop, it will loop itself forever
	while(first != last)
	{
		*counter+=1;
		long int *middle = first + (last - first)/(long int)2;
		if(*middle == value)
		{
			*counter += 1;
			// if value *is* middle
			return middle;
		} 
		else
	       	{
			if(*middle > value)
			{
				*counter += 2;
				// if the value is in smaller than middle
				last = middle;
			}
			else
			{
				*counter += 2; 
				// if the value is bigger than middle
				first = middle + 1;
			}	
		}		
	}	
	// *counter+=1;
	return last_backup;
}

long int *r_binary( long int *first, long int *last, long int value, long int *counter )
{
	if(first == last){
		*counter += 1;
		return last; 
	}


	long int *last_backup = last; // todo
	long int *middle = first + (last - first)/(long int)2;	
	
	if(*middle == value){
		*counter += 1;
		return middle;
	} else {
		if(*middle > value){
			*counter += 2;
			// if the value is in smaller than middle
	    	last = middle;
			return r_binary( first, last, value, counter );
	    }else{
			*counter += 2;
			 // if the value is bigger than middle
		    first = middle + 1;
			return r_binary( first, last, value, counter );
		}
	}
	return last_backup;
}	
