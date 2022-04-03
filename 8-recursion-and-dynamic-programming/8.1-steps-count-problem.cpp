#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int countStepsHelper(int stairs, vector<int> memo){
    if(stairs<0) return 0;
    if(stairs==0) return 1;
    else if(memo[stairs]==0){
        memo[stairs]=countStepsHelper(stairs-1, memo) + countStepsHelper(stairs-2, memo) + countStepsHelper(stairs-3, memo);
    }
    return memo[stairs];
}
int countSteps(int stairs){
    vector<int> memo(stairs);
    return countStepsHelper(stairs, memo);
}

int main(){
    int n = 17;
    cout<<"Count steps for " << n << " stairs:"<< countSteps(n) <<endl;
    return 0; 
}