/* 
 * File:   statistics.h
 * Author: vtv13qau
 *
 * Created on 05 February 2015, 13:05
 */

#ifndef STATISTICS_H
#define	STATISTICS_H

#ifdef	__cplusplus
extern "C" {
#endif
#include "DataArray.h"
   
    void sort(DataArray*);
    int comp(const void*, const void*);
    float getMean(DataArray*);
    int getMedian(DataArray*);
    DataArray getMode(DataArray*);
    float getStdDeviation(DataArray*);
    
    
    
    

#ifdef	__cplusplus
}
#endif

#endif	/* STATISTICS_H */

