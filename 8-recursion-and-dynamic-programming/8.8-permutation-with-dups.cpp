#include <iostream>
#include <unordered_set>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

using  namespace std;

unordered_map<char,int> buildFreqTable(string str){
    unordered_map<char,int> map;
    for(char c : str){
        if(map.find(c)==map.end()){
            map[c]=0;
        }
        map[c]=map[c]+1;
    }
    return map;
}
vector<string> printPerms(unordered_map<char,int> map, string prefix, int remaining){
    vector<string> result;
    if(remaining == 0){
        result.push_back(prefix);
        return result;
    }
    for(auto c : map){
        int count = c.second;
        if(count>0){
            map[c.first]=count-1;
            auto someResults = printPerms(map, prefix + c.first, remaining -1);
            result.insert(result.end(), someResults.begin(), someResults.end());
            map[c.first]=count;
        }
    }
    return result;
}
vector<string> getPermutation(string str){
    vector<string> result;
    unordered_map<char, int> map = buildFreqTable(str);
    result = printPerms(map, "", str.length());
    return result;
}

int main(){
    string str = "abbc";
    auto results = getPermutation(str);
    for(auto res: results){
        cout << res << endl;
    }
    return 0;
}