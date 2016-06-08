
#ifndef HISTOGRAM_H
#define	HISTOGRAM_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include "DataArray.h"
 typedef struct Histogram{
        
        int* values;
        int* occurrences;
        int noValues;
    }   Histogram;
 Histogram getHistogram(DataArray*);



#ifdef	__cplusplus
}
#endif

#endif	/* HISTOGRAM_H */

