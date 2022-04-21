#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int search(vector<string> words, string word, int first, int last){
    if(first>last){
        return -1;
    }
    int mid = (last + first)/2;
    if(words[mid].empty()){
        int left = mid  -1;
        int right =mid+1;
        while(true){
            if(left<first && right>last){
                return -1;
            }
            else if(left>=first  && !words[left].empty()){
                mid=left;
                break;
            }
            else if(right<=last && !words[right].empty()){
                mid=right;
                break;
            }
            right++;
            left--;
        }
    }
    if(word==words[mid]){
        return mid;
    }
    else if(word<words[mid]){
        return search(words,word,first,mid-1);
    }
    else{
        return  search(words,word,mid+1,last);
    }
}

int search(vector<string> words, string word){
    if(words.empty() || word==""){
        return -1;
    }
    return search(words,word,0,words.size()-1);
}

int main(){
    vector<string> words;
    words.push_back("at");
    words.push_back("");
    words.push_back("");
    words.push_back("");
    words.push_back("ball");
    words.push_back("");
    words.push_back("");
    words.push_back("car");
    words.push_back("");
    words.push_back("");
    words.push_back("dad");
    words.push_back("");
    words.push_back("");
    string word="dad";
    cout<< "words:"<<endl;
    for(auto w : words){
        cout<<w<<", ";
    }
    cout<<endl;
    cout<< "search for "<<word<<": "<<search(words,word)<<endl;
    return 0;
}