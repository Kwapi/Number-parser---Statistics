#include <ctype.h>
#include "io.h"
#include <stdio.h>
#include <stdlib.h>



//returns the struct containing size of the array
//and the array of data itself
DataArray readFile(FILE *file){
    
    int size;
       
    //get the size of the data(located in the first line)
    fscanf(file,"%d",&size);
    
    //allocate the memory of length size
    int *data = (int*)malloc(size*sizeof(int));
    
    //get the integers from the file and put them into an array
    int i = 0;
    for(i ; i<size; i++){
        int temp;
        fscanf(file,"%d",&temp);
        data[i] = temp;
    }
    
    
    DataArray dArr;
    dArr.data = data;
    dArr.size = size;
    return dArr;
     
    
}

//opens returns the file specified by the filename
FILE* openFile(char *filename){
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: unable to open %s\n", filename);
        exit(EXIT_FAILURE);
    }

}

//redirects the output stream to a file specified by the filename
//returns the file
FILE* writeToFile(char *filename){
	FILE *file = fopen(filename, "w");
	if (file == NULL) {
		printf("Error: unable to open and write to %s\n", filename);
		exit(EXIT_FAILURE);
		}

	return file;
}
//prints the mean
void printMean(float mean, FILE* file){
	fprintf(file,"mean:\t%4.6f\n", mean);
	fflush(file);

}

//prints the median
void printMedian(float median, FILE* file){
	fprintf(file,"median:\t%4.6f\n", median);
	fflush(file);
	
}

//prints the mode (multiple modes supported)
void printMode(DataArray *modes, FILE* file){
    int i = 0;
	fprintf(file,"mode:\t");
    int noModes = modes->size;
    for(i; i<noModes;i++){
		fprintf(file,"%d", modes->data[i]);
        if(noModes>1 && i!=noModes-1){
			fprintf(file, ", ");
        }
    }
	fprintf(file, "\n");
	fflush(file);
}

//prints the histogram
void printHistogram(Histogram *histogram, FILE* file){
    int i = 0;
    int k = 0;
    
	fprintf(file, "\nHistogram:\n\n");
    for (i; i<histogram->noValues; i++){
		fprintf(file, "%-3d: \t", histogram->values[i]);
        for (k; k <(histogram->occurrences[i]); k++){
			fprintf(file, "*");
        }
		fprintf(file, "\n");
        k=0;
    }
	fflush(file);
}
//prints the standard deviation
void printStdDeviation(float stdDeviation, FILE* file){
	fprintf(file, "Stdev:\t%4.6f\n", stdDeviation);
	fflush(file);
}
//prints the Header ("Statistical Report")
void printHeader(FILE* file){
	fprintf(file, "Statistical Report");
	fprintf(file, "\n==================\n\n");
	fflush(file);
}
