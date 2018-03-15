#include "binary.h"

long int *i_binary( long int *first, long int *last, long int value, long int *counter )
{
	long int *last_backup = last;
	// if first == last and the program doesn't stop, it will loop itself forever
	while(first != last){
		*counter+=1;
		long int *middle = first + (last - first)/(long int)2;
		if(*middle == value){
			// if value *is* middle
			return middle;
		} else {
			if(*middle > value){
				// if the value is in smaller than middle
				last = middle;
			}else{
				// if the value is bigger than middle
				first = middle + 1;
			}	
		}		
	}	
	*counter+=1;
	return last_backup;
}

long int *r_binary( long int *first, long int *last, long int value, long int *counter )
{
	*counter+=1;
	long int *last_backup = last;
	long int *middle = first + (last - first)/(long int)2;	
	
	if(*middle == value){
	// if value *is* middle
		return middle;
	} else {
		if(*middle > value){
		// if the value is in smaller than middle
	    	last = middle;
	    }else{
		 // if the value is bigger than middle
		    first = middle + 1;
			// sem os *
			return r_binary( first, last, value, counter );
		}
	}
	return last_backup;
}	
	
