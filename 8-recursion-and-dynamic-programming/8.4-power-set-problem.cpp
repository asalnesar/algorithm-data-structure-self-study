#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <bitset>


using namespace std;

string getSetFromInt(vector<string> set, int binary){
    auto b = bitset<32>(binary).to_ulong();
    string result;
    result.append("{");
    int index =0;
    while(b!=0){
        cout<<"B"<<b<<endl;
        if(b&1==1){
            result.append(set[index] + ", ");
        }
        index++;
        b>>=1;
    }
    result.append("}");
    return result;
}
vector<string> getSubsets(vector<string> set){
    vector<string> result;
    int max = 1 << set.size();
    for(int i = 0 ; i< max;i++){
        result.push_back(getSetFromInt(set, i));
    }
    return result;
}

int main(){
    vector<string> set;
    set.push_back("a");
    set.push_back("b");
    set.push_back("c");
    set.push_back("d");
    set.push_back("e");

    auto results = getSubsets(set);
    for(auto result : results){
        cout<<result<<endl;
    }
    return 0;
}