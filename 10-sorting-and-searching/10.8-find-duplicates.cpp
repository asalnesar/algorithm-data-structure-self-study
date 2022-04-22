#include <cstdint>
#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

void printDuplicates(vector<int> arr){
    bitset<32000> b;
    for(int num : arr){
        if(!b[num]){
            b[num]=1;
        }
        else{
            cout<<num<<", ";
        }
    }
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(7);
    arr.push_back(31);
    arr.push_back(1);
    arr.push_back(12);
    arr.push_back(7);
    arr.push_back(3);
    arr.push_back(20);
    arr.push_back(12);
    printDuplicates(arr);
    return 0;
}