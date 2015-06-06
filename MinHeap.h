#ifndef _MINHEAP_H_
#define _MINHEAP_H_
#include <iostream>

template <class T>
class MinHeap{
private:
    T *heapArray;
    int heapSize;
    int capacity;

    void percUp(int curIndex);
    void percDown(int curIndex);
    void swap(int pos_x, int pos_y);
    void BuildHeap();

public:
    MinHeap(int);
    virtual ~MinHeap(){delete []heapArray;};
    bool isEmpty();
    bool isLeaf(int pos) const;
    int LeftChild(int pos) const;
    int RightChild(int pos) const;
    int Parent(int pos) const;
    bool Remove(int pos, T&node);
    bool Insert(const T& newNode);
    T& RemoveMin();

    int getHeapSize(){
        return heapSize;
    }
};

template <class T>
MinHeap<T>::MinHeap(const int n){
    if(n <= 0)
        return;
    heapSize = 0;
    capacity = n;
    heapArray = new T[capacity];
    for(int i = 0; i < capacity; i++)
        BuildHeap();
}

template <class T>
bool MinHeap<T>::isEmpty(){
    return (heapSize == 0);
}

template <class T>
bool MinHeap<T>::isLeaf(int pos) const{
    return (pos >= heapSize/2) && (pos < heapSize);
}

template <class T>
void MinHeap<T>::BuildHeap(){
    for(int i = heapSize/2-1; i >= 0; i--)
        percDown(i);
}

template <class T>
int MinHeap<T>::LeftChild(int pos) const{
    return 2*pos+1;
}

template <class T>
int MinHeap<T>::RightChild(int pos) const{
    return 2*pos+2;
}

template <class T>
int MinHeap<T>::Parent(int pos) const{
    return (pos-1)/2;
}

template <class T>
void MinHeap<T>::swap(int pos_x, int pos_y){
    int temp = pos_x;
    pos_x = pos_y;
    pos_y = temp;
}

template <class T>
bool MinHeap<T>::Insert(const T& newNode){
    if(heapSize == capacity)
        return false;
    heapArray[heapSize] = newNode;
    percUp(heapSize);
    heapSize++;
    return true;
}

template <class T>
T& MinHeap<T>::RemoveMin(){
    if(heapSize == 0){
        //cerr << "Cannot Delete";
        //exit(1);
    }
    else{
        swap(0, --capacity);
        if(heapSize > 1)
            percDown(0);
        return heapArray[heapSize];
    }
}

template <class T>
bool MinHeap<T>::Remove(int pos, T& node){
}

template <class T>
void MinHeap<T>::percUp(int curIndex){
    int tempPos = curIndex;
    T temp = heapArray[tempPos];
    while((tempPos > 0) && (heapArray[Parent(tempPos)] > temp)){
        heapArray[tempPos] = heapArray[Parent(tempPos)];
        tempPos = Parent(tempPos);
    }
    heapArray[tempPos] = temp;
}

template <class T>
void MinHeap<T>::percDown(int curIndex){
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
