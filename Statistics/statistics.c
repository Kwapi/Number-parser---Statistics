
#include "io.h"
#include "statistics.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h> 

/*
 * Comparator used in the sort() method
 */
int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) return  1;
    if (f < s) return -1;
    return 0;
}
/*
 *  Sorts the data in the  ascending order
 */
void sort(DataArray *dArr) 
{    qsort (dArr->data, dArr->size, sizeof(*(dArr->data)), comp);
}
/*
 *  Returns the mean
 */
float getMean(DataArray *dArr){

    float sum = 0;
    int i = 0;
    for (i; i<dArr->size; i++){
        sum += dArr->data[i];
    }
    
    return sum/dArr->size;
}
/*
 * Returns the median
 */
int getMedian(DataArray *dArr){
    
    //sort the list
    sort(dArr);
    
    //if the size of a list is odd, choose the middle value
    if (dArr->size%2!=0){
        
        return dArr->data[(dArr->size - 1)/2];
    }
    //if the size of a list is even, get the average of the two middle values
    else{
        int value1 = dArr->data[(dArr->size)/2];
        int value2 = dArr->data[(dArr->size)/2 - 1];
               
        return (float)(value1 + value2)/2;
        
    }
    
    
    
    
}

//Returns the mode (DataArray) on the provided DataArray
DataArray getMode(DataArray *dArr){
   
    //sort the list 
    //(might have been sorted earlier but it's better to be on the safe side)
    sort(dArr);
    
    Histogram histogram = getHistogram(dArr);
    
    int currentMax = 0;
    int currentVal = 0;
    
    //indices of the numbers with the max occurrence number
    //(dynamically allocated to the maximum value which is the size of the histogram)
    int *indices = (int*)malloc(histogram.noValues*sizeof(int));
    
    int i = 0;
    int k = 0;
    
    //get the maximum number of occurrences
    for (i; i<histogram.noValues; i++){
        currentVal = histogram.occurrences[i];
        if(currentVal>currentMax){
            currentMax = currentVal;
        }      
    }
   
    //check how many values have that occurrence number
    for (i=0; i<histogram.noValues; i++){
        currentVal = histogram.occurrences[i];
        if (currentMax==currentVal){
            indices[k] = i;
            k++;
        }
    }
    
    
    
    int *results = (int*)malloc(k * sizeof(int));
    
    
    //link the indices to the actual values
    for(i=0; i<k; i++)
    {
        results[i] = histogram.values[indices[i]];
               
    }
    
    DataArray result;
    result.data = results;
    result.size = k;
    
    
    
    
    return result;
    
}

//Returns the value of standard deviation based on the data from the DataArray provided
float getStdDeviation(DataArray *dArr){
    float mean = getMean(dArr);
    float sum = 0;
    int i = 0;
   
    
    for (i; i<(dArr->size);i++){
         sum += pow(((dArr->data[i]) - mean),2) ;
    }
  
    
    
    return (float) sqrt((sum/(dArr->size)));
    
    
}