/* 
 * File:   DataArray.h
 * Author: vtv13qau
 *
 * Created on 12 February 2015, 16:21
 */

#ifndef DATAARRAY_H
#define	DATAARRAY_H

#ifdef	__cplusplus
extern "C" {
#endif

typedef struct DataArray{
    int size;
    int* data;
} DataArray;   



#ifdef	__cplusplus
}
#endif

#endif	/* DATAARRAY_H */

