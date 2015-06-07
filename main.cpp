#include <iostream>
#include <ctime>
#include <cstdlib>
#include "QuickSort.h"
#include "HeapSort.h"

using namespace std;

int main(){
    clock_t begin, end;
    int i,n;
    srand(time(0));

    //cout << "please input the length:";
    //cin >> n;
    n = 10;
    int *a = new int[n];
    for(i = 0; i < n; i++)
        a[i] = rand()%100;          //generate random number

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    begin = clock();

    //QuickSort(a, 0, n-1);
    HeapSort(a, n, n);

    end = clock();

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;


    cout << end-begin << "ms" << endl;
}
