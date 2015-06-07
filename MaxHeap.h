#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_
#include <iostream>

template <class T>
class MaxHeap{
private:
    T *heapArray;
    int heapSize;
    int capacity;

    void percUp(int curIndex);
    void percDown(int curIndex);
    void BuildHeap();

public:
    MaxHeap(int);
    MaxHeap(T[], int, int);
    virtual ~MaxHeap(){delete []heapArray;};
    int LeftChild(int pos) const;
    int RightChild(int pos) const;
    int Parent(int pos) const;
    void RemoveMax();

};


template <class T>
MaxHeap<T>::MaxHeap(T Array[], int cur, int cap){
    if(cur <= 0 || cap <= 0)
        return;
    heapSize = cur;
    capacity = cap;
    heapArray = Array;
    //BuildHeap();
}

template <class T>
void MaxHeap<T>::BuildHeap(){
    for(int i = heapSize/2-1; i >= 0; i--)
        percDown(i);
}

template <class T>
int MaxHeap<T>::LeftChild(int pos) const{
    return 2*pos+1;
}

template <class T>
int MaxHeap<T>::RightChild(int pos) const{
    return 2*pos+2;
}

template <class T>
int MaxHeap<T>::Parent(int pos) const{
    return (pos-1)/2;
}

template <class T>
void MaxHeap<T>::RemoveMax(){
    /*if(heapSize == 0){
        cerr << "Cannot Delete";
        exit(1);
    }
    else{*/
        T temp = heapArray[0];
        heapArray[0] = heapArray[capacity];
        heapArray[capacity] = temp;
        capacity--;

        if(heapSize > 1)
            percDown(0);
        return heapArray[heapSize];
    //}
}


template <class T>
void MaxHeap<T>::percUp(int curIndex){
    int tempPos = curIndex;
    T temp = heapArray[tempPos];
    while((tempPos > 0) && (heapArray[Parent(tempPos)] > temp)){
        heapArray[tempPos] = heapArray[Parent(tempPos)];
        tempPos = Parent(tempPos);
    }
    heapArray[tempPos] = temp;
}

template <class T>
void MaxHeap<T>::percDown(int curIndex){
    int i = curIndex;
    int j = LeftChild(i);
    T temp = heapArray[i];
    while(j < heapSize){
        if((j < heapSize-1) && ( heapArray[j] > heapArray[j+1]))
            j++;
        if(temp > heapArray[j]){
            heapArray[i] = heapArray[j];
            i = j;
            j = LeftChild(j);
        }
        else
            break;
    }
    heapArray[i] = temp;
}


#endif
