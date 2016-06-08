
#include "Histogram.h"
#include "DataArray.h"

//Returns a Histogram based on the probided DataArray
Histogram getHistogram(DataArray *dArr){
    //sort the list
    sort(dArr);
    //initialise the struct
    Histogram histogram;
    
    int minValue = dArr->data[0];
    int maxValue = dArr->data[(dArr->size)-1];
    
    //allocate the memory to an array containing all the unique values from the data
    int *values = (int*)malloc(dArr->size*sizeof(int)); //TODO: FIX MEMORY LEAK
    
    int prevValue = minValue-1; //set to be a value which is not present in the data    
    
    //indices
    int i = 0;
    int j = 0;
    
    //loop through the data
    for(i;i<dArr->size;i++){
        //get only the unique values from the data and put them into a separate
        //array
        if(dArr->data[i] !=prevValue){
            values[j] = dArr->data[i];
            prevValue = dArr->data[i];
            j++;
        }
    }
    
    //j is equal to the size of the finished array
    int size = j;
    
    //allocate the memory to an array containing the number of 
    //occurrences of the values in the data
    int *occurrences = (int*)malloc(size*sizeof(int));
    
    //reset the indices
    j= 0;
    i=0;
    for (i;i<size;i++){
        occurrences[i] = 0; //initialise the values to 0
        
        while(values[i]==dArr->data[j]){ //count the no of occurrences
            occurrences[i]++;
            j++;
        }
    }
    
    //assign the variables to the struct
    histogram.values = values;
    histogram.noValues = size;
    histogram.occurrences = occurrences;
  
    
    return histogram;
       
}
