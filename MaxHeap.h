#ifndef _MAXHEAP_H_
#define _MAXHEAP_H_

template <class T>
class MaxHeap{
private:
    T *heapArray;
    int heapSize;
    int capacity;

    void percDown(int);
    void BuildHeap();

public:
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
    BuildHeap();
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
    if(heapSize == 0){
        return;
    }
    else{
        T temp = heapArray[0];
        heapArray[0] = heapArray[heapSize-1];
        heapArray[heapSize-1] = temp;
        heapSize--;
        capacity--;

        if(heapSize > 1)
            percDown(0);
    }
}



template <class T>
void MaxHeap<T>::percDown(int curIndex){
    int i = curIndex;
    int j = LeftChild(i);
    T temp = heapArray[i];
    while(j < heapSize){
        if((j < heapSize-1) && ( heapArray[j] < heapArray[j+1]))
            j++;
        if(temp < heapArray[j]){
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
