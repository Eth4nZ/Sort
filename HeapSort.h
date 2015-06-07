#ifndef _HEAPSORT_H_
#define _HEAPSORT_H_
#include "MaxHeap.h"


template <class Record>
void HeapSort(Record Array[], int cur, int cap){
    MaxHeap<Record> mh = MaxHeap<Record>(Array, cur, cap);
    for(int i = 0; i < cur-1; i++)
        mh.RemoveMax();
}

#endif
