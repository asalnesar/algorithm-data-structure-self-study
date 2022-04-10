#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <bitset>

using namespace std;

int multiplyHelper(int smaller, int bigger){
    if(smaller==0){
        return 0;
    }
    if(smaller==1){
        return bigger;
    }
    int s = smaller >> 1; //divide by 2
    int half = multiplyHelper(s  , bigger);
    if(smaller%2==0){
        return half+half;
    }
    else{
        return half + half + bigger;
    }
}
int multiply(int a, int b){
    int smaller = a <= b ? a : b;
    int bigger = a<=b ? b : a;
    return multiplyHelper(smaller,bigger);
}

int main(){
    int a = 23;
    int b = 5;
    cout << "multiply" <<a<< "*" <<b<<"=" << multiply(a,b)<<endl;
    return 0;
}