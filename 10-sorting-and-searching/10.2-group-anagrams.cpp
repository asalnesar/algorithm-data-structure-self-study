#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <map>
#include <stdlib.h>
#include <vector>
#include <list>

using namespace std;

vector<string> groupAnagrams(vector<string> strings){
    vector<string> results;
    map<string, list<string>  > wordMap;
    for(auto str : strings){
        string key = str;
        sort(key.begin(), key.end());
        wordMap[key].push_back(str);
    }
    for(auto words: wordMap){
        results.insert(results.end(),words.second.begin(), words.second.end());
    }
    return results;
}

int main()
{
    // As an example, we can use:
    vector<string> s;
    s.push_back("abcd");
    s.push_back("asleep");
    s.push_back("notananagram");
    s.push_back("silent");
    s.push_back("cdba");
    s.push_back("please");
    s.push_back("dcba");
    s.push_back("listen");
    // print array before
    cout << "Array before: ";
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }

    auto s2 = groupAnagrams(s);

    // print array after
    cout << "\nArray after: ";
    for (int i = 0; i < s2.size(); i++) {
        cout << s2[i] << " ";
    }

    return 0;
}