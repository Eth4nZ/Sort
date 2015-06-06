#include "QuickSort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){
    clock_t begin, end;
    int i,n;
    begin = clock();
    srand(time(0));

    cout << "please input the length:";
    cin >> n;

    int *a = new int[n];
    for(i = 0; i < n; i++)
        a[i] = rand();          //generate random number



    //QuickSort(a, 0, n-1);

    for(i = 0; i < n; i++)
        cout << a[i] << " ";
    cout <<endl;

    end = clock();

    cout << end-begin << "ms" << endl;
}
