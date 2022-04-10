#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>


using namespace std;
int findMagicIndex(vector<int> arr, int start, int  end){
    if(end<start) return -1;
    int midIndex = (start + end)/2;
    if(arr[midIndex]==midIndex){
        return midIndex;
    }
    else if(arr[midIndex] < midIndex){
        return findMagicIndex(arr, midIndex+1, end);

    }
    else{
        return findMagicIndex(arr, start, midIndex-1);
    }

}
int findMagicIndex(vector<int> arr){
    return findMagicIndex(arr, 0, arr.size()-1);
}
int main(){
    vector<int> arr;
    arr.push_back(-10);
    arr.push_back(-2);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(11);
    arr.push_back(12);
    arr.push_back(14);
    cout<<"array: {";
    for(int a: arr){
        cout<<a <<", ";
    }
    cout<<endl;
    cout <<"Magic index:" << findMagicIndex(arr) <<endl;
    return 0;
}