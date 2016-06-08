/* 
 * File:   main.cpp
 * Author: vtv13qau
 *
 * Created on 05 February 2015, 13:03
 */

#include <cstdlib>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    FILE *file = fopen("dataset1.txt","r");
    if (file == NULL) {
        printf("Error: unable to open ‘albums.txt’ in mode ’r’\n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

