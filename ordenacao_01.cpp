#include <iomanip>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cstdint>
#include <cstring>

using namespace std;

void Split (int b[],int iBegin,int iEnd,int a[] );
void Merge(int a[],int iBegin,int iMiddle, int iEnd,int b[]);
void CopyArray(int A[],int iBegin,int iEnd, int B[]);
void QuickSort(int A[], int lo, int hi);
int Part(int A[], int lo, int hi);
void maxheap(int a[] , int i, int n);
void buildheap(int a[],int n);
void HeapSort(int a[],int n);

int main( int argc, char* argv[] )
  {
    int i,j;
    int n, temp;
    std::cin >> n;
    int a[n];
    for(i=0;i<n;i++){
        std::cin >>a[i];
    }

    switch (atoi(argv[1])){
        case 1:
        //selection sort
        {
        for (j = 0; j < n-1; j++)
            {
            int iMin = j;
            for (i = j+1; i < n; i++) {
                if (a[i] < a[iMin]) {
                    iMin = i;
                }
            }
            if(iMin != j)
                {
                temp = a[j];
                a[j] = a[iMin];
                a[iMin] = temp;
            }
        }
        break;
        }
        case 2:
            //insertion sort

        {
        for(i=1;i<n-1;i++){
            j = i;
            while((j>0) &&(a[j-1]>a[j])){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                j = j-1;
            }
        }
        break;
        }
        case 3:
            //MergeSort
            {
            int b[n];
            CopyArray(a,0,n,b);
            Split(b,0,n,a);

            break;
            }
        case 4:
            //QuickSort
            QuickSort(a,0,n);

        break;

        case 5:
            //HeapSort
            HeapSort(a,n);

        break;


   }
   for(i=0;i<n;i++){
        std::cout << a[i] << endl;
    }


  }

  void Split (int b[],int iBegin,int iEnd,int a[] ){
        int iMiddle;
    if(iEnd - iBegin < 2)
        return;

    iMiddle = (iEnd + iBegin) / 2;
    Split(a, iBegin,  iMiddle, b);
    Split(a, iMiddle,    iEnd, b);
    Merge(b, iBegin, iMiddle, iEnd, a);

  }

  void Merge(int a[],int iBegin,int iMiddle, int iEnd,int b[]){
        int i = iBegin;
        int j = iMiddle;
        for (int k = iBegin; k < iEnd; k++) {
        if (i < iMiddle && (j >= iEnd || a[i] <= a[j])) {
            b[k] = a[i];
            i = i + 1;
        } else {
            b[k] = a[j];
            j = j + 1;
        }
    }
  }

  void CopyArray(int A[],int iBegin,int iEnd, int B[])
{

    for(int k = iBegin; k < iEnd; k++)
        B[k] = A[k];
}

    void QuickSort(int A[], int lo, int hi){
        if(lo<hi){
            int p = Part(A,lo,hi);
            QuickSort(A,lo,p-1);
            QuickSort(A,p+1,hi);
        }
    }

    int Part(int A[], int lo, int hi){
        int pivo = A[hi];
        int pos = hi;
        int temp;
        hi = hi - 1;
        while(lo<=hi){
            while(A[lo]< pivo)
                lo++;
            while(A[hi]>pivo)
                hi--;
            if(lo>=hi)
                break;
            else{
                temp = A[hi];
                A[hi] = A[lo];
                A[lo] = temp;
            }
        }
        temp = A[lo];
        A[lo] = pivo;
        A[pos] = temp;
        return lo;
    }

    void maxheap(int a[], int i, int n){
        int left = 2*i;
        int right = 2*i+1;
        int largest;
        if(left <= n && a[left] > a[i]){
                largest = left;
        }
        else {
            largest = i;
        }
        if(right <= n && a[right] > a[largest])
            { largest = right;
        } if(largest != i){
            int temp = a[i];
            a[i] = a[largest];
            a[largest] = temp;
            maxheap(a, largest,n);
            }
}

    void buildheap(int a[],int n){

        for(int i = n/2; i >= 0; i--){
                maxheap(a,i,n);
        }
    }

    void HeapSort(int a[],int n){
         buildheap(a,n);
         int temp;
        for(int i = n; i>0; i--){
            temp = a[0];
            a[0] = a[i];
            a[i] = temp;
            n = n-1;
            maxheap(a, 0,n);
        }
        }

