#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <vector>

using namespace std;

bool isUnique(string str)
{
    if(str.length() > 128) return false;

    bool charSet[128] = {0};
    for(int i=0 ; i< str.length() ; i++)
    {
        char curChar = str.at(i);
        if(charSet[curChar]) return false;
        charSet[curChar] = true;
    }
    return true;
}

void sortString(string &str)
{
    sort(str.begin(), str.end());
}

bool checkPermutation(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;

    //we sort the strings
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    return str1 == str2;
}

bool checkPermutation2(string str1, string str2)
{
    if(str1.length() != str2.length()) return false;

    int letters[128] = {0};

    for(int i= 0 ; i < str1.length(); i++)
    {
        letters[str1.at(i)]++;
    }
    for(int i= 0 ; i < str2.length(); i++)
    {
        letters[str2.at(i)]--;
        if(letters[str2.at(i)] < 0) return false;
    }
    return true;
}

int countSpace(string str, int start, int end, int target)
{
    int count = 0;
    for(int i= start ; i< end; i++){
        if(str.at(i) == target)
        {
            count++;
        }
    }
    return count;
}

string urlify(string str, int trueLength)
{
    int numberOfSpaces =  countSpace(str, 0, trueLength, ' ');
    int newIndex = trueLength - 1 + (numberOfSpaces * 2);
    cout <<"number of spaces: " << numberOfSpaces << endl;
    cout <<"new index: "<<newIndex <<endl;
    if(newIndex + 1 < str.length()) {
        str.at(newIndex+1)='\0';
    }
    for(int i = trueLength - 1; i >=0 ; i--)
    {
        if(str.at(i) == ' '){
            str.at(newIndex) = '0';
            str.at(newIndex - 1) = '2';
            str.at(newIndex  - 2) = '%';
            newIndex -= 3;
        }
        else{
            str.at(newIndex) = str.at(i);
            newIndex--;
        }
    }
    return str;
}

bool isPalindromePermutation(string str)
{
    int letters['z'-'a' + 1] = {0};
    int countOdd = 0;
    for(int i=0;i<str.length(); i++)
    {
        int currenctChar = str.at(i);
        if(currenctChar >= 'a' && currenctChar <= 'z')
        {
            letters[currenctChar-'a']++;
            if(letters[currenctChar-'a']%2==1)
            {
                countOdd++;
            } else {
                countOdd--;
            }
        }
        else if(currenctChar >= 'A' && currenctChar <'Z')
        {

            letters[currenctChar-'A']++;
            if(letters[currenctChar-'A']%2==1)
            {
                countOdd++;
            } else {
                countOdd--;
            }
        }
    }
    cout << letters << endl;
    cout<<"Odd count: " << countOdd;
    return countOdd <= 1;
}

bool oneEditAway(string first, string second)
{
    if(abs(int(first.length() - second.length())) > 1)
        return false;
    int index1=0;
    int index2=0;
    bool foundDifference = false;

    string str1 = first.length() > second.length() ? first : second;
    string str2 = first.length() > second.length() ? second : first;
    cout<<str1 <<" <---str1" <<endl;
    cout<<str2 <<" <---str2" <<endl;
    while(index1<str1.length() && index2<str2.length()){
        if(str1.at(index1) != str2.at(index2)){
            if(foundDifference){
                return false;
            }
            foundDifference = true;
            if(str1.length() == str2.length()){
                index2++;
            }
        } else {
            index2++;
        }
        index1++;
    }
    return true;
}

string compress(string str)
{
    stringstream compressedStream;
    int consecutiveCount = 0;
    for(int i =0 ; i< str.length(); i++){
        consecutiveCount++;
        if(i+1>=str.length() || str.at(i)!=str.at(i+1)){
            compressedStream << str.at(i) << consecutiveCount;
            consecutiveCount=0;
        }
    }
    string compressed = compressedStream.str();
    return compressed.length() > str.length() ? str : compressed;
    
}

bool rotateMatrix(vector<vector<int>> matrix)
{
    if(matrix.size() ==  0 || matrix.size() != matrix[0].size()) return false;
    
}

void  testIsUniques()
{
    cout << "Check if a string has unique characters." << endl;
    cout << "Put in the string:";
    string str;
    cin >> str;
    bool result = isUnique(str);
    cout << "for string " << str << " result is " << result << endl;
}

void  testPermutation()
{
    cout << "Check permutation of two strings:" << endl;
    string str1, str2;
    cout << "Put in the first string:";
    cin >> str1;
    cout << "Put in the second string:";
    cin >> str2;
    bool result = checkPermutation2(str1, str2);
    cout << "for string " << str1 << " and string " << str2 << " result is " << result << endl;
}

void testUrlify()
{
    cout << urlify("asal nesar nobari     ", 17) << endl;
}

void testPalindromePermutation()
{
    bool result = isPalindromePermutation("Tact -+)/Coa");
    cout << "Is string Palindrome permutation: " << result << endl;
}

void testOneEditAway()
{
    cout << "One edit away:"<<endl;
    cout<<"Put in first string:"<<endl;
    string first;
    cin>>first;
    cout<<"Put in second string:"<<endl;
    string second;
    cin>>second;
    bool result = oneEditAway(first,second);
    cout <<"Words "<<first<<" and " << second<< " are one edit away? result: " <<result<<endl;
}

void testCompress(){
    cout <<"Test compressing:"<<endl;
    cout<<"Put in string:"<<endl;
    string str;
    cin>>str;
    string result = compress(str);
    cout<<"String " <<str<< " was compressed: " << result <<endl;
}


int main()
{
    testCompress();
    return 0;
}

