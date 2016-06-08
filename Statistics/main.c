
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include "io.h"
#include "statistics.h"

/*
 * Opens the file and prints mean, median, mode, standard deviation and histogram based on the data
 */
int main(int argc, char** argv) {
    FILE* file = openFile("dataset2.txt");
    
    DataArray dArr = readFile(file);
    DataArray mode = getMode(&dArr);
    Histogram histogram = getHistogram(&dArr);
    
	FILE* txtOutput = writeToFile("report.txt");

	printHeader(txtOutput);
    printMean(getMean(&dArr), txtOutput);
	printMode(&mode, txtOutput);
	printMedian(getMedian(&dArr), txtOutput);
		printStdDeviation(getStdDeviation(&dArr), txtOutput);
	printHistogram(&histogram, txtOutput);
     
	fclose(txtOutput);
	return (EXIT_SUCCESS);
}


