/* 
 * File:   io.h
 * Author: vtv13qau
 *
 * Created on 05 February 2015, 13:05
 */

#ifndef IO_H
#define	IO_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <stdio.h>
#include "Histogram.h"
#include "DataArray.h"
    
 

DataArray readFile(FILE*);  
FILE* openFile(char*);
FILE* writeToFile(char*);
void printMean(float, FILE*);
void printMode(DataArray*, FILE*);
void printMedian(float, FILE*);
void printStdDeviation(float, FILE*);
void printHistogram(Histogram*);
void printHeader(FILE*);


#ifdef	__cplusplus
}
#endif

#endif	/* IO_H */

