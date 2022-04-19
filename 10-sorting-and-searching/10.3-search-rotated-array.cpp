#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>

using namespace std;

int search(vector<int> a, int left, int right, int target){
    if(left>right){
        return -1;
    }
    int middle = (left + right)/2;
    if(target==a[middle]) return middle;
    if(a[middle]<a[right])//right is ordered
    {
        if(a[middle]<target && target<=a[right]){
            return search(a, middle+1, right,  target);
        }
        else{
            return search(a, left, middle-1,  target);
        }
    }
    else if(a[left]<a[middle])//left is ordered
    {
        if(a[left]<=target && target < a[middle]){
            return search(a,left,middle-1,target);
        }
        else{
            return search(a,middle+1,right,target);
        }
    }
    else{
        int loc=-1;
        if(a[left]==a[middle]){
            loc = search(a, middle+1,right,target);
        }
        if(loc==-1 && a[middle]==a[right]){
            loc = search(a,left,middle-1,target);
        }
        return loc;
    }
}

int search(vector<int> a, int target){
    return search(a, 0 , a.size()-1, target);
}

int main(){
    vector<int> a;
    a.push_back(15);
    a.push_back(16);
    a.push_back(19);
    a.push_back(20);
    a.push_back(25);
    a.push_back(1);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(7);
    a.push_back(10);
    a.push_back(14);

    int target = 5;
    cout<< "Search array for "<<target << ": "<<endl;
    for(auto num : a){
        cout<<num<<" ";
    }
    cout<<endl;
    cout <<"result index: " << search(a,target)<<endl;
}