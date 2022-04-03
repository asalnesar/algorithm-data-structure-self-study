#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int countSteps(int stairs){
    if(stairs<0) return 0;
    if(stairs==0) return 1;
    return countSteps(stairs-1) + countSteps(stairs-2) + countSteps(stairs-3);
}

int main(){
    int n = 17;
    cout<<"Count steps for " << n << " stairs:"<< countSteps(n) <<endl;
    return 0; 
}