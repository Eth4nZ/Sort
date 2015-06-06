#ifndef _QUICKSORT_H_
#define _QUICKSORT_H_

template <class Record>
int Partition(Record Array[], int left, int right){
    int l = left;
    int r = right;
    Record TempRecord = Array[r];
    while(l != r){
        while(Array[l] <= TempRecord && l < r)
            l++;
        if(l < r){
            Array[r] = Array[l];
            r--;
        }
        while(Array[r] >= TempRecord && l < r)
            r--;
        if(l < r){
            Array[l] = Array[r];
            l++;
        }
    }
    Array[l] = TempRecord;
    return l;
}

template <class Record>
void QuickSort(Record Array[], int left, int right){
    if(right <= left)
        return;
    int pivot = (left+right)/2; //select pivotValue
    int temp = Array[pivot];    //swap(Array, pivot, right)
    Array[pivot] = Array[right];
    Array[right] = temp;
    pivot = Partition(Array, left, right);
    QuickSort(Array, left, pivot-1);
    QuickSort(Array, pivot+1, right);
}


#endif
