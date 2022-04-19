#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

void printArray(int a[]){
    for(int i=0;i<11;i++){
        cout<<a[i]<<" ";
    }
    cout << endl;
}

void mergeSorted(int a[], int b[], int countA, int countB){
    int indexMerged = countA+countB-1;
    int indexA = countA-1;
    int indexB  = countB-1;
    while(indexB>=0){
        if(indexA>=0 && a[indexA]>b[indexB]){
            a[indexMerged]=a[indexA];
            indexA--;
        }
        else{
            a[indexMerged]=b[indexB];
            indexB--;
        }
        indexMerged--;
    }
    printArray(a);
}

int main(){
    int a[] = {2,5,7,11,0,0,0,0,0,0,0};
    int b[]={1,4,5,6,8,9,13};
    mergeSorted(a,b,4,7);
    return 0;
}