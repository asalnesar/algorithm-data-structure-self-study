#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using  namespace std;

vector<string> getPermutations(string str, int index){
    vector<string> results;
    if(index == str.length()-1){
        string result;
        result.push_back(str.at(index));
        results.push_back(result);
        return results;
    }
    vector<string> someResults = getPermutations(str, index + 1);
    for(string res : someResults){
        for(int i=0; i<=res.length();i++){
            string tmp = res;
            tmp.insert(i,1, str.at(index));
            results.push_back(tmp);
        }
    }
    return results;
}

int main(){
    string str = "abcd";
    auto results = getPermutations(str, 0);
    for(auto res: results){
        cout << res << endl;
    }
    return 0;
}