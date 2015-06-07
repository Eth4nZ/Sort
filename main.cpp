#include <iostream>
#include <ctime>
#include <cstdlib>
#include "QuickSort.h"
#include "HeapSort.h"
#include "MergeSort.h"

using namespace std;

int main(){
    clock_t begin, end;
    int i,n;
    srand(time(0));

    cout << "please input the length:";
    cin >> n;
    //n = 100;
    int *a = new int[n];
    int *b = new int[n];
    int *c = new int[n];
    for(i = 0; i < n; i++){
        a[i] = rand()%100;
        b[i] = c[i] = a[i];
    }


    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    begin = clock();            //QuickSort
    QuickSort(a, 0, n-1);
    end = clock();
    cout << "QuickSort:" << end-begin << "ms" << endl;


    //HeapSort(a, n, n);        //HeapSort
    begin = clock();
    MaxHeap<int> mh = MaxHeap<int>(b, n, n);
      for(i = 0; i < n-1; i++)
        mh.RemoveMax();
    end = clock();
    cout << "HeapSort:" << end-begin << "ms" << endl;


    begin = clock();            //MergeSort
    int *d = new int[n];
    MergeSort(c, d, 0, n-1);
    end = clock();
    cout << "MergeSort:" << end-begin << "ms" << endl;


    /*for(i = 0; i < n; i++)    //show result
        cout << a[i] << " ";
    cout << endl;
    */


}



